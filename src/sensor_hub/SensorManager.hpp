#pragma once

#include "ISensor.hpp"
#include "../plugins/PluginManager.hpp"
#include <memory>
#include <vector>
#include <unordered_map>

namespace InstrumotionCore {

class SensorManager {
public:
    SensorManager();
    bool registerSensor(std::unique_ptr<ISensor> sensor);
    bool unregisterSensor(const std::string& sensorName);
    std::vector<SensorMetadata> getAvailableSensors() const;
    ISensor* getSensor(const std::string& sensorName);
    void loadPlugin(const std::string& pluginPath);

private:
    std::unordered_map<std::string, std::unique_ptr<ISensor>> sensors;
    std::unique_ptr<PluginManager> pluginManager;
};

} // namespace InstrumotionCore
