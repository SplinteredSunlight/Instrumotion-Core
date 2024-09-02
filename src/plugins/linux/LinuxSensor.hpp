#pragma once

#include "ISensor.hpp"

class LinuxSensor : public ISensor {
public:
    LinuxSensor();
    ~LinuxSensor() override;

    bool initialize() override;
    SensorData captureData() override;
    void cleanup() override;
    SensorMetadata getMetadata() const override;

private:
    // Linux-specific sensor implementation details
};

extern "C" {
    ISensor* createSensor() {
        return new LinuxSensor();
    }
}
