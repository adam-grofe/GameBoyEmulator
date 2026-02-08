
#include <memory>

#include "logger/ILogger.hpp"
#include "logger/NullLogger.hpp"

std::shared_ptr<Logger::ILogger> Logger::logger_factory(Logger::LoggerType loggerType)
{
    return std::make_shared<Logger::NullLoggerImpl>();
}