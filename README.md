# BoostSharedMemoryTemplate

A templated wrapper for Boost Shared Memory that is compatible with PySHMXtreme

## Requirements
1. Boost
2. CMake

## Installation
```
git clone https://github.com/ColinTogashi/BoostSharedMemoryTemplate
mkdir build
cmake ..
sudo make install
```

If /usr/local is not part of the LD_LIBRARY_PATH:
```
echo "export LD_LIBRARY_PATH=\"${LD_LIBRARY_PATH}:/usr/local/lib\""  >>  ~/.bashrc
```

## Platforms Tested On

1. Ubuntu 18.04 (Boost 1.65.0, CMake 3.9)
