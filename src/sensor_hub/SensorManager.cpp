#include "SensorManager.hpp"
#include "../core/Logger.hpp"
#include "../core/Error.hpp"
#include "PluginManager.hpp"

namespace InstrumotionCore {

#ifdef _WIN32
#define PLATFORM_PLUGIN_PATH "plugins/windows/"
#elif __APPLE__
#define PLATFORM_PLUGIN_PATH "plugins/macos/"
#elif __linux__
#define PLATFORM_PLUGIN_PATH "plugins/linux/"
#elif __ANDROID__
#define PLATFORM_PLUGIN_PATH "plugins/android/"
#elif __ios__
#define PLATFORM_PLUGIN_PATH "plugins/ios/"
#else
#error "Unsupported platform"
#endif

SensorManager::SensorManager() : pluginManager(std::make_unique<PluginManager>()) {
#ifdef _WIN32
    loadPlugin(PLATFORM_PLUGIN_PATH "windows_sensor.dll");
#elif __APPLE__
    loadPlugin(PLATFORM_PLUGIN_PATH "macos_sensor.dylib");
#elif __linux__
    loadPlugin(PLATFORM_PLUGIN_PATH "linux_sensor.so");
#elif __ANDROID__
    loadPlugin(PLATFORM_PLUGIN_PATH "android_sensor.so");
#elif __ios__
    loadPlugin(PLATFORM_PLUGIN_PATH "ios_sensor.dylib");
#endif
}



void SensorManager::loadPlugin(const std::string& pluginPath) {
    pluginManager->loadPlugin(pluginPath);
    auto loadedSensors = pluginManager->getLoadedSensors();
    for (const auto& sensor : loadedSensors) {
        registerSensor(std::unique_ptr<ISensor>(sensor->clone()));
    }
}


void SensorManager::loadPlugin(const std::string& pluginPath) {
    pluginManager->loadPlugin(pluginPath);
    auto loadedSensors = pluginManager->getLoadedSensors();
    for (const auto& sensor : loadedSensors) {
        registerSensor(std::unique_ptr<ISensor>(sensor->clone()));
    }
}

bool SensorManager::registerSensor(std::unique_ptr<ISensor> sensor) {
    auto metadata = sensor->getMetadata();
    if (sensors.find(metadata.name) != sensors.end()) {
        LOG_WARNING("Sensor with name " + metadata.name + " already exists.");
        return false;
    }
    sensors[metadata.name] = std::move(sensor);
    LOG_INFO("Registered sensor: " + metadata.name);
    return true;
}

bool SensorManager::unregisterSensor(const std::string& sensorName) {
    auto it = sensors.find(sensorName);
    if (it == sensors.end()) {
        LOG_WARNING("Sensor " + sensorName + " not found.");
        return false;
    }
    sensors.erase(it);
    LOG_INFO("Unregistered sensor: " + sensorName);
    return true;
}

std::vector<SensorMetadata> SensorManager::getAvailableSensors() const {
    std::vector<SensorMetadata> availableSensors;
    for (const auto& [name, sensor] : sensors) {
        availableSensors.push_back(sensor->getMetadata());
    }
    return availableSensors;
}

ISensor* SensorManager::getSensor(const std::string& sensorName) {
    auto it = sensors.find(sensorName);
    if (it == sensors.end()) {
        throw InstrumotionCoreError("Sensor " + sensorName + " not found.");
    }
    return it->second.get();
}

} // namespace InstrumotionCore
