#include "dbconnect.h"

DBConnect::DBConnect()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);
    db.open();
}

AccountModel DBConnect::SelectAccount(QString login, QString password)
{
    int id;
    bool isActive;

    QString sql = "SELECT id, login, password, is_active FROM table_account WHERE login = '" + login + "' AND password = '" + password + "' AND is_active = 1;";
    QSqlQuery query;
    query.exec(sql);
    db.close();

    if (query.next()) {
        id = query.value(0).toInt();
        login = query.value(1).toString();
        password = query.value(2).toString();
        isActive = query.value(3).toBool();

        AccountModel accountModel(id, login, password, isActive);
        return accountModel;
    } else {
        AccountModel accountModel;
        return accountModel;
    }
}

PersonModel DBConnect::SelectPerson(int id)
{
    QString sql = QStringLiteral("SELECT id, first_name, last_name, birth_day, email, tel FROM table_person WHERE id = %1;").arg(id);
    QSqlQuery query;
    query.exec(sql);
    db.close();

    if (query.next()) {
        auto id = query.value(0).toInt();
        auto firstName = query.value(1).toString();
        auto lastName = query.value(2).toString();
        auto birthDay = query.value(3).toDate();
        auto email = query.value(4).toString();
        auto tel = query.value(5).toString();

        PersonModel person(id, firstName, lastName, birthDay, email, tel);
        return person;
    } else {
        PersonModel person;
        return person;
    }
}
