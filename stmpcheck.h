#ifndef STMPCHECK_H
#define STMPCHECK_H

#include <QObject>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonParseError>
#include<QJsonArray>
#include<QJsonValue>
#include<QUuid>
#include<QDateTime>
#include<QTimer>
#include"singletondata.h"
#include "httprequesthandler.h"

using namespace stefanfrings;


class StmpCheck : public HttpRequestHandler
{
    Q_OBJECT
public:
    explicit StmpCheck(QObject *parent = nullptr);
    void service(HttpRequest& request, HttpResponse& response);

signals:

};

#endif // STMPCHECK_H
