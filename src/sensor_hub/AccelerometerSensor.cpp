#include "AccelerometerSensor.hpp"
#include "../core/Logger.hpp"

namespace InstrumotionCore {

AccelerometerSensor::AccelerometerSensor() {
    metadata.name = "Accelerometer Sensor";
    metadata.type = SensorType::ACCELEROMETER;
    metadata.capabilities = {"measure_acceleration", "detect_orientation"};
}

bool AccelerometerSensor::initialize() {
    LOG_INFO("Initializing Accelerometer Sensor");
    // Add initialization logic here
    return true;
}

bool AccelerometerSensor::captureData() {
    LOG_INFO("Capturing data from Accelerometer Sensor");
    // Simulate capturing acceleration data
    double x = 0.0, y = 0.0, z = 9.81; // Example: device at rest on a flat surface
    LOG_INFO("Acceleration: x=" + std::to_string(x) + ", y=" + std::to_string(y) + ", z=" + std::to_string(z));
    return true;
}

void AccelerometerSensor::cleanup() {
    LOG_INFO("Cleaning up Accelerometer Sensor");
    // Add cleanup logic here
}

SensorMetadata AccelerometerSensor::getMetadata() const {
    return metadata;
}

} // namespace InstrumotionCore
