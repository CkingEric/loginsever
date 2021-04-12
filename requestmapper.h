#ifndef REQUESTMAPPER_H
#define REQUESTMAPPER_H

#include <QObject>
#include"singletondata.h"
#include "httprequesthandler.h"
#include"pclogin.h"
#include"dynpasscheck.h"
#include"phonelogin.h"
#include"stmpcheck.h"
#include"register.h"
#include "phonebindcheck.h"
#include"helloword.h"


class RequestMapper :public HttpRequestHandler
{
public:
    explicit RequestMapper(QObject *parent = nullptr);
    void service(HttpRequest& request, HttpResponse& response);

signals:


private:
     PcLogin pclogin;
     Dynpasscheck dynpasscheck;
     PhoneLogin phonelogin;
     StmpCheck stmpcheck;
     Register registers;
     HelloWord hello;
     Phonebindcheck bindcheck;
};

#endif // REQUESTMAPPER_H
