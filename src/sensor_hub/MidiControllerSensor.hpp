#pragma once

#include "ISensor.hpp"

namespace InstrumotionCore {

class MidiControllerSensor : public ISensor {
public:
    MidiControllerSensor();
    ~MidiControllerSensor() override = default;

    bool initialize() override;
    bool captureData() override;
    void cleanup() override;
    SensorMetadata getMetadata() const override;

private:
    SensorMetadata metadata;
};

} // namespace InstrumotionCore
