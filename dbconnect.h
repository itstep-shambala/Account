#ifndef DBCONNECT_H
#define DBCONNECT_H

#include <QString>
#include <QVector>

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
    QVector <AccountModel> UserTable();
    void Update(int id, QString firstName, QString lastName, QDate birthDay, QString email, QString tel);
private:
    const QString path = "account.sqlite";
    QSqlDatabase db;
};

#endif // DBCONNECT_H
