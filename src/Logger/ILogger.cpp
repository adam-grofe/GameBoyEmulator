
#include <memory>

#include "Logger/ILogger.hpp"
#include "Logger/NullLogger.hpp"

std::shared_ptr<Logger::ILogger> Logger::logger_factory(Logger::LoggerType loggerType)
{
    return std::make_shared<Logger::NullLoggerImpl>();
}
