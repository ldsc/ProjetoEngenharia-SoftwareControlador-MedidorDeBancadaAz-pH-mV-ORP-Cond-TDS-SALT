#include "Instrumentor.h"

#include <iostream>


    void Instrumentor::BeginSession(const std::string &name, const std::string &filepath)
    {
        {
			std::lock_guard lock(m_Mutex);
			if (m_CurrentSession)
			{

                std::cout << "Instrumentor::BeginSession(\'" << name <<"\') when session \'{" << m_CurrentSession << "}\' already open." << std::endl;
			}
			m_OutputStream.open(filepath);

			if (m_OutputStream.is_open())
			{
				m_CurrentSession = new InstrumentationSession({name});
				WriteHeader();
			}
			else
			{

                std::cout << "Instrumentor could not open results file \'{" << filepath << "}\'." << std::endl;

			}
		}
    }

    void Instrumentor::EndSession()
    {
		std::lock_guard lock(m_Mutex);
		InternalEndSession();
	}

    void Instrumentor::WriteProfile(const ProfileResult &result)
    {
		std::stringstream json;

		json << std::setprecision(3) << std::fixed;
		json << ",{";
		json << "\"cat\":\"function\",";
		json << "\"dur\":" << (result.ElapsedTime.count()) << ',';
		json << "\"name\":\"" << result.Name << "\",";
		json << "\"ph\":\"X\",";
		json << "\"pid\":0,";
		json << "\"tid\":" << result.ThreadID << ",";
		json << "\"ts\":" << result.Start.count();
		json << "}";

		std::lock_guard lock(m_Mutex);
		if (m_CurrentSession)
		{
			m_OutputStream << json.str();
			m_OutputStream.flush();
		}
	}

    Instrumentor &Instrumentor::Get()
    {
		static Instrumentor instance;
		return instance;
	}

    Instrumentor::Instrumentor() : m_CurrentSession(nullptr)
    {
    }

    Instrumentor::~Instrumentor()
    {
			EndSession();
	}

    void Instrumentor::WriteHeader()
    {
		m_OutputStream << "{\"otherData\": {},\"traceEvents\":[{}";
		m_OutputStream.flush();
	}

    void Instrumentor::WriteFooter()
    {
		m_OutputStream << "]}";
		m_OutputStream.flush();
	}

    void Instrumentor::InternalEndSession()
    {
		if (m_CurrentSession)
		{
			WriteFooter();
			m_OutputStream.close();
			delete m_CurrentSession;
			m_CurrentSession = nullptr;
		}
	}

    InstrumentationTimer::InstrumentationTimer(const char *name) : m_Name(name), m_Stopped(false)
	{
		m_StartTimepoint = std::chrono::steady_clock::now();
	}

    InstrumentationTimer::~InstrumentationTimer()
    {
		if (!m_Stopped)
		    Stop();
	}

    void InstrumentationTimer::Stop()
    {
		auto endTimepoint = std::chrono::steady_clock::now();
		auto highResStart = FloatingPointMicroseconds{ m_StartTimepoint.time_since_epoch() };
		auto elapsedTime = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch() - std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimepoint).time_since_epoch();

		Instrumentor::Get().WriteProfile({ m_Name, highResStart, elapsedTime, std::this_thread::get_id() });

		m_Stopped = true;
	}
