#ifndef INFOMANAGER_H
#define INFOMANAGER_H


#include "cpuinfo.h"


#include <QObject>
#include <QList>

#include <QObject>

class InfoManager : public QObject
{
    Q_OBJECT
public:
    explicit InfoManager(QObject *parent = 0);
    ~InfoManager();

//    void setCPURawData(const QString& cpuData);

    void parseCPURawData(qint32 processorCount, const QString& cpuData);
    QList<CPUInfo*> getProcessorList();

signals:

public slots:

private:
    void setCPUInfoValues(CPUInfo* singleCPUInfo, QString& singleCPUData);


//    QString cpuData;
    QList<CPUInfo*> processorList;
};

#endif // INFOMANAGER_H
