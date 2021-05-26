#include "manager.h"

Manager::Manager(QObject *parent) : QObject(parent)
{
    QUrl url;
    url.setScheme("https");
    url.setHost("postman-echo.com");
    url.setPath("/get");

    QNetworkRequest request;
    request.setUrl(url);

    QNetworkReply *reply = manager.get(request);

    connect(reply, &QNetworkReply::finished,[=](){

        loop.quit();

        QMetaEnum metaEnum = QMetaEnum::fromType<QNetworkReply::NetworkError>();

        qDebug() << "Error" << metaEnum.valueToKey(reply->error());
        qDebug() << reply->readAll();

    });

    loop.exec();
}
