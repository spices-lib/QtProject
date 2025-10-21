#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "CppWorker.h"
#include "CppSignalSender.h"
#include "Movie.h"

int main(int argc, char *argv[])
{
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));

    QGuiApplication app(argc, argv);

    CppWorker cppWorker;
    CppSignalSender sender;
    Movie movie;
    movie.setTitle("Golden");
    movie.setMainCharacter("Rumi");

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("BWorker", &cppWorker);
    engine.rootContext()->setContextProperty("CppSignalSender", &sender);
    engine.rootContext()->setContextProperty("Movie", &movie);

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
