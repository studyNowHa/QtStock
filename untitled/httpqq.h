#ifndef HTTPQQ_H
#define HTTPQQ_H
#include <QNetworkAccessManager>
#include <QString>
#include <QByteArray>
#include <QUrl>
#include <QMainWindow>
#include <QObject>

class httpQQ: public QObject
{
    Q_OBJECT

public:
    explicit httpQQ(QString num);       //访问腾讯网的股票数据
    ~httpQQ();
private slots:
    void replyFinished(QNetworkReply *replys);
    void replyreadyRead();
private:
    QString sNum;
    bool replyState = true;
    QNetworkReply *reply;
    QNetworkAccessManager *netWork;
};

#endif // HTTPQQ_H
