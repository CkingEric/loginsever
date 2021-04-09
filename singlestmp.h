#ifndef SINGLESTMP_H
#define SINGLESTMP_H
#include<QByteArray>
#include<QString>
#include<QTcpSocket>
#include<QHostAddress>


class SingleStmp
{
public:
    static SingleStmp* instance();
    void send(QByteArray recvaddr,QString subject,QString content);
    ~SingleStmp();

private:
    SingleStmp();
    static SingleStmp* _instance;
    QTcpSocket *clientsocket;
    QByteArray username;
    QByteArray password;
    QByteArray recvaddr;
    QByteArray mailfrom = "mail from:<";
    QByteArray rcptto = "rcpt to:<";
    QByteArray prefrom = "from:";
    QByteArray preto = "to:";
    QByteArray presubject ="subject:";
    QString subject;                //主题
    QString content;                //发送内容
    QByteArray recvdata;            //接收到的数据
};

#endif // SINGLESTMP_H
