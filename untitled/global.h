#ifndef GLOBAL_H
#define GLOBAL_H
#include <QStandardItemModel>
#include <QVector>
#include "structstock.h"

    QStandardItemModel* model;
    QVector<structStock> *stock_vector;//所有股票池
    QVector<structStock> *stock_vector_limit_up;//涨停股票池

#endif // GLOBAL_H
