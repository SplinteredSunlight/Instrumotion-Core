add_library(instrumotion_core_lib INTERFACE
    Logger.hpp
    Error.hpp
)

target_include_directories(instrumotion_core_lib INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../../include
)
