#include "httpqq.h"
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QObject>
#include <QNetworkAccessManager>
#include <QThread>
#include <QEventLoop>
#include <QStringList>
#include "structstock.h"

httpQQ::httpQQ(QString num)
{
    QString stock = "http://qt.gtimg.cn/q=" + num;
    netWork = new QNetworkAccessManager();
    QEventLoop eventLoop;
    QObject::connect(netWork, SIGNAL(finished(QNetworkReply*)),&eventLoop,SLOT(quit()));
    while(1){
        reply =netWork->get(QNetworkRequest(QUrl(stock)));
        eventLoop.exec();
        QString all = QString::fromLocal8Bit(reply->readAll());
        QStringList stock_list = all.split("~");
        structStock stock_data;
        if(stock_list.count()>48){
            stock_data.stock_name = stock_list.at(1);
            stock_data.stock_num = stock_list.at(2);
            stock_data.stock_uplift_percent = stock_list.at(32);
            qDebug()<< stock_data.stock_name;
            qDebug()<< stock_data.stock_num;
            qDebug()<< stock_data.stock_uplift_percent<<endl;
            //填充表格数据
        }
        delete reply;
        eventLoop.processEvents();
        QThread::sleep(1);//降低CPU使用率
//        qDebug()<< all << endl;
//        qDebug()<< "while_replyState" << endl;
    }

}

httpQQ::~httpQQ()
{
    netWork->deleteLater();
    reply->deleteLater();
    qDebug()<< "~httpQQ" << endl;
}

void httpQQ::replyFinished(QNetworkReply *replys)
{
    QString all = QString::fromLocal8Bit(replys->readAll());
    qDebug()<< all << endl;
    replys->deleteLater();
    replyState = true;
    qDebug()<< "replyFinished" << endl;
}

void httpQQ::replyreadyRead()
{
//    QString all = QString::fromLocal8Bit(reply->readAll());
//    qDebug()<< all << endl;
//    qDebug()<< "replyreadyRead" << endl;
}
