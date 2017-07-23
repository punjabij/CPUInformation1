#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickView>
#include <QQmlComponent>

#include "filemanager.h"
#include "infomanager.h"
#include "cpulist.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    FileManager fileManager;

    if ( fileManager.readFile("/proc/cpuinfo") )
    {
        qint32 processorCount = fileManager.getProcessorCount();

        if ( processorCount > 0 )
        {
            InfoManager infoManager;
//            infoManager.setCPURawData(fileManager.getFileContents());
            infoManager.parseCPURawData(processorCount, fileManager.getFileContents());

            CPUList cpuList;
            cpuList.setCPUList(infoManager.getProcessorList());

            //![register list]
                qmlRegisterType<CPUList>("CPUDetails", 1,0, "CPUList");
                qmlRegisterType<CPUInfo>("CPUDetails", 1,0, "CPUInfo");
            //![register list]
            //!
            //!
            //!
              int rc = 0;
              QQmlEngine engine;
              QQmlComponent *component = new QQmlComponent(&engine);
              component->loadUrl(QUrl("qrc:/main.qml"));

              if (!component->isReady() ) {
                  qWarning("%s", qPrintable(component->errorString()));
                  return -1;
              }

              QObject *topLevel = component->create();
              QQuickWindow *window = qobject_cast<QQuickWindow *>(topLevel);

              QSurfaceFormat surfaceFormat = window->requestedFormat();
              window->setFormat(surfaceFormat);
              window->show();

              rc = app.exec();

              delete component;
              return rc;

//            QList<QObject*> dataList;
//            QList<CPUInfo*> procList = infoManager.getProcessorList();
//            for (int i = 0; i<procList.size(); i++){
//                dataList.append(procList.at(i));
//            }


//            engine.rootContext()->setContextProperty("procModel", QVariant::fromValue(dataList));

//            QQuickView view;
//            view.setResizeMode(QQuickView::SizeRootObjectToView);
//            QQmlContext *ctxt = view.rootContext();
//            ctxt->setContextProperty("procModel", QVariant::fromValue(dataList));

//            view.setSource(QUrl("qrc:/main.qml"));
//            view.show();

        }

    }

//    QQmlApplicationEngine engine;
//    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

