#include "infomanager.h"
#include "constantslist.h"

#include <QDebug>

InfoManager::InfoManager(QObject *parent) : QObject(parent)
{

}

InfoManager::~InfoManager()
{
    processorList.clear();
}



//void InfoManager::setCPURawData(const QString& rawCPUData)
//{
//    cpuData = rawCPUData;
//}


void InfoManager::setCPUInfoValues(CPUInfo* singleCPUInfo, QString& singleCPUData)
{
    QStringList cpuDatalist = singleCPUData.split('\n');

//    Parse processor id
    QStringList processorId = cpuDatalist.filter(ProcesssorParameter);
    singleCPUInfo->setProcessorId((processorId.at(0).mid((processorId.at(0).indexOf(':')) + 1)).trimmed());

//    Parse processor frequency
    QStringList processorFrequency = cpuDatalist.filter(CPUFrequencyMHz);
    singleCPUInfo->setCpuFrequency((processorFrequency.at(0).mid((processorFrequency.at(0).indexOf(':')) + 1)).trimmed());

//            QString str = ;
//            qDebug() << str;



//    qint32 index1 = singleCPUData.indexOf(ProcesssorParameter);
//    QString temp = singleCPUData.right(ProcesssorParameter.length());
//    bool isOk;
//    qint32 id = (temp.trimmed()).toInt(&isOk);
//    qDebug() << nameValue;
//    singleCPUInfo->setProcessorId(temp.trimmed().toInt(isOk));


}


void InfoManager::parseCPURawData(qint32 processorCount, const QString& cpuData)
{
    QString remainingCpuData = cpuData;
    qDebug() << remainingCpuData;

    for (int i=0; i<processorCount; i++)
    {
        qint32 startSingleCPUSection = remainingCpuData.indexOf(ProcesssorParameter);
        qint32 endSingleCPUSection =  remainingCpuData.indexOf(ProcesssorParameter, startSingleCPUSection + 1);

        QString singleCPUData = remainingCpuData.mid(startSingleCPUSection, endSingleCPUSection);
        qDebug() << singleCPUData;

        CPUInfo* singleCPUInfo = new CPUInfo();

        setCPUInfoValues(singleCPUInfo, singleCPUData);

        processorList.append(singleCPUInfo);

        remainingCpuData = remainingCpuData.mid(endSingleCPUSection);
        qDebug() << remainingCpuData;
    }
}


QList<CPUInfo*> InfoManager::getProcessorList()
{
    return processorList;
}

