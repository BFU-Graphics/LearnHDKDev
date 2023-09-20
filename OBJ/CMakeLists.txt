set(OBJ_TARGETS
        OBJ_01_Gravity
#        OBJ_02_MassSpring
)

foreach(TARGET ${OBJ_TARGETS})
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
endforeach(TARGET)
