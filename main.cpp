#include <QCoreApplication>
#include <QSettings>
#include <QFile>
#include <QDir>
#include <QString>
#include "httplistener.h"
#include "httprequesthandler.h"
#include"requestmapper.h"



using namespace stefanfrings;

QString searchConfigFile() {
    QString binDir=QCoreApplication::applicationDirPath();
    QFile file;
    file.setFileName(binDir+"/etc/gamesever.ini");
    if (file.exists()) {
        QString configFileName=QDir(file.fileName()).canonicalPath();
        qDebug("using config file %s", qPrintable(configFileName));
        return configFileName;
    }
    else {
        qFatal("config file not found");
            return QString("");
    }
}



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString configFileName=searchConfigFile();
    QSettings* listenerSettings=new QSettings(configFileName, QSettings::IniFormat, &a);
    qDebug("config file loaded");
    listenerSettings->beginGroup("listener");
    new HttpListener(listenerSettings, new RequestMapper(&a), &a);
    return a.exec();
}
