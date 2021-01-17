#include "usermodel.h"

UserModel::UserModel()
{

}

UserModel::UserModel(int id, QString firstName, QString lastName, QDate birthDay, QString email, QString tel, QString login, QString password, bool isActive)
{
    this->id = id;
    this->firstName = firstName;
    this->lastName = lastName;
    this->birthDay = birthDay;
    this->email = email;
    this->tel = tel;
    this->login = login;
    this->password = password;
    this->isActive = isActive;
}
