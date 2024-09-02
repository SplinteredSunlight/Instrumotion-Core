#pragma once

#include "ISensor.hpp"

class MacOSSensor : public ISensor {
public:
    MacOSSensor();
    ~MacOSSensor() override;

    bool initialize() override;
    SensorData captureData() override;
    void cleanup() override;
    SensorMetadata getMetadata() const override;

private:
    // macOS-specific sensor implementation details
};

extern "C" {
    ISensor* createSensor() {
        return new MacOSSensor();
    }
}
