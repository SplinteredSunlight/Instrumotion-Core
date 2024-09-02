#pragma once

#include "ISensor.hpp"

class IOSSensor : public ISensor {
public:
    IOSSensor();
    ~IOSSensor() override;

    bool initialize() override;
    SensorData captureData() override;
    void cleanup() override;
    SensorMetadata getMetadata() const override;

private:
    // iOS-specific sensor implementation details
};

extern "C" {
    ISensor* createSensor() {
        return new IOSSensor();
    }
}
