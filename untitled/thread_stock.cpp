#include "thread_stock.h"
#include "httpqq.h"

thread_stock::thread_stock()
{

}

void thread_stock::run()
{
    qDebug("run_thread_stock");
//    httpQQ *http = new httpQQ();
//    http = new httpQQ();
    httpQQ *http = new httpQQ(num);
    //获取股票数据
//    MainWindow *main = new MainWindow;
//    qDebug("column=%d",main->getTableView()->rootIndex().column());
}
