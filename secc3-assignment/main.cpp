#include <QCoreApplication>
#include "libraryforsecc3.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    LibraryForSecc3 lib;

    qDebug() << lib.functionReturnOne();
    qDebug() << lib.functionReturnTwo();

    return a.exec();
}
