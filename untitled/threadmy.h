#ifndef THREADMY_H
#define THREADMY_H

#include <QObject>
#include <QString>
#include <QThread>

class threadMy : public QObject
{
    Q_OBJECT
public:
    explicit threadMy(QObject *parent = 0);
    threadMy(QString str);

signals:
    void starts();
public slots:
};

#endif // THREADMY_H
