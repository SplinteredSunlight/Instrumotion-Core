#include "PluginManager.hpp"
#include <dlfcn.h>
#include <stdexcept>

class PluginManager::Impl {
public:
    std::vector<void*> loadedLibraries;
    std::vector<std::shared_ptr<ISensor>> loadedSensors;

    ~Impl() {
        for (void* handle : loadedLibraries) {
            dlclose(handle);
        }
    }
};

PluginManager::PluginManager() : pImpl(std::make_unique<Impl>()) {}

PluginManager::~PluginManager() = default;

void PluginManager::loadPlugin(const std::string& pluginPath) {
    void* handle = dlopen(pluginPath.c_str(), RTLD_LAZY);
    if (!handle) {
        throw std::runtime_error("Failed to load plugin: " + std::string(dlerror()));
    }

    using CreateSensorFunc = ISensor* (*)();
    CreateSensorFunc createSensor = reinterpret_cast<CreateSensorFunc>(dlsym(handle, "createSensor"));
    if (!createSensor) {
        dlclose(handle);
        throw std::runtime_error("Failed to find createSensor function in plugin");
    }

    ISensor* sensor = createSensor();
    if (!sensor) {
        dlclose(handle);
        throw std::runtime_error("Failed to create sensor instance from plugin");
    }

    pImpl->loadedLibraries.push_back(handle);
    pImpl->loadedSensors.emplace_back(sensor);
}

std::vector<std::shared_ptr<ISensor>> PluginManager::getLoadedSensors() const {
    return pImpl->loadedSensors;
}
