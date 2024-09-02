#include "CameraSensor.hpp"
#include "../core/Logger.hpp"

namespace InstrumotionCore {

CameraSensor::CameraSensor() {
    metadata.name = "Camera Sensor";
    metadata.type = SensorType::CAMERA;
    metadata.capabilities = {"capture_image", "adjust_exposure"};
}

bool CameraSensor::initialize() {
    LOG_INFO("Initializing Camera Sensor");
    // Add initialization logic here
    return true;
}

bool CameraSensor::captureData() {
    LOG_INFO("Capturing data from Camera Sensor");
    // Add data capture logic here
    return true;
}

void CameraSensor::cleanup() {
    LOG_INFO("Cleaning up Camera Sensor");
    // Add cleanup logic here
}

SensorMetadata CameraSensor::getMetadata() const {
    return metadata;
}

} // namespace InstrumotionCore
