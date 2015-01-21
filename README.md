# PictureDisplayer


----
### Build on Windows x86
##### QT 5.3
[Download and install](http://download.qt.io/archive/qt/5.3/5.3.2/qt-opensource-windows-x86-mingw482_opengl-5.3.2.exe)

##### Boost 1.57.0
[Download](http://www.boost.org/users/history/version_1_57_0.html)
```
1.  Unzip it
2.  Run cmd in Administrator and type below command
      cd boost_1_57_0
      set PATH=C:\Qt5\Tools\mingw482_32\bin;%PATH%
      bootstrap mingw
      b2 toolset=gcc
3. Check libboost_*-mgw48-mt-1_57.a files in boost_1_57_0/stage/lib
```


### Build on Linux 64-bit (Ubuntu-14.04.1-LTS-x86_64)

##### QT 5.3
[Download and install](http://www.qt.io/download/)

##### libGL
```bash
$ sudo apt-get install libglu1-mesa-dev -y
```

##### GStreamer
```bash
sudo apt-get install gstreamer0.10-plugins-bad gstreamer0.10-plugins-ugly gstreamer0.10-fluendo-mp3
```

##### Boost 1.57.0
[Download and install](http://www.boost.org/)

or

```bash
$ git clone https://github.com/boostorg/boost.git
$ cd boost
$ git checkout boost-1.57.0 -b boost-1.57.0
$ git submodule init
$ git submodule update
$ ./bootstrap.sh --prefix=`pwd`/build/
$ ./b2 variant=release install
$ sudo ln -s `pwd`/build/include/boost/ /usr/include/boost_1_57_0
$ sudo ln -s `pwd`/build/lib/ /usr/lib/boost_lib
```

----
#### Attention
```bash
In order not to load resource(image/script) fail, please disable shadow build with 
QT Creator as recommended.
```
#### Application
```bash
$ git clone https://github.com/WalonLi/PictureDisplayer.git
$ cd PictureDisplayer/
$ mkdir build
$ cd build/
$ qmake ..
$ make
$ export LD_LIBRARY_PATH=/usr/lib/boost_lib:$LD_LIBRARY_PATH
$ ./PictureDisplayer
```

