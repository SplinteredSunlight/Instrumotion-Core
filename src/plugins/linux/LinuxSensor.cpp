#include "LinuxSensor.hpp"

LinuxSensor::LinuxSensor() {}

LinuxSensor::~LinuxSensor() {}

bool LinuxSensor::initialize() {
    // Initialize Linux-specific sensor
    return true;
}

SensorData LinuxSensor::captureData() {
    // Capture data from Linux-specific sensor
    return SensorData();
}

void LinuxSensor::cleanup() {
    // Cleanup Linux-specific sensor resources
}

SensorMetadata LinuxSensor::getMetadata() const {
    return SensorMetadata {
        "LinuxSensor",
        SensorType::PLATFORM_SPECIFIC,
        "Linux-specific sensor"
    };
}
