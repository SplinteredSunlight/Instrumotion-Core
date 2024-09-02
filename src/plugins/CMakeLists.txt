add_library(plugin_manager STATIC
    PluginManager.cpp
)

target_include_directories(plugin_manager PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../../include
)

target_link_libraries(plugin_manager PRIVATE
    ${CMAKE_DL_LIBS}
)

# Platform-specific plugin subdirectories
add_subdirectory(windows)
add_subdirectory(macos)
add_subdirectory(linux)
add_subdirectory(android)
add_subdirectory(ios)
