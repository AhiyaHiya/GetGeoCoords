
# Building on Windows

"C:\Program Files\Python311\python.exe" -m venv py311_venv
py311_venv2\Scripts\activate.bat
pip install conan
conan install conanfile.txt --profile=windows.txt --build=missing --output-folder=build
cmake -G "Visual Studio 17 2022" -B ./build -S .