#pragma once

#include "ISensor.hpp"

namespace InstrumotionCore {

class AccelerometerSensor : public ISensor {
public:
    AccelerometerSensor();
    ~AccelerometerSensor() override = default;

    bool initialize() override;
    bool captureData() override;
    void cleanup() override;
    SensorMetadata getMetadata() const override;

private:
    SensorMetadata metadata;
};

} // namespace InstrumotionCore
