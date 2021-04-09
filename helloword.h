#ifndef HELLOWORD_H
#define HELLOWORD_H

#include <QObject>
#include "httprequesthandler.h"
#include "util.h"


using namespace stefanfrings;

class HelloWord : public HttpRequestHandler
{
    Q_OBJECT
public:
    explicit HelloWord(QObject *parent = nullptr);
    void service(HttpRequest& request, HttpResponse& response);

signals:

};

#endif // HELLOWORD_H
