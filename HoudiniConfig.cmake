set(Houdini_PATH "E:/Softwares/Houdini/APP/Houdini19.5.716")
set(Houdini_DIR ${Houdini_PATH}/toolkit/cmake)
find_package(Houdini REQUIRED)

function(NEW_HDK_NODE TARGET)
    add_library(${TARGET} SHARED
            ${TARGET}.h
            ${TARGET}.cpp
    )
    target_link_libraries(${TARGET} PUBLIC Houdini)
    target_include_directories(${TARGET}
            PRIVATE
            ${CMAKE_CURRENT_BINARY_DIR}
    )
    houdini_configure_target(${TARGET})
endfunction()
