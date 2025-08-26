
#include <QtLogging>
#include <QDebug>
#include "logger/QtLogger.hpp"


void Logger::QtLogger::Debug(std::string_view s){
    qDebug() << s;
}

void Logger::QtLogger::Info(std::string_view s) {
    qInfo() << s;
}

void Logger::QtLogger::Warn(std::string_view s) {
    qWarning() << s;
}

void Logger::QtLogger::Error(std::string_view s) {
    qFatal() << s;
}