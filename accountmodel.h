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
    QString role;

    AccountModel();
    AccountModel(int id, QString  login, QString password, bool isActive, QString role);
};

#endif // ACCOUNTMODEL_H
