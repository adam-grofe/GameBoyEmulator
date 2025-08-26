
#include <memory>

#include "logger/ILogger.hpp"
#include "logger/QtLogger.hpp"

std::shared_ptr<Logger::ILogger> Logger::logger_factory(Logger::LoggerType loggerType)
{
    switch (loggerType)
    {
    case QtLogger:
        return std::make_shared<QtLogger>();
    }
}