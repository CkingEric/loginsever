#include"util.h"

QString utill::randomcode()
{

    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    auto i=qrand()%10000;
    QString code=QCryptographicHash::hash(QString::number(i).toLatin1(),QCryptographicHash::Md5).toHex().mid(0,6);
    return code;

}
