
# Building on Linux

python3 -m venv virtual_pyenv

virtual_pyenv\Scripts\activate

pip install conan

conan install conanfile.txt --build=missing --output-folder=build

cmake -G "Ninja" -B ./build -S .


# Building on Windows

"C:\Program Files\Python311\python.exe" -m venv virtual_pyenv

virtual_pyenv\Scripts\activate.bat

pip install conan

conan install conanfile.txt --profile=windows.txt --build=missing --output-folder=build

cmake -G "Visual Studio 17 2022" -B .\build -S .

