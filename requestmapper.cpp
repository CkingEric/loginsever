#include "requestmapper.h"

RequestMapper::RequestMapper(QObject *parent) : HttpRequestHandler(parent)
{

}

void RequestMapper::service(HttpRequest &request, HttpResponse &response)
{
    QByteArray path=request.getPath();
    qDebug("RequestMapper: path=%s",path.data());

    if(path=="/PcLogin"){
        pclogin.service(request,response);
    }
    else if(path=="/Register"){
        registers.service(request,response);
    }
    else if(path=="/PhoneLogin"){
        phonelogin.service(request,response);
    }
    else if(path=="/StmpCheck"){
        stmpcheck.service(request,response);
    }
    else if(path=="/Dynpasscheck"){
        dynpasscheck.service(request,response);
    }
    else{
        response.setStatus(404);
        response.write("The URL is wrong, no such document.",true);
    }
}
