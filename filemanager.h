#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QObject>

class FileManager : public QObject
{
    Q_OBJECT
public:
    explicit FileManager(QObject *parent = 0);
    ~FileManager();

    bool readFile(const QString& fileName);

    qint32 getProcessorCount();

    qint32 parseFileContents();

    QString& getFileContents();

signals:

public slots:

private:

    QString fileContents;
    qint32 processorCount;




};

#endif // FILEMANAGER_H
