#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QEventLoop>
#include <QMetaEnum>

class Manager : public QObject
{
    Q_OBJECT
public:
    explicit Manager(QObject *parent = nullptr);

signals:

private:
    QNetworkAccessManager manager;
    QEventLoop loop;
};

#endif // MANAGER_H
