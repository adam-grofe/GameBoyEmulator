
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QString>
#include <iostream>

#include "logger/ILogger.hpp"

int main(int argc, char* argv[])
{
    auto logger = Logger::logger_factory(Logger::QtLogger);
    logger->Debug("Pre");

    QGuiApplication app(argc, argv);

    logger->Debug("Starting");

    QQmlApplicationEngine engine;
    const auto url = QUrl(QStringLiteral("qrc:/qt/qml/app/src/main.qml"));
    logger->Debug("Loading QML from : " + url.toString().toStdString());
    engine.load(url);

    logger->Debug("QML Loaded");

    if (engine.rootObjects().isEmpty())
        return -1;

    logger->Debug("App executing");

    return app.exec();
}
