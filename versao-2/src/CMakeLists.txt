cmake_minimum_required(VERSION 3.5)

project(Pedro VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

SET(CMAKE_C_COMPILER c:/mingw64/bin/gcc.exe)
SET(CMAKE_CXX_COMPILER c:/mingw64/bin/g++.exe)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(QCUSTOMPLOT_VERSION 2.1.1 CACHE STRING "")
set(QCUSTOMPLOT_URL "https://www.qcustomplot.com/release/2.1.1/QCustomPlot.tar.gz" CACHE STRING "")
set(QT_VERSION 5 CACHE STRING "")
set(CMAKE_BUILD_TYPE "Release" CACHE STRING "")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -static -W -Wall")

include(FetchContent)
FetchContent_Declare(qcustomplot
  URL "${QCUSTOMPLOT_URL}"
  )
FetchContent_MakeAvailable(qcustomplot)

add_library(qcustomplot
  "${qcustomplot_SOURCE_DIR}/qcustomplot.h"
  "${qcustomplot_SOURCE_DIR}/qcustomplot.cpp"
  )

target_include_directories(qcustomplot PUBLIC
"${qcustomplot_SOURCE_DIR}"
)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets LinguistTools PrintSupport)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets LinguistTools PrintSupport)


set(TS_FILES Pedro_pt_BR.ts)

set(CMAKE_INSTALL_LIBDIR CMAKE_LIBRARY_OUTPUT_DIRECTORY ../../lib)
set(CMAKE_INSTALL_BINDIR CMAKE_BINARY_DIR ./bin)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
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
        qcustomplot.cpp
        qcustomplot.h

        ${TS_FILES}
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Pedro
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Pedro APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation

    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    if(ANDROID)
        add_library(Pedro SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Pedro
            ${PROJECT_SOURCES}
        )
    endif()

    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

target_link_libraries(Pedro PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::PrintSupport qcustomplot)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Pedro)
endif()
set_target_properties(Pedro PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Pedro)
endif()
