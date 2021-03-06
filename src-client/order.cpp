#include "order.h"
#include "sqltool.h"
#include <QDebug>




Order::Order(int orderID, QString datetime, QStringList productInfo)
{
    this->id = orderID;
    this->datetime = datetime;
    this->productInfo = productInfo;
    QSqlQuery query;
    SQLTool::search(query, "ID", "orderInfo");
    query.last();
    this->orderID = query.value(0).toInt();
}

Order::Order(){

}

void Order::editInfo(int id, QString datetime, QStringList productInfo){
    this->id = id;
    this->datetime = datetime;
    this->productInfo = productInfo;
}

void Order::toString(QStringList &list){
    list.append(QString::number(id));
    list.append(datetime);
    int n = this->productInfo.size();

    while(n){
        list.append(this->productInfo.at(n-2));
        list.append(this->productInfo.at(n-1));
        n -= 2;
    }
}

void Order::getProductInfo(QStringList &list){
    int n = this->productInfo.size();
    while(n){
        list.append(this->productInfo.at(n-2));
        list.append(this->productInfo.at(n-1));
        n -= 2;
    }
}

QString Order::getDatetime(){
    return this->datetime;
}

void Order::saveOrder(Order &order)
{
    QStringList list;
    QString productInformation;
    productInformation = order.productInfo.join("#");
    list.append("0");
    list.append(order.datetime);
    list.append(productInformation);
    qDebug() << list;
    SQLTool::insert("orderInfo", list);

}



void Order::info(QString orderID, QStringList &orderInformation)
{
    QSqlQuery query;
    SQLTool::search(query, "order", "ID", orderID);
    if(query.next()){
        orderInformation.append(query.value(0).toString());
        orderInformation.append(query.value(1).toString());
        orderInformation.append(query.value(2).toString());
    }

}

void Order::info(QVector<QStringList> &orderInformation)
{
    QSqlQuery query;
    SQLTool::search(query, "order");
    QStringList list;
    while (query.next()) {
        list.clear();
        list.append(query.value(0).toString());
        list.append(query.value(1).toString());
        list.append(query.value(2).toString());
        orderInformation.append(list);
    }
}


