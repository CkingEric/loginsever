#ifndef REGISTER_H
#define REGISTER_H

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

class Register : public HttpRequestHandler
{
    Q_OBJECT
public:
    explicit Register(QObject *parent = nullptr);
    void service(HttpRequest& request, HttpResponse& response);

signals:

};

#endif // REGISTER_H
