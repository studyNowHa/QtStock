#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "thread_stock.h"
#include <QMenu>
#include <QAction>
#include <QObject>
#include <QString>
#include <QDebug>
#include <QVector>
#include <thread_stock.h>
#include <QTextCodec>
#include "httpqq.h"
#include "threadmy.h"

// QTableView *MainWindow::view = new QTableView;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
//    ui->setupUi(this);


    model = new QStandardItemModel();
    model->setItem(0, 0, new QStandardItem("概念"));
    model->setItem(0, 1, new QStandardItem("股票代码"));
    model->setItem(0, 2, new QStandardItem("股票名称"));
    model->setItem(0, 3, new QStandardItem("打板时间"));
    model->setItem(0, 4, new QStandardItem("第几板"));
    model->setItem(0, 5, new QStandardItem("涨停属性"));
    model->setItem(2, 1, new QStandardItem("1-1"));
    model->setItem(2, 2, new QStandardItem("1-2"));
    model->setItem(2, 3, new QStandardItem("1-3"));
    QTableView *view = new QTableView;
    view->setModel(model);

    //鼠标右键
    view->setContextMenuPolicy(Qt::CustomContextMenu);
    rightQMenu = new QMenu;
    QAction *merge = new QAction("合并");
    QAction *middle = new QAction("居中");
    rightQMenu->addAction(merge);
    rightQMenu->addAction(middle);
    connect(view,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(clicked_rightMenu(QPoint)));
    connect(merge, &QAction::triggered, this, &MainWindow::clicked_merge);
    connect(middle, &QAction::triggered, this, &MainWindow::clicked_middle);
    //鼠标单击
    connect(view,SIGNAL(entered(const QModelIndex &)),this,SLOT(getItem(const QModelIndex &)));
    connect(view,SIGNAL(clicked(const QModelIndex &)),this,SLOT(getStartItem(const QModelIndex &)));
    connect(view,SIGNAL(pressed(const QModelIndex &)),this,SLOT(clicked_pressed(const QModelIndex &)));
    //线程
    QVector <QString> str;
    str.append("sz300000");
    str.append("sz300001");
    str.append("sz300002");
    str.append("sz300003");
    str.append("sz300004");
    str.append("sz300005");
    str.append("sz300006");
    str.append("sz300007");
    str.append("sz300008");
    str.append("sz300009");
    str.append("sz300010");
    str.append("sz300011");
    str.append("sz300012");
    str.append("sz300013");
    str.append("sz300014");
    str.append("sz300015");
    str.append("sz300016");
    str.append("sz300017");
    str.append("sz300018");
    str.append("sz300019");
    str.append("sz300020");
    str.append("sz300021");
    str.append("sz300022");
    str.append("sz300023");
    str.append("sz300024");
    str.append("sz300025");
    str.append("sz300026");
    str.append("sz300027");
    str.append("sz300028");
    str.append("sz300029");
    str.append("sz300452");
    str.append("sz300471");
    str.append("sz300228");
    for(int i=0; i<str.count(); i++){
        threadMy *threasStrart = new threadMy(str.at(i));
    }
    view->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

QTableView *MainWindow::getTableView()
{
    return MainWindow::view;
}

/*
合并单元格
*/
void MainWindow::clicked_rightMenu(const QPoint &pos)
{
    rightQMenu->exec(QCursor::pos());
}

void MainWindow::clicked_merge()
{
        qDebug("first.column=%d",vectorEnd.first().column);
        qDebug("first.row=%d",vectorEnd.first().row);
        qDebug("end.column=%d",vectorEnd.last().column);
        qDebug("end.row=%d",vectorEnd.last().row);
        view->setSpan(vectorEnd.first().row, vectorEnd.first().column, vectorEnd.last().row+1-vectorEnd.first().row, vectorEnd.last().column+1-vectorEnd.first().column);
        vectorEnd.clear();
}

void MainWindow::clicked_middle()
{
    model->item(pressed_row, pressed_cloumn)->setTextAlignment(Qt::AlignCenter);
}
/*
获取行列号
*/
void MainWindow::getItem(const QModelIndex &index)
{
    qDebug()<<"getItem";
    enteredColumnRow.column = index.column();
    enteredColumnRow.row = index.row();
    vectorEnd.append(enteredColumnRow);
    qDebug("end.column=%d",vectorEnd.last().column);
    qDebug("end.row=%d",vectorEnd.last().row);

}

void MainWindow::getStartItem(const QModelIndex &index)
{

}

void MainWindow::clicked_pressed(const QModelIndex &index)
{
    qDebug("pressed_row=%d",index.row());
    qDebug("pressed_column=%d",index.column());
    pressed_row = index.row();
    pressed_cloumn = index.column();
}

void MainWindow::replyFinished(QNetworkReply *replys)
{
    QString all = QString::fromLocal8Bit(replys->readAll());
    qDebug()<< all << endl;
}


