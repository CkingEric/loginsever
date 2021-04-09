#ifndef PHONELOGIN_H
#define PHONELOGIN_H

#include <QObject>
#include<QVector>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonParseError>
#include<QJsonArray>
#include<QJsonValue>
#include<QUuid>
#include"singletondata.h"
#include "httprequesthandler.h"


using namespace stefanfrings;

class PhoneLogin : public HttpRequestHandler
{
    Q_OBJECT
public:
    explicit PhoneLogin(QObject *parent = nullptr);
    void service(HttpRequest& request, HttpResponse& response);

signals:

};

#endif // PHONELOGIN_H
