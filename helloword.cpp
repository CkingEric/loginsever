#include "helloword.h"

HelloWord::HelloWord(QObject *parent) : HttpRequestHandler(parent)
{

}

void HelloWord::service(HttpRequest &request, HttpResponse &response)
{
    QString hello="\
                <html>\
                <head>\
                </head>\
                <body>\
                    这是网页的内容\
                    <h1>helloworld</h1>\
                    <h2>personalweb</h2>\
                    <h3>test</h3>\
                    <h4>h4</h4>\
                    <h5>%1</h5>\
             \
                    <p>ppppppppppp</p>\
             \
                <div>\
                    <p>ppppppppppp</p>\
                </div>\
             \
                    <ul>\
                        <li>hahaha</li>\
                        <li>hahaha</li>\
                        <li>hahaha</li>\
                    </ul>\
             \
                    <ol>\
                        <li>ahahah</li>\
                        <li>ahahah</li>\
                        <li>ahahah</li>\
                    </ol>\
             \
                </body>\
            </html>";;
    if(request.getMethod()=="GET"){
        response.write(hello.arg(utill::randomcode()).toLatin1(),true);
    }

}
