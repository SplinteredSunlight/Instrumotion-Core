#include "InstrumotionCoreAPI.hpp"
#include <iostream>

int main() {
    InstrumotionCoreAPI api;
    
    std::cout << "InstrumotionCore initialized. Discovering sensors..." << std::endl;
    
    auto sensors = api.discoverSensors();
    
    std::cout << "Discovered " << sensors.size() << " sensors:" << std::endl;
    for (const auto& sensor : sensors) {
        std::cout << "- " << sensor.name << " (Type: " << static_cast<int>(sensor.type) << ")" << std::endl;
    }
    
    return 0;
}
