#pragma once

#include <memory>
#include <string_view>

namespace Logger
{

class ILogger
{

  public:
    virtual void Debug(std::string_view s) = 0;
    virtual void Info(std::string_view s) = 0;
    virtual void Warn(std::string_view s) = 0;
    virtual void Error(std::string_view s) = 0;
};

enum LoggerType
{
    QtLogger
};

std::shared_ptr<ILogger> logger_factory(LoggerType loggerType);
} // namespace Logger