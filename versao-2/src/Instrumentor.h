#ifndef INSTRUMENTOR_H
#define INSTRUMENTOR_H


#include <algorithm>
#include <chrono>
#include <fstream>
#include <iomanip>
#include <string>
#include <thread>
#include <mutex>
#include <sstream>

using FloatingPointMicroseconds = std::chrono::duration<double, std::micro>;

struct ProfileResult
{
    std::string Name;

    FloatingPointMicroseconds Start;
    std::chrono::microseconds ElapsedTime;
    std::thread::id ThreadID;
};

struct InstrumentationSession
{
    std::string Name;
};

class Instrumentor
{
public:
    Instrumentor(const Instrumentor&) = delete;
    Instrumentor(Instrumentor&&) = delete;

    void BeginSession(const std::string& name, const std::string& filepath = "results.json");

    void EndSession();

    void WriteProfile(const ProfileResult& result);

    static Instrumentor& Get();
		
private:
    Instrumentor();

    ~Instrumentor();

    void WriteHeader();
		

    void WriteFooter();

    void InternalEndSession();
		
private:
    std::mutex m_Mutex;
    InstrumentationSession* m_CurrentSession;
    std::ofstream m_OutputStream;
};

class InstrumentationTimer
{
public:
    InstrumentationTimer(const char* name);

    ~InstrumentationTimer();

    void Stop();
		
private:
    const char* m_Name;
    std::chrono::time_point<std::chrono::steady_clock> m_StartTimepoint;
    bool m_Stopped;
	};

namespace InstrumentorUtils {

		template <size_t N>
		struct ChangeResult
		{
			char Data[N];
		};

		template <size_t N, size_t K>
		constexpr auto CleanupOutputString(const char(&expr)[N], const char(&remove)[K])
		{
			ChangeResult<N> result = {};

			size_t srcIndex = 0;
			size_t dstIndex = 0;
			while (srcIndex < N)
			{
				size_t matchIndex = 0;
				while (matchIndex < K - 1 && srcIndex + matchIndex < N - 1 && expr[srcIndex + matchIndex] == remove[matchIndex])
					matchIndex++;
				if (matchIndex == K - 1)
					srcIndex += matchIndex;
				result.Data[dstIndex++] = expr[srcIndex] == '"' ? '\'' : expr[srcIndex];
				srcIndex++;
			}
			return result;
		}
	}

#define STUDY_PROFILE 1
#if STUDY_PROFILE
	
	#if defined(__GNUC__) || (defined(__MWERKS__) && (__MWERKS__ >= 0x3000)) || (defined(__ICC) && (__ICC >= 600)) || defined(__ghs__)
		#define STUDY_FUNC_SIG __PRETTY_FUNCTION__
	#elif defined(__DMC__) && (__DMC__ >= 0x810)
		#define STUDY_FUNC_SIG __PRETTY_FUNCTION__
	#elif (defined(__FUNCSIG__) || (_MSC_VER))
		#define STUDY_FUNC_SIG __FUNCSIG__
	#elif (defined(__INTEL_COMPILER) && (__INTEL_COMPILER >= 600)) || (defined(__IBMCPP__) && (__IBMCPP__ >= 500))
		#define STUDY_FUNC_SIG __FUNCTION__
	#elif defined(__BORLANDC__) && (__BORLANDC__ >= 0x550)
		#define STUDY_FUNC_SIG __FUNC__
	#elif defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901)
		#define STUDY_FUNC_SIG __func__
	#elif defined(__cplusplus) && (__cplusplus >= 201103)
		#define STUDY_FUNC_SIG __func__
	#else
		#define STUDY_FUNC_SIG "STUDY_FUNC_SIG unknown!"
	#endif

    #define STUDY_PROFILE_BEGIN_SESSION(name, filepath) ::Instrumentor::Get().BeginSession(name, filepath)
    #define STUDY_PROFILE_END_SESSION() ::Instrumentor::Get().EndSession()
    #define STUDY_PROFILE_SCOPE_LINE2(name, line) constexpr auto fixedName##line = ::InstrumentorUtils::CleanupOutputString(name, "__cdecl ");\
                                               ::InstrumentationTimer timer##line(fixedName##line.Data)
	#define STUDY_PROFILE_SCOPE_LINE(name, line) STUDY_PROFILE_SCOPE_LINE2(name, line)
	#define STUDY_PROFILE_SCOPE(name) STUDY_PROFILE_SCOPE_LINE(name, __LINE__)
	#define STUDY_PROFILE_FUNCTION() STUDY_PROFILE_SCOPE(STUDY_FUNC_SIG)
#else
	#define STUDY_PROFILE_BEGIN_SESSION(name, filepath)
	#define STUDY_PROFILE_END_SESSION()
	#define STUDY_PROFILE_SCOPE(name)
	#define STUDY_PROFILE_FUNCTION()
#endif

#endif
