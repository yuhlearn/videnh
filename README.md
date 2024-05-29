# Real-ESRGAN ncnn Vulkan

This is a video enhancement tool. It started off as a fork of [Real-ESRGAN-ncnn-vulkan](https://github.com/xinntao/Real-ESRGAN-ncnn-vulkan). 

## TODO List

- [x] Update README with compilation instructions.
- [ ] Modify the project to work on video files instead of images.
- [ ] Update TODO with more things.

## Usage

### Building the project

There are a number of dependancies you need before you can compile the project. For Debian, the following might do:

```
sudo apt-get install cmake libvulkan-dev libglut-dev glslc glslang-tools libgif-dev
```

Use the following commands to clone the repo with submodules and build the project.

```
git clone https://github.com/yuhlearn/videnh.git
cd videnh
git submodule update --init --recursive
mkdir build 
cd build
cmake ../src
cmake --build . -j 4
```

### Example Command

TBI

### Full Usages

TBI

## Other Open-Source Code Used

- https://github.com/xinntao/Real-ESRGAN-ncnn-vulkan aims at developing Practical Algorithms for General Image Restoration
- https://github.com/Tencent/ncnn for fast neural network inference on ALL PLATFORMS
- https://github.com/webmproject/libwebp for encoding and decoding Webp images on ALL PLATFORMS
- https://github.com/nothings/stb for decoding and encoding image on Linux / MacOS
- https://github.com/tronkko/dirent for listing files in directory on Windows

