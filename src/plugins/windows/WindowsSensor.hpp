#pragma once

#include "ISensor.hpp"

class WindowsSensor : public ISensor {
public:
    WindowsSensor();
    ~WindowsSensor() override;

    bool initialize() override;
    SensorData captureData() override;
    void cleanup() override;
    SensorMetadata getMetadata() const override;

private:
    // Windows-specific sensor implementation details
};

extern "C" {
    ISensor* createSensor() {
        return new WindowsSensor();
    }
}
