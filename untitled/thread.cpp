#include "thread.h"
#include <QThread>
#include "thread_stock.h"
#include <QString>


thread::thread(QString str)
{
    QThread *pThread = new QThread();
    thread_stock *threadStock = new thread_stock();
    threadStock->num = str;
    threadStock->moveToThread(pThread);
    connect(this, SIGNAL(starts()), threadStock, SLOT(run()));
    pThread->start();
    emit starts();
}

thread::thread()
{

}
