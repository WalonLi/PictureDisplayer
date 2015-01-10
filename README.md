# PictureDisplayer

### Build on Linux 64-bit (Ubuntu-14.04.1-LTS-x86_64)

#### QT 5.3
[Download and install](http://www.qt.io/download/)
```bash
In order not to load resource(image/script) fail, please disable shadow build with QT Creator as 
recommended.
```

#### libGL
```bash
$ sudo apt-get install libglu1-mesa-dev -y
```

#### Boost 1.57.0
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

#### Application
```bash
$ git clone https://github.com/WalonLi/PictureDisplayer.git
$ cd PictureDisplayer/
$ mkdir build
$ cd build/
$ qmake ..
$ make
```
