#include "threadmy.h"
#include "thread_stock.h"

threadMy::threadMy(QObject *parent) : QObject(parent)
{

}

threadMy::threadMy(QString str)
{
    QThread *pThread = new QThread();
    thread_stock *threadStock = new thread_stock();
    threadStock->num = str;
    threadStock->moveToThread(pThread);
    connect(this, SIGNAL(starts()), threadStock, SLOT(run()));
    pThread->start();
    emit starts();
}
