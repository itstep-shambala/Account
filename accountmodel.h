#ifndef ACCOUNTMODEL_H
#define ACCOUNTMODEL_H

#include <QString>

class AccountModel
{
public:
    int id;
    QString login;
    QString password;
    bool isActive;
    QString rule;

    AccountModel();
    AccountModel(int id, QString  login, QString password, bool isActive, QString rule);
};

#endif // ACCOUNTMODEL_H
