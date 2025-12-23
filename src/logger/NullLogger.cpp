#include "logger/NullLogger.hpp"

Logger::NullLoggerImpl::NullLoggerImpl(Logger::NullLoggerImpl::LogLevel logLevel, size_t nMessages)
{
    _nMessages = nMessages;
    _messages = std::queue<std::string>();
    _logLevel = logLevel;
}

void Logger::NullLoggerImpl::Debug(std::string_view s)
{
    if (_logLevel >= Logger::NullLoggerImpl::LogLevel::Debug)
    {
        _addMessage(s, Logger::NullLoggerImpl::LogLevel::Debug);
    }
}

void Logger::NullLoggerImpl::Info(std::string_view s)
{
    if (_logLevel >= Logger::NullLoggerImpl::LogLevel::Info)
    {
        _addMessage(s, Logger::NullLoggerImpl::LogLevel::Info);
    }
}

void Logger::NullLoggerImpl::Warn(std::string_view s)
{
    if (_logLevel >= Logger::NullLoggerImpl::LogLevel::Warn)
    {
        _addMessage(s, Logger::NullLoggerImpl::LogLevel::Warn);
    }
}

void Logger::NullLoggerImpl::Error(std::string_view s)
{
    if (_logLevel >= Logger::NullLoggerImpl::LogLevel::Error)
    {
        _addMessage(s, Logger::NullLoggerImpl::LogLevel::Error);
    }
}

void Logger::NullLoggerImpl::_addMessage(std::string_view message, Logger::NullLoggerImpl::LogLevel logLevel)
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

Logger::NullLoggerImpl::MessageOutputType Logger::NullLoggerImpl::Messages()
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

std::string Logger::NullLoggerImpl::_formatMessage(std::string_view s, Logger::NullLoggerImpl::LogLevel logLevel)
{
    switch (logLevel)
    {
    case Logger::NullLoggerImpl::LogLevel::Debug:
        return "[Debug]  " + std::string(s);
    case Logger::NullLoggerImpl::LogLevel::Info:
        return "[Info ]  " + std::string(s);
    case Logger::NullLoggerImpl::LogLevel::Warn:
        return "[Warn ]  " + std::string(s);
    case Logger::NullLoggerImpl::LogLevel::Error:
        return "[Error]  " + std::string(s);
    default:
        throw std::runtime_error("Unhandled log level in _formatMessage");
        break;
    }
}