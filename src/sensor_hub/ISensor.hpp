#ifndef ISENSOR_HPP
#define ISENSOR_HPP

#include <string>

struct SensorMetadata {
    std::string name;
    std::string type;
    // Add any other relevant metadata fields
};

class ISensor {
public:
    virtual ~ISensor() = default;
    
    virtual void initialize() = 0;
    virtual void update() = 0;
    virtual void shutdown() = 0;
};

#endif // ISENSOR_HPP