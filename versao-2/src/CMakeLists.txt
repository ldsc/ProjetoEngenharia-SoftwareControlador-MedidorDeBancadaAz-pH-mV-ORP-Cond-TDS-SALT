cmake_minimum_required(VERSION 3.5)

project(Pedro VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

SET(CMAKE_C_COMPILER c:/mingw64/bin/gcc.exe)
SET(CMAKE_CXX_COMPILER c:/mingw64/bin/g++.exe)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -static -W -Wall")

set(CMAKE_PREFIX_PATH "G:/Qt/6.7.0/mingw_64")

find_package(Qt6 REQUIRED COMPONENTS Core Widgets PrintSupport LinguistTools Quick Gui)

include_directories("G:/Qt/6.7.0/mingw_64/include/" "G:/Pedro/Pedro")

add_executable(
	Pedro
	qcustomplot.cpp
        qcustomplot.h
	about.cpp
        about.h
        about.ui
        enums.h
        measure.cpp
        measure.h
        sensor.cpp
        sensor.h
        utils.cpp
        utils.h
	Instrumentor.h
	Instrumentor.cpp
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

set_source_files_properties(${TS_FILES} PROPERTIES OUTPUT_LOCATION "l18n")
qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} Pedro_PT.ts)

target_link_libraries(Pedro PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::PrintSupport Qt${QT_VERSION_MAJOR}::Gui Qt${QT_VERSION_MAJOR}::Quick)


