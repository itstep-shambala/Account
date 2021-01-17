#include "accountmodel.h"

AccountModel::AccountModel() {}

AccountModel::AccountModel(int id, QString  login, QString password, bool isActive, QString role)
{
    this->id = id;
    this->login = login;
    this->password = password;
    this->isActive = isActive;
    this->role = role;
}
