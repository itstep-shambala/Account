#ifndef ACCOUNTMODEL_H
#define ACCOUNTMODEL_H

#include <QString>
#include <QDate>

class AccountModel
{
public:
    int id;
    QString login;
    QString password;
    bool isActive;
    QString role;

    AccountModel();
    AccountModel(int id, QString  login, QString password, bool isActive, QString role);
    AccountModel(int id, QString  login);

};

#endif // ACCOUNTMODEL_H
