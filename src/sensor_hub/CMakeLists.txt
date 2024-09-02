add_library(sensor_hub_lib
    SensorManager.cpp
    CameraSensor.cpp
    AccelerometerSensor.cpp
    MidiControllerSensor.cpp
)

target_link_libraries(sensor_hub_lib PRIVATE core_lib)
target_include_directories(sensor_hub_lib PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(sensor_hub_lib PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
