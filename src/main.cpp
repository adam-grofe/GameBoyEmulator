
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <iostream>

int main(int argc, char *argv[])
{
    std::cout << "Pre\n";

    QGuiApplication app(argc, argv);

    qDebug() << "Starting\n";

    QQmlApplicationEngine engine;
    const auto url = QUrl(QStringLiteral("qrc:/qt/qml/app/src/main.qml"));
    qDebug() << "Loading QML from : " << url.toString() << "\n";
    engine.load(url);

    qDebug() << "QML Loaded\n";

    if (engine.rootObjects().isEmpty())
        return -1;

    qDebug() << "App executing\n";

    return app.exec();
}
