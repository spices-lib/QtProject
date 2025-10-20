#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "CppWorker.h"

int main(int argc, char *argv[])
{
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));

    QGuiApplication app(argc, argv);

    CppWorker cppWorker;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("BWorker", &cppWorker);

    QObject::connect(
            &engine,
            &QQmlApplicationEngine::objectCreationFailed,
            &app,
            []() { QCoreApplication::exit(-1); },
            Qt::QueuedConnection);
    engine.loadFromModule("QtProject", "Main");

    return app.exec();
}
