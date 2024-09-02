
# Building on Windows

conan install conanfile.txt -of=build
cmake -G "Visual Studio 17 2022" -B ./build -S .