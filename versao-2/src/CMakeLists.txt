cmake_minimum_required(VERSION 3.25)

project(Pedro VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_COMPILER "${Qt6_DIR}/../../../../../Tools/mingw1120_64/bin/g++.exe")

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Configuração para C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

# Encontrar pacotes do Qt
find_package(Qt6 REQUIRED COMPONENTS Core Widgets PrintSupport LinguistTools Quick Gui)

# Listar arquivos fonte
set(SOURCES
    ${CMAKE_SOURCE_DIR}/main.cpp
    ${CMAKE_SOURCE_DIR}/about.cpp
    ${CMAKE_SOURCE_DIR}/about.ui
    ${CMAKE_SOURCE_DIR}/instrumentor.cpp
    ${CMAKE_SOURCE_DIR}/mainwindow.cpp
    ${CMAKE_SOURCE_DIR}/mainwindow.ui
    ${CMAKE_SOURCE_DIR}/measure.cpp
    ${CMAKE_SOURCE_DIR}/qcustomplot.cpp
    ${CMAKE_SOURCE_DIR}/sensor.cpp
    ${CMAKE_SOURCE_DIR}/utils.cpp
    ${CMAKE_SOURCE_DIR}/build.rc
)

# Definir arquivos de tradução
set(TS_FILES ${CMAKE_SOURCE_DIR}/Pedro_PT.ts)

# Gerar arquivos de tradução
qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})

# Criar o executável
add_executable(Pedro WIN32 ${SOURCES})

# Adicionar diretório do qcustomplot.h ao alvo
target_include_directories(Pedro PRIVATE ${CMAKE_SOURCE_DIR})

# Definir diretório de saída do executável
set_target_properties(Pedro PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Vincular bibliotecas do Qt ao executável
target_link_libraries(Pedro PRIVATE Qt6::Core Qt6::Widgets Qt6::PrintSupport Qt6::Gui Qt6::Quick)

add_custom_command(TARGET Pedro POST_BUILD
    COMMAND "${Qt6_DIR}/../../../../mingw_64/bin/windeployqt.exe" --compiler-runtime $<TARGET_FILE:Pedro>
    COMMAND "${Qt6_DIR}/../../../../mingw_64/bin/lupdate.exe" ${SOURCES} -ts ${TS_FILES}
    COMMAND ${CMAKE_COMMAND} -E copy ${TS_FILES} ${CMAKE_SOURCE_DIR}/bin/
    COMMAND ${CMAKE_COMMAND} -E remove ${TS_FILES}
    COMMENT "Deploying Qt dependencies and moving translation file"
)
