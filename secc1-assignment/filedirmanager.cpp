#include "filedirmanager.h"

FileDirManager::FileDirManager(QObject *parent) : QObject(parent)
{

}

void FileDirManager::setSourceDir(const QDir &newSourceDir)
{
    sourceDir = newSourceDir;
}
