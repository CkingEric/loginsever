#include "pclogin.h"

PcLogin::PcLogin(QObject *parent) : HttpRequestHandler(parent)
{

}

void PcLogin::service(HttpRequest &request, HttpResponse &response)
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
    QJsonObject obj=JD.object();
    QString useid=obj.value("useid").toString();
    QString passwd=obj.value("passwd").toString();
    if(database->userdata.count(useid)!=0){
        QVector<QString> usedata=database->userdata.value(useid);
        if(passwd==usedata[0]){
            response.setStatus(200);
            QString token=QUuid::createUuid().toString();
            database->pclogintoken.insert(useid,token);
            QJsonObject resobj;
            resobj.insert("mail",QJsonValue(usedata[1]));
            resobj.insert("token",QJsonValue(token));
            QJsonDocument resJD(resobj);
            QByteArray resbyte=resJD.toJson();
            response.write(resbyte,true);
        }
    }
    response.setStatus(403);
    response.write("error",true);

}
