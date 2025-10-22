#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "CppWorker.h"
#include "CppSignalSender.h"
#include "Movie.h"
#include "PropertyWrapper.h"
#include "QmlJSCaller.h"

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
    //engine.rootContext()->setContextProperty("Movie", &movie);

    qmlRegisterType<Movie>("com.example.movie", 1, 0, "Movie");

    /*
    QString lastName = "Doe";
    QString firstName = "John";

    engine.rootContext()->setContextProperty("lastname", QVariant::fromValue(lastName));
    engine.rootContext()->setContextProperty("firstname", QVariant::fromValue(firstName));*/

    PropertyWrapper wrapper;
    wrapper.setLastname("Doe");
    wrapper.setFirstname("John");

    engine.rootContext()->setContextObject(&wrapper);

    QmlJSCaller qmlJSCaller;
    engine.rootContext()->setContextProperty("QmlJSCaller", &qmlJSCaller);

    auto root = engine.rootObjects();
    if (!root.empty())
    {
        qmlJSCaller.setQmlRootObject(root.first());
    }

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
