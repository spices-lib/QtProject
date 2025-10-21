#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "CppWorker.h"
#include "CppSignalSender.h"

int main(int argc, char *argv[])
{
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));

    QGuiApplication app(argc, argv);

    CppWorker cppWorker;
    CppSignalSender sender;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("BWorker", &cppWorker);
    engine.rootContext()->setContextProperty("CppSignalSender", &sender);

    QObject::connect(
            &engine,
            &QQmlApplicationEngine::objectCreationFailed,
            &app,
            []() {
                qDebug() <<  "QML object creation failed!";
                QCoreApplication::exit(-1);
            },
            Qt::QueuedConnection);
    engine.loadFromModule("QtProject", "Main");

    return app.exec();
}
