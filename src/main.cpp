#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "CppWorker.h"

int main(int argc, char *argv[])
{
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));

    QGuiApplication app(argc, argv);

    CppWorker* cppWorker = new CppWorker();

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("BWorker", cppWorker);

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

    int result = app.exec();

    delete cppWorker;
    return result;
}
