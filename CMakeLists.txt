cmake_minimum_required(VERSION 3.26)
project(LearnHDK)

set(CMAKE_CXX_STANDARD 17)

set(Houdini_DIR "C:/Program Files/Side Effects Software/Houdini 19.5.716/toolkit/cmake")
find_package(Houdini REQUIRED)

add_library(MyLib1 SHARED
        my_lib1.h
        my_lib1.cpp
)
target_link_libraries(MyLib1 PUBLIC Houdini)
target_include_directories(MyLib1
        PRIVATE
        ${CMAKE_CURRENT_BINARY_DIR}
)
houdini_configure_target(MyLib1)
