#include "stmpcheck.h"

StmpCheck::StmpCheck(QObject *parent) : HttpRequestHandler(parent)
{

}

void StmpCheck::service(HttpRequest &request, HttpResponse &response)
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
    int type=obj.value("type").toInt();//type 0 pc 1 phone
    QString mailaddress=obj.value("mail").toString();
    if(type==0){
        if(database->pc_mail_vericode.count(mailaddress)!=0){
            response.setStatus(403);
            response.write("mailaddress has been register",true);
        }
        QString code=utill::randomcode();
        SingleStmp::instance()->send(mailaddress.toLatin1(),"邮箱验证",QString("邮箱验证码为%1，请尽快绑定!").arg(code));
        database->pc_mail_vericode.insert(mailaddress,code);
        response.write("send mail success",true);
    }
    if(type==1){
        QString token=obj.value("token").toString();
        QString code=utill::randomcode();
        SingleStmp::instance()->send(mailaddress.toLatin1(),"手机令牌绑定",QString("验证码为%1，请尽快绑定!").arg(code));
        database->phone_token_vericode.insert(token,code);
        response.write("send mail success",true);
    }
    response.write("test",true);
    return;

}
