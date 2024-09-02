#include "MidiControllerSensor.hpp"
#include "../core/Logger.hpp"
#include <random>

namespace InstrumotionCore {

MidiControllerSensor::MidiControllerSensor() {
    metadata.name = "MIDI Controller Sensor";
    metadata.type = SensorType::MIDI_CONTROLLER;
    metadata.capabilities = {"capture_notes", "capture_control_changes"};
}

bool MidiControllerSensor::initialize() {
    LOG_INFO("Initializing MIDI Controller Sensor");
    // Add initialization logic here
    return true;
}

bool MidiControllerSensor::captureData() {
    LOG_INFO("Capturing data from MIDI Controller Sensor");
    
    // Simulate MIDI data capture
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> note_dist(0, 127);
    std::uniform_int_distribution<> velocity_dist(0, 127);
    
    int note = note_dist(gen);
    int velocity = velocity_dist(gen);
    
    LOG_INFO("MIDI Note On: note=" + std::to_string(note) + ", velocity=" + std::to_string(velocity));
    
    return true;
}

void MidiControllerSensor::cleanup() {
    LOG_INFO("Cleaning up MIDI Controller Sensor");
    // Add cleanup logic here
}

SensorMetadata MidiControllerSensor::getMetadata() const {
    return metadata;
}

} // namespace InstrumotionCore
