#pragma once

#include "Logger/ILogger.hpp"
#include <queue>
#include <string>
#include <string_view>
#include <vector>

namespace Logger
{
class NullLogger : public ILogger
{
  public:
    using MessageOutputType = std::vector<std::string>;
    enum class LogLevel : uint8_t
    {
        Debug = 4,
        Info = 3,
        Warn = 2,
        Error = 1
    };

    NullLogger(LogLevel logLevel = LogLevel::Info, size_t nMessages = 10);
    ~NullLogger() = default;
    void Debug(std::string_view s) override;
    void Info(std::string_view s) override;
    void Warn(std::string_view s) override;
    void Error(std::string_view s) override;

    MessageOutputType Messages();

  private:
    std::queue<std::string> _messages;
    size_t _nMessages;

    LogLevel _logLevel;

    void _addMessage(std::string_view, LogLevel logLevel);
    std::string _formatMessage(std::string_view s, LogLevel logLevel);
};
} // namespace Logger