#pragma once

#include "Logger/ILogger.hpp"

namespace Logger
{
class QtLogger : public ILogger
{
  public:
    QtLogger() = default;
    ~QtLogger() = default;
    void Debug(std::string_view s) override;
    void Info(std::string_view s) override;
    void Warn(std::string_view s) override;
    void Error(std::string_view s) override;
};
} // namespace Logger