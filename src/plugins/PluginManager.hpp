#pragma once

#include <string>
#include <vector>
#include <memory>
#include "../sensor_hub/ISensor.hpp"

class PluginManager {
public:
    PluginManager() = default;
    ~PluginManager() = default;

    bool loadPlugin(const std::string& pluginPath);
    std::vector<std::unique_ptr<ISensor>> getLoadedSensors() const;

private:
    // Implementation details to be added
};
