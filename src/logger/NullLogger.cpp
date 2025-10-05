#include "logger/NullLogger.hpp"

Logger::NullLogger::NullLogger(Logger::NullLogger::LogLevel logLevel, size_t nMessages)
{
    _nMessages = nMessages;
    _messages = std::queue<std::string>();
    _logLevel = logLevel;
}

void Logger::NullLogger::Debug(std::string_view s)
{
    if (_logLevel >= Logger::NullLogger::LogLevel::Debug)
    {
        _addMessage(s, Logger::NullLogger::LogLevel::Debug);
    }
}

void Logger::NullLogger::Info(std::string_view s)
{
    if (_logLevel >= Logger::NullLogger::LogLevel::Info)
    {
        _addMessage(s, Logger::NullLogger::LogLevel::Info);
    }
}

void Logger::NullLogger::Warn(std::string_view s)
{
    if (_logLevel >= Logger::NullLogger::LogLevel::Warn)
    {
        _addMessage(s, Logger::NullLogger::LogLevel::Warn);
    }
}

void Logger::NullLogger::Error(std::string_view s)
{
    if (_logLevel >= Logger::NullLogger::LogLevel::Error)
    {
        _addMessage(s, Logger::NullLogger::LogLevel::Error);
    }
}

void Logger::NullLogger::_addMessage(std::string_view message, Logger::NullLogger::LogLevel logLevel)
{
    std::string formattedMessage = _formatMessage(message, logLevel);
    if (_messages.size() < _nMessages)
    {
        _messages.push(formattedMessage);
    }
    else
    {
        _messages.pop();
        _messages.push(formattedMessage);
    }
}

Logger::NullLogger::MessageOutputType Logger::NullLogger::Messages()
{
    std::vector<std::string> result;
    size_t N = _messages.size();
    for (size_t i = 0; i < N; i++)
    {
        result.push_back(_messages.front());
        _messages.pop();
    }
    return result;
}

std::string Logger::NullLogger::_formatMessage(std::string_view s, Logger::NullLogger::LogLevel logLevel)
{
    switch (logLevel)
    {
    case Logger::NullLogger::LogLevel::Debug:
        return "[Debug]  " + std::string(s);
    case Logger::NullLogger::LogLevel::Info:
        return "[Info ]  " + std::string(s);
    case Logger::NullLogger::LogLevel::Warn:
        return "[Warn ]  " + std::string(s);
    case Logger::NullLogger::LogLevel::Error:
        return "[Error]  " + std::string(s);
    default:
        throw std::runtime_error("Unhandled log level in _formatMessage");
        break;
    }
}