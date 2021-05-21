#include "filedirmanager.h"
#include <QDirIterator>
#include <QDebug>
#include <QtConcurrent>
#include <QStringList>

FileDirManager::FileDirManager(QObject *parent) : QObject(parent)
{
    futureWatcher.setFuture(future);

    connect(&futureWatcher, &QFutureWatcherBase::finished, [=](){

        qInfo() << "End process: ";

        qInfo() << future.result();

    });
}

void FileDirManager::setSourceDir(const QDir &newSourceDir)
{
    sourceDir = newSourceDir;
}

void FileDirManager::showEntryListRecursively()
{
    qInfo() << "Begin to process: ";
    future = QtConcurrent::run(&FileDirManager::_getAllStringPathFiles, sourceDir);
}

QStringList FileDirManager::_getAllStringPathFiles(const QDir &directory)
{
    QStringList list;

    QDirIterator it(directory, QDirIterator::Subdirectories);
    while (it.hasNext()) {
        list << it.next();
    }

    return list;
}
