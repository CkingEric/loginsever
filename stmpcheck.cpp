#include "stmpcheck.h"

StmpCheck::StmpCheck(QObject *parent) : HttpRequestHandler(parent)
{

}

void StmpCheck::service(HttpRequest &request, HttpResponse &response)
{
    auto time1=QDateTime::currentMSecsSinceEpoch() / 60000;
    auto time2=time1-1;
    QString timeString1 = QString::number(time1);
    QString timeString2 = QString::number(time2);
    qDebug()<<timeString1;
    qDebug()<<timeString2;
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
    QJsonObject obj=JD.object();
    int type=obj.value("type").toInt();//type 0 pc 1 phone
    if(type==0){

    }
    if(type==1){

    }
    response.write("test",true);
    return;

}
