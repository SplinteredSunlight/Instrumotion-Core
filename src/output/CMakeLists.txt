add_library(instrumotion_output_lib STATIC
    OutputFormatter.cpp
)

target_include_directories(instrumotion_output_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../../include
)

target_link_libraries(instrumotion_output_lib PRIVATE instrumotion_core_lib)
