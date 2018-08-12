#ifndef THREAD_STOCK_H
#define THREAD_STOCK_H
#include <QThread>
#include <mainwindow.h>
#include <QObject>

class thread_stock : public QObject
{
    Q_OBJECT
public:
    thread_stock();
    QString num;
public slots:
    void run();
};

#endif // THREAD_STOCK_H
