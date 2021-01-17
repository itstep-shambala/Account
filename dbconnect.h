#ifndef DBCONNECT_H
#define DBCONNECT_H

#include <QString>

#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include "QVariant"

#include "accountmodel.h"
#include "personmodel.h"

class DBConnect
{
public:    
    DBConnect();
    AccountModel SelectAccount(QString login, QString password);
    PersonModel SelectPerson(int id);

private:
    const QString path = "account.sqlite";
    QSqlDatabase db;
};

#endif // DBCONNECT_H
