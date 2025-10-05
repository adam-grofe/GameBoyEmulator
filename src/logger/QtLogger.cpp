
#include "logger/QtLogger.hpp"
#include <QDebug>
#include <QtLogging>

void Logger::QtLogger::Debug(std::string_view s)
{
    qDebug() << QString::fromUtf8(s.data(), s.size());
}

void Logger::QtLogger::Info(std::string_view s)
{
    qInfo() << QString::fromUtf8(s.data(), s.size());
}

void Logger::QtLogger::Warn(std::string_view s)
{
    qWarning() << QString::fromUtf8(s.data(), s.size());
}

void Logger::QtLogger::Error(std::string_view s)
{
    qCritical() << QString::fromUtf8(s.data(), s.size());
}