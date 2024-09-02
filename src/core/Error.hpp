#pragma once

#include <stdexcept>
#include <string>

namespace InstrumotionCore {

class InstrumotionCoreError : public std::runtime_error {
public:
    explicit InstrumotionCoreError(const std::string& message) : std::runtime_error(message) {}
};

} // namespace InstrumotionCore
