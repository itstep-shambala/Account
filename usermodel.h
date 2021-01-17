#ifndef USERMODEL_H
#define USERMODEL_H

#include <QString>
#include <QDate>

#include "personmodel.h"
#include "accountmodel.h"

class UserModel
{
public:
    int id;
    QString firstName;
    QString lastName;
    QDate birthDay;
    QString email;
    QString tel;
    QString login;
    QString password;
    bool isActive;

    UserModel();
    UserModel(int id, QString firstName, QString lastName, QDate birthDay, QString email, QString tel, QString login, QString password, bool isActive);
};

#endif // USERMODEL_H
