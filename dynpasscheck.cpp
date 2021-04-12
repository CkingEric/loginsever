#include "dynpasscheck.h"

Dynpasscheck::Dynpasscheck(QObject *parent) : HttpRequestHandler(parent)
{

}

void Dynpasscheck::service(HttpRequest &request, HttpResponse &response)
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
    QString pctoken=obj.value("token").toString();
    QString dynpass=obj.value("dynpass").toString();
    QString phoneuuid=database->pctoken_uuid.value(pctoken);
    QString hashinput=timeString1.append(phoneuuid);
    QString severcheckdyn1=QCryptographicHash::hash(hashinput.toLatin1(),QCryptographicHash::Md5).toHex();
    if(severcheckdyn1==dynpass){
        response.write("dynpass check success!",true);
        return;
    }
    hashinput=timeString2.append(phoneuuid);
    QString severcheckdyn2=QCryptographicHash::hash(hashinput.toLatin1(),QCryptographicHash::Md5).toHex();
    if(severcheckdyn2==dynpass){
        response.write("dynpass check success!",true);
        return;
    }
    response.setStatus(403);
    response.write("check failed!",true);
}
