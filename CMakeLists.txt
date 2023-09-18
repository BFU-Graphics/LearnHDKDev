cmake_minimum_required(VERSION 3.26)
project(LearnHDK)

set(CMAKE_CXX_STANDARD 17)

set(Houdini_DIR "E:/Softwares/Houdini/APP/Houdini19.5.716/toolkit/cmake")
find_package(Houdini REQUIRED)

add_subdirectory(OBJ)
