#include "manager.h"
#include <QUrlQuery>

Manager::Manager(QObject *parent) : QObject(parent)
{
    QUrlQuery query;
    query.addQueryItem("page", "2");

    QUrl url;
    url.setScheme("https");
    url.setHost("reqres.in");
    url.setPath("/api/users");
    url.setQuery(query);

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
