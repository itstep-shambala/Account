#ifndef PERSONMODEL_H
#define PERSONMODEL_H

#include <QString>
#include <QDate>

class PersonModel
{
public:
    int id;
    QString firstName;
    QString lastName;
    QDate birthDay;
    QString email;
    QString tel;

    PersonModel();
    PersonModel(int id, QString firstName, QString lastName, QDate birthDay, QString email, QString tel);
};

#endif // PERSONMODEL_H
