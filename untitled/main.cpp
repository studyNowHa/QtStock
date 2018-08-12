#include "mainwindow.h"
#include <QApplication>
#include <test.h>

#include "global.h"
extern QStandardItemModel* model;
extern QVector<structStock> *stock_vector;//全局变量 所有股票
extern QVector<structStock> *stock_vector_limit_up;//全局变量 涨停股票

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    model = new QStandardItemModel();
    //初始化全局变量
    stock_vector = new QVector<structStock>;
    stock_vector_limit_up = new QVector<structStock>;
    MainWindow w;
//    w.show();


    return a.exec();
}


//QTableView动态更新
//haha
