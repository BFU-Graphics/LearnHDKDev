cmake_minimum_required(VERSION 3.26)
project(LearnHDK)

set(CMAKE_CXX_STANDARD 17)

set(Houdini_DIR "E:/Softwares/Houdini/APP/Houdini19.5.716/toolkit/cmake")
find_package(Houdini REQUIRED)

#set(TARGET Gravity)
set(TARGET SIM_ForceOrbit)

add_library(${TARGET} SHARED
        ${TARGET}.h
        ${TARGET}.C
)
target_link_libraries(${TARGET} PUBLIC Houdini)
target_include_directories(${TARGET}
        PRIVATE
        ${CMAKE_CURRENT_BINARY_DIR}
)
houdini_configure_target(${TARGET})
