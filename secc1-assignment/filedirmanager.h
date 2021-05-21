#ifndef FILEDIRMANAGER_H
#define FILEDIRMANAGER_H

#include <QObject>
#include <QDir>

class FileDirManager : public QObject
{
    Q_OBJECT
public:
    explicit FileDirManager(QObject *parent = nullptr);

    void setSourceDir(const QDir &newSourceDir);

signals:

private:
    QDir sourceDir;
};

#endif // FILEDIRMANAGER_H
