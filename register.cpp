#include "register.h"

Register::Register(QObject *parent) : HttpRequestHandler(parent)
{

}

void Register::service(HttpRequest &request, HttpResponse &response)
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
    QString useid=obj.value("useid").toString();
    QString passwd=obj.value("passwd").toString();
    QString mail=obj.value("mail").toString();
    QString code=obj.value("code").toString();
    if(database->userdata.count(useid)!=0){
        response.setStatus(403);
        response.write("",true);//该账号已经注册
    }
    if(code!=database->pc_mail_vericode.value(mail)){
        response.setStatus(403);
        response.write("1",true);//验证码错误
    }
    database->phonebool.insert(useid,false);
    QVector<QString> temp;
    temp.push_back(passwd);
    temp.push_back(mail);
    database->userdata.insert(useid,temp);
    auto it=database->pc_mail_vericode[mail]="";
    response.setStatus(200);
  //  response.setHeader("Content-Type","application/json;charset=UTF-8");
    response.write("register success!",true);
    return;


}
