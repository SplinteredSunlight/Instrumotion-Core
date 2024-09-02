#include "InstrumotionCoreAPI.hpp"
#include "../sensor_hub/SensorManager.hpp"
#include "../core/Logger.hpp"
#include "../core/Error.hpp"

InstrumotionCoreAPI::InstrumotionCoreAPI() : sensorManager(std::make_unique<SensorManager>()) {
    LOG_INFO("InstrumotionCoreAPI initialized");
}

InstrumotionCoreAPI::~InstrumotionCoreAPI() = default;

std::vector<SensorMetadata> InstrumotionCoreAPI::discoverSensors() {
    LOG_INFO("Discovering available sensors");
    return sensorManager->getAvailableSensors();
}

bool InstrumotionCoreAPI::selectSensor(const std::string& sensorName) {
    try {
        auto* sensor = sensorManager->getSensor(sensorName);
        if (sensor) {
            LOG_INFO("Sensor " + sensorName + " selected");
            return true;
        }
    } catch (const InstrumotionCoreError& e) {
        LOG_ERROR("Error selecting sensor: " + std::string(e.what()));
    }
    return false;
}

bool InstrumotionCoreAPI::configureSensor(const std::string& sensorName, const std::string& configKey, const std::string& configValue) {
    try {
        auto* sensor = sensorManager->getSensor(sensorName);
        if (sensor) {
            // This is a placeholder. In a real implementation, you would have a configuration method in the ISensor interface.
            LOG_INFO("Configuring sensor " + sensorName + ": " + configKey + " = " + configValue);
            return true;
        }
    } catch (const InstrumotionCoreError& e) {
        LOG_ERROR("Error configuring sensor: " + std::string(e.what()));
    }
    return false;
}

SensorData InstrumotionCoreAPI::retrieveData(const std::string& sensorName) {
    try {
        auto* sensor = sensorManager->getSensor(sensorName);
        if (sensor && sensor->captureData()) {
            // This is a placeholder. In a real implementation, you would return actual sensor data.
            LOG_INFO("Data retrieved from sensor " + sensorName);
            return SensorData(); // Return empty SensorData for now
        }
    } catch (const InstrumotionCoreError& e) {
        LOG_ERROR("Error retrieving data: " + std::string(e.what()));
    }
    return SensorData(); // Return empty SensorData in case of error
}

bool InstrumotionCoreAPI::enlistNewSensor(std::unique_ptr<ISensor> sensor) {
    if (sensorManager->registerSensor(std::move(sensor))) {
        LOG_INFO("New sensor enlisted successfully");
        return true;
    }
    LOG_ERROR("Failed to enlist new sensor");
    return false;
}
}
