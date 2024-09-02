#pragma once

#include "ISensor.hpp"

class AndroidSensor : public ISensor {
public:
    AndroidSensor();
    ~AndroidSensor() override;

    bool initialize() override;
    SensorData captureData() override;
    void cleanup() override;
    SensorMetadata getMetadata() const override;

private:
    // Android-specific sensor implementation details
};

extern "C" {
    ISensor* createSensor() {
        return new AndroidSensor();
    }
}
