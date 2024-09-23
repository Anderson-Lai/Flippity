## Building from source

**Prerequisites**:
- wxWidgets
- libcurl
- CMake 3.20 or higher
- A C++ compiler supporting C++20
- all other dependencies will be feteched via CMake during build time  

### Installation on Debian-based Linux distros

#### Installing wxWidgets

``` sh
sudo apt install -y libgtk-3-dev libgl1-mesa-dev libglu1-mesa-dev libegl1-mesa-dev libgstreamer-plugins-base1.0-dev
git clone --recurse-submodules https://github.com/wxWidgets/wxWidgets.git
cd wxWidgets
mkdir buildgtk
cd buildgtk
../configure --enable-optimise --with-gtk=3 --prefix=/usr/local   
make -j$(nproc)
sudo make install
sudo ldconfig
```

#### Installing libcurl

``` sh
sudo apt install libcurl4-openssl-dev
```

#### Installing CMake and a C++ compiler

``` sh
sudo apt install cmake
sudo apt install gcc
```

### Building the Project 

``` sh
mkdir build
cd build 

cmake -- . --DCMAKE_BUILD_TYPE=Release -DNDEBUG
cmake --build . --config Release
```
