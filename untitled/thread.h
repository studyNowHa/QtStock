#ifndef THREAD_H
#define THREAD_H
#include <QString>
#include <QObject>


class thread : public QObject
{
    Q_OBJECT

public:
    thread(QString str);
    thread();
signals:
    void starts();
};

#endif // THREAD_H
