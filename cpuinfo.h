#ifndef CPUINFO_H
#define CPUINFO_H

#include <QObject>
#include <QStringList>




class CPUInfo : public QObject
{
    Q_OBJECT


    Q_PROPERTY(QString processorId READ processorId WRITE setProcessorId NOTIFY processorId_changed )
    Q_PROPERTY(QString cpuFrequencyMHz READ cpuFrequency NOTIFY cpuFrequency_changed)

public:
    explicit CPUInfo(QObject *parent = 0);

    QString processorId() const;
    void setProcessorId(const QString &processorId);

//    void setVendorId(qint32 vendorId);
//    void setcpuFamily(qint32 cpuFamily);
//    void setModel(qint32 model);processorId_changed
//    void setMicrocode(const QString& microcode);

    QString cpuFrequency() const;
    void setCpuFrequency(const QString &cpuFrequencyMHz);

signals:
    void processorId_changed();
    void cpuFrequency_changed();

public slots:

private:
    QString m_processorId;
//    QString name;
//    QString value;
//    QString vendorId;
//    qint32 cpuFamily;
//    qint32 model;
//    QString modelName;
//    QString microcode;
    QString m_cpuFrequencyMHz;

//    qint32 cacheKB;
//    qint32 physicalId;
//    qint32 siblings;
//    qint32 coreId;
//    qint32 cpuCores;
//    qint32 apicid;
//    qint32 initApicid;
//    bool fpu;
//    bool fpu_exception;
//    qint32 cpuIdLevel;
//    bool wp;
//    QStringList flags;
//    float bogomips;
//    qint32 clflushSize;
//    qint32 cacheAlignment;
//    QString addressSize_PhysicalInBits;
//    QString addressSize_VirtualInBits;
//    QString powerManagement;

};

#endif // CPUINFO_H
