#ifndef CPULIST_H
#define CPULIST_H

#include "cpuinfo.h"

#include <QObject>
#include <QList>
#include <QQmlListProperty>



class CPUList : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QQmlListProperty<CPUInfo> processorList READ getProcessorList)
    Q_PROPERTY(QString count READ getCount)

public:
    explicit CPUList(QObject *parent = 0);
    ~CPUList();

    void setCPUList(QList<CPUInfo*> list);

    QQmlListProperty<CPUInfo> getProcessorList();
    int getProcessorCount() const;
    CPUInfo* getCPUInfoAt(int index) const;

    QString getCount();

signals:

public slots:

private:
     QList<CPUInfo*> m_processorList;
     int count;
};

#endif // CPULIST_H
