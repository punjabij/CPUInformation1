#include "filemanager.h"
#include "constantslist.h"

#include <QObject>


#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>

FileManager::FileManager(QObject *parent) : QObject(parent)
{

}


FileManager::~FileManager()
{

}

bool FileManager::readFile(const QString& fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return false;

    QTextStream in(&file);
    fileContents = in.readAll();

//    qDebug() << fileContents;
//    int size = fileContents.size();
//    qDebug() << size;

    return true;
}


qint32 FileManager::getProcessorCount()
{
    if (fileContents != NULL)
    {
        processorCount = fileContents.count(ProcesssorParameter);
//        qDebug() << processorCount;

//        if (processorCount > 0)
//        {

//            for( int i = 0; i < processorCount; i++)
//            CPUInfo* cpuInfo = new CPUInfo;

//        }


//        QString title =  "Processor count";
//        QString message = "No processor data found!";
//        if (processorCount > 0)
//        {
//            message = QString::number(processorCount);
//        }

//        QMessageBox msgBox(parent);
//        msgBox.setText(title);
//        msgBox.setInformativeText(message);
//        msgBox.setStandardButtons(QMessageBox::Ok);
//        msgBox.setDefaultButton(QMessageBox::Save);
//        int ret = msgBox.exec();

    }

    return processorCount;
}


QString& FileManager::getFileContents()
{
    return fileContents;
}
