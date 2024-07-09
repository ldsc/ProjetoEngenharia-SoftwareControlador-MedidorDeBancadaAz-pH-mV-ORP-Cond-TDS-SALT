@echo "Criando diretorios"

rem Limpa diretório de build anterior, se existir
rmdir /s /q build
rmdir /s /q bin

rem Cria diretório de build
mkdir bin
mkdir build

rem Executa o CMake para configurar o projeto em modo Release
cmake -B build

rem Executa o CMake para configurar o projeto em modo Release
cmake -B build -DCMAKE_BUILD_TYPE=Release

rem Compila o projeto
cmake --build build