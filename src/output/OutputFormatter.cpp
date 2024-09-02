#include "OutputFormatter.hpp"
#include <sstream>
#include <iomanip>

namespace InstrumotionCore {

std::string OutputFormatter::formatSensorData(const SensorData& data) {
    std::ostringstream oss;
    oss << "Sensor: " << data.sensorName << "\n";
    oss << "Timestamp: " << std::chrono::system_clock::to_time_t(data.timestamp) << "\n";
    oss << "Data: ";
    for (const auto& byte : data.data) {
        oss << std::setw(2) << std::setfill('0') << std::hex << static_cast<int>(byte) << " ";
    }
    oss << "\n";
    return oss.str();
}

std::vector<uint8_t> OutputFormatter::serializeSensorData(const SensorData& data) {
    std::vector<uint8_t> serialized;
    // Implement serialization logic here
    // This is a placeholder implementation
    serialized = data.data;
    return serialized;
}

SensorData OutputFormatter::deserializeSensorData(const std::vector<uint8_t>& serializedData) {
    SensorData data;
    // Implement deserialization logic here
    // This is a placeholder implementation
    data.data = serializedData;
    return data;
}

} // namespace InstrumotionCore
