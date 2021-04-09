#ifndef PCLOGIN_H
#define PCLOGIN_H

#include <QObject>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonParseError>
#include<QJsonArray>
#include<QJsonValue>
#include<QUuid>
#include"singletondata.h"
#include "httprequesthandler.h"


using namespace stefanfrings;

class PcLogin : public HttpRequestHandler
{
    Q_OBJECT
public:
    explicit PcLogin(QObject *parent = nullptr);
    void service(HttpRequest& request, HttpResponse& response);

signals:

};

#endif // PCLOGIN_H
