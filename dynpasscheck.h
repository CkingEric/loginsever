#ifndef DYNPASSCHECK_H
#define DYNPASSCHECK_H

#include <QObject>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonParseError>
#include<QJsonArray>
#include<QJsonValue>
#include<QUuid>
#include<QDateTime>
#include<QTimer>
#include <QCryptographicHash>

#include"singletondata.h"
#include "httprequesthandler.h"


using namespace stefanfrings;

class Dynpasscheck : public HttpRequestHandler
{
    Q_OBJECT
public:
    explicit Dynpasscheck(QObject *parent = nullptr);
    void service(HttpRequest& request, HttpResponse& response);

signals:

};

#endif // DYNPASSCHECK_H
