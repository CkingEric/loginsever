#ifndef SINGLETONDATA_H
#define SINGLETONDATA_H
#include<QMap>
#include<QVector>
#include<QString>


class SingletonData
{
public:
    static SingletonData* instance();
    QMap<QString,QVector<QString>>userdata;
    QMap<QString,bool>phonebool;
    QMap<QString,QString>pclogintoken;
    QMap<QString,QString>phonelogintoken;
    QMap<QString,QString>pc_mail_vericode;
    QMap<QString,QString>phone_token_vericode;
    QMap<QString,QString>useid_phoneuuid;
    QMap<QString,QString>pctoken_uuid;
    QMap<QString,QString>regitertoken_mailcode;


private:
    explicit SingletonData();
    static SingletonData* _instance;
};

#endif // SINGLETONDATA_H
