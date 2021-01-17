#include "personmodel.h"

PersonModel::PersonModel() {}

PersonModel::PersonModel(int id, QString firstName, QString lastName, QDate birthDay, QString email, QString tel)
{
    this->id = id;
    this->firstName = firstName;
    this->lastName = lastName;
    this->birthDay = birthDay;
    this->email = email;
    this->tel = tel;
}
