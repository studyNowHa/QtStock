#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableView>
#include <QTreeWidgetItem>
#include <QVector>
#include <QStandardItemModel>
#include <QNetworkReply>

struct columnRow{
    int column;
    int row;
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QTableView *getTableView();
    QTableView *view;

private:
    Ui::MainWindow *ui;
//    static QTableView *view;
    QMenu *rightQMenu;
    int enteredRow;
    int enteredColumn;
    columnRow enteredColumnRow;
    QVector<columnRow> vectorStatr;
    QVector<columnRow> vectorEnd;

    int pressed_row;
    int pressed_cloumn;
private slots:
    void clicked_rightMenu(const QPoint &pos);          //右键信号槽函数
    void clicked_merge();
    void clicked_middle();
    void getItem(const QModelIndex &index);              //左键信号槽函数
    void getStartItem(const QModelIndex &index);              //左键信号槽函数
    void clicked_pressed(const QModelIndex &index);
    void replyFinished(QNetworkReply *replys);
signals:
    void    starts();
};

#endif // MAINWINDOW_H
