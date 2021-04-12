#include "phonebindcheck.h"

Phonebindcheck::Phonebindcheck(QObject *parent) : HttpRequestHandler(parent)
{

}

void Phonebindcheck::service(HttpRequest &request, HttpResponse &response)
{
    if(request.getMethod()!="POST"){
        response.setStatus(405);
        response.write("method is error!",true);
        return;
    }
    QJsonParseError jp;
    QByteArray s=request.getBody();
    QJsonDocument JD=QJsonDocument::fromJson(s,&jp);
    if(jp.error != QJsonParseError::NoError)
    {
          qDebug() << "json init error!";
    }

    SingletonData* database=SingletonData::instance();
    QJsonObject obj=JD.object();
    QString token=obj.value("token").toString();
    QString code=obj.value("code").toString();
    if(code==database->phone_token_vericode.value(token)){
        response.setStatus(200);
        response.write("",true);
        return;
    }else {
        response.setStatus(403);
        response.write("",true);
        return;
}

}
