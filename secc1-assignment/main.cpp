#include <QCoreApplication>
#include "filedirmanager.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    FileDirManager dirManager;
    dirManager.setSourceDir(QDir::currentPath());

    dirManager.showEntryListRecursively();

    return a.exec();
}
