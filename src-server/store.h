#ifndef STORE_H
#define STORE_H

#include "TCPConnection.h"
#include "order.h"
#include <QVector>

class Store{
public:
    static void getAllClothes(QVector<QStringList>&);
    static void getStoreInfo(QString, QString, QVector<QString>&);
    static void getStock(QString, QVector<QVector<QString>>&);
    static void getRecord(QString id_store, int& size, QVector<QStringList>&, QMap<QString, QMap<QString, QString> >&);
    static void getStores(QVector<QStringList>&);
    static bool sellGoods(QString, QString, QVector<int>&);
    static void purchase(QString, QMap<QString, QString>&);
    static void getPurchaseInfo(QString, QString, QVector<QStringList>&);
    static void getPurchaseInfo(QString, QVector<QStringList>&, QMap<QString, QMap<QString, QString>>&);
    static void getAllPurchaseInfo(QVector<QStringList>&);
    static void changePAmount(QString, QString, QString);

    static void storeArrive(QString, QString, Order&);
    static void logisticsReject(QString, QString);
    static void readStoreArrive(QString);
};

#endif // STORE_H
