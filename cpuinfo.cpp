#include "cpuinfo.h"

CPUInfo::CPUInfo(QObject *parent) : QObject(parent)
{

}


QString CPUInfo::processorId() const
{
    return m_processorId;
}

QString CPUInfo::cpuFrequency() const
{
    return m_cpuFrequencyMHz;
}


void CPUInfo::setProcessorId(const QString &processorId)
{
    if(processorId != m_processorId) {
        m_processorId = processorId;
        emit processorId_changed();
    }
}


void CPUInfo::setCpuFrequency(const QString &cpuFrequencyMHz)
{
     if(cpuFrequencyMHz != m_cpuFrequencyMHz)
        m_cpuFrequencyMHz = cpuFrequencyMHz;
        emit cpuFrequency_changed();
}

// void CPUInfo::setVendorId(qint32 vendorId)
// {
//     this->vendorId = vendorId;
// }

// void CPUInfo::setcpuFamily(qint32 cpuFamily)
// {
//     this->cpuFamily = cpuFamily;
// }

// void CPUInfo::setModel(qint32 model)
// {
//     this->model = model;
// }

// void CPUInfo::setMicrocode(const QString& microcode)
// {
//     this->microcode = microcode;
// }



// void CPUInfo::setProcessorId(qint32 processorId)
// {
//     this->processorId = processorId;
// }
