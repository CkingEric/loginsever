#include "phonebindcheck.h"

Phonebindcheck::Phonebindcheck(QObject *parent) : HttpRequestHandler(parent)
{

}

void Phonebindcheck::service(HttpRequest &request, HttpResponse &response)
{
    if(request.getMethod()!="POST"){
        response.setStatus(405);
        response.write("method is error!",true);
    }
    QJsonParseError jp;
    QByteArray s=request.getBody();
    QJsonDocument JD=QJsonDocument::fromJson(s,&jp);
    if(jp.error != QJsonParseError::NoError)
    {
          qDebug() << "json init error!";
    }

    SingletonData* database=SingletonData::instance();
}
