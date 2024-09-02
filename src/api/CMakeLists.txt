add_library(api_lib STATIC
    InstrumotionCoreAPI.cpp
)

target_link_libraries(api_lib PRIVATE core sensor_hub)
target_include_directories(api_lib PUBLIC ${PROJECT_SOURCE_DIR}/include)
