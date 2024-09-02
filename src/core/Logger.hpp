#pragma once

#include <iostream>
#include <string>

namespace InstrumotionCore {

enum class LogLevel {
    DEBUG,
    INFO,
    WARNING,
    ERROR
};

class Logger {
public:
    static void log(LogLevel level, const std::string& message) {
        switch (level) {
            case LogLevel::DEBUG:
                std::cout << "[DEBUG] ";
                break;
            case LogLevel::INFO:
                std::cout << "[INFO] ";
                break;
            case LogLevel::WARNING:
                std::cout << "[WARNING] ";
                break;
            case LogLevel::ERROR:
                std::cerr << "[ERROR] ";
                break;
        }
        std::cout << message << std::endl;
    }
};

} // namespace InstrumotionCore

#define LOG_DEBUG(message) InstrumotionCore::Logger::log(InstrumotionCore::LogLevel::DEBUG, message)
#define LOG_INFO(message) InstrumotionCore::Logger::log(InstrumotionCore::LogLevel::INFO, message)
#define LOG_WARNING(message) InstrumotionCore::Logger::log(InstrumotionCore::LogLevel::WARNING, message)
#define LOG_ERROR(message) InstrumotionCore::Logger::log(InstrumotionCore::LogLevel::ERROR, message)
