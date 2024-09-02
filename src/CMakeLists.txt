add_subdirectory(core ${CMAKE_BINARY_DIR}/instrumotion_core_core_build)
add_subdirectory(sync ${CMAKE_BINARY_DIR}/instrumotion_core_sync_build)
add_subdirectory(output ${CMAKE_BINARY_DIR}/instrumotion_core_output_build)
add_subdirectory(api ${CMAKE_BINARY_DIR}/instrumotion_core_api_build)
add_subdirectory(sensor_hub ${CMAKE_BINARY_DIR}/instrumotion_core_sensor_hub_build)
add_subdirectory(plugins ${CMAKE_BINARY_DIR}/instrumotion_core_plugins_build)
add_subdirectory(gesture_recognition ${CMAKE_BINARY_DIR}/instrumotion_core_gesture_recognition_build)
add_subdirectory(audio ${CMAKE_BINARY_DIR}/instrumotion_core_audio_build)
add_subdirectory(ar ${CMAKE_BINARY_DIR}/instrumotion_core_ar_build)
add_subdirectory(sam2 ${CMAKE_BINARY_DIR}/instrumotion_core_sam2_build)

add_library(instrumotion_core_main_lib INTERFACE)

target_link_libraries(instrumotion_core_main_lib
    INTERFACE
    instrumotion_core_lib
    sync_lib
    output_lib
    api_lib
    sensor_hub_lib
    plugins_lib
    gesture_recognition_lib
    audio_lib
    ar_lib
    sam2_lib
)

target_include_directories(instrumotion_core_main_lib
    INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/core
    ${CMAKE_CURRENT_SOURCE_DIR}/sync
    ${CMAKE_CURRENT_SOURCE_DIR}/output
    ${CMAKE_CURRENT_SOURCE_DIR}/api
    ${CMAKE_CURRENT_SOURCE_DIR}/sensor_hub
    ${CMAKE_CURRENT_SOURCE_DIR}/plugins
    ${CMAKE_CURRENT_SOURCE_DIR}/gesture_recognition
    ${CMAKE_CURRENT_SOURCE_DIR}/audio
    ${CMAKE_CURRENT_SOURCE_DIR}/ar
    ${CMAKE_CURRENT_SOURCE_DIR}/sam2
)

# Tests are now in a separate CMakeLists.txt file in the tests directory

# Add executable target with a unique name
add_executable(instrumotion_core_main_exe main.cpp)
target_link_libraries(instrumotion_core_main_exe PRIVATE instrumotion_core_main_lib)

# Tests are now in a separate CMakeLists.txt file in the tests directory