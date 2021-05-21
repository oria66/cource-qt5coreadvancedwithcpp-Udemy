#ifndef FILEDIRMANAGER_H
#define FILEDIRMANAGER_H

#include <QObject>
#include <QDir>
#include <QFutureWatcher>

class FileDirManager : public QObject
{
    Q_OBJECT
public:
    explicit FileDirManager(QObject *parent = nullptr);

    void setSourceDir(const QDir &newSourceDir);

    void showEntryListRecursively();

signals:

private:
    static QStringList _getAllStringPathFiles(const QDir &directory);

    QDir sourceDir;

    QFuture<QStringList> future;
    QFutureWatcher<QStringList> futureWatcher;
};

#endif // FILEDIRMANAGER_H
