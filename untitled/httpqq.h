#ifndef HTTPQQ_H
#define HTTPQQ_H
#include <QNetworkAccessManager>
#include <QString>
#include <QByteArray>
#include <QUrl>
#include <QMainWindow>
#include <QObject>
#include "structstock.h"
#include <QMutex>
#include <QMutexLocker>


extern QVector<structStock> *stock_vector;//全局变量 所有股票
extern QVector<structStock> *stock_vector_limit_up;//全局变量 涨停股票

class httpQQ: public QObject
{
    Q_OBJECT

public:
    explicit httpQQ(QString num);       //访问腾讯网的股票数据
    ~httpQQ();
    bool compareStockData(const structStock &stock_data1, const structStock &stock_data2);
private slots:
    void replyFinished(QNetworkReply *replys);
    void replyreadyRead();
private:
    QString sNum;
    bool replyState = true;
    QNetworkReply *reply;
    QNetworkAccessManager *netWork = new QNetworkAccessManager();
    structStock stock_data;
    structStock* getStockData(QString num);
    QMutex mutex;
};

#endif // HTTPQQ_H
