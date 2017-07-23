#include "cpulist.h"

CPUList::CPUList(QObject *parent) : QObject(parent)
{

}


CPUList::~CPUList()
{
    m_processorList.clear();
}


void CPUList::setCPUList(QList<CPUInfo *> list)
{
    for (int i=0; i<list.size(); i++)
    {
        m_processorList.append(list.at(i));

    }
}


int CPUList::getProcessorCount() const
{
    return m_processorList.count();
}


CPUInfo* CPUList::getCPUInfoAt(int index) const
{
    return m_processorList.at(index);
}


 QQmlListProperty<CPUInfo> CPUList::getProcessorList()
 {
     return  QQmlListProperty<CPUInfo>(this, m_processorList);

 }


 QString CPUList::getCount()
 {
     QString str = QString::number(m_processorList.count());
     return str;


 }
