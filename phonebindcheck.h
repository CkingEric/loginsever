#ifndef PHONEBINDCHECK_H
#define PHONEBINDCHECK_H

#include <QObject>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonParseError>
#include<QJsonArray>
#include<QJsonValue>

#include"singletondata.h"
#include "httprequesthandler.h"

using namespace stefanfrings;

class Phonebindcheck : public HttpRequestHandler
{
    Q_OBJECT
public:
    explicit Phonebindcheck(QObject *parent = nullptr);
    void service(HttpRequest& request, HttpResponse& response);

signals:

};

#endif // PHONEBINDCHECK_H
