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

/*PersonModel DBConnect::SelectPerson(int id)
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
*/
UserModel DBConnect::SelectInfo(int id)
{
   // QString sql = QStringLiteral("SELECT id, login, password, is_active FROM table_account WHERE id = %1;").arg(id);
    QString sql =QStringLiteral("select table_account.id, table_account.login, table_account.password, table_account.is_active, table_person.first_name, table_person.last_name, table_person.birth_day, table_person.email, table_person.tel from table_account left join table_person on table_account.id=table_person.id where table_account.id=%1;").arg(id);
    QSqlQuery query;
    query.exec(sql);
    db.close();

    if (query.next()) {
        auto id = query.value(0).toInt();
        auto login = query.value(1).toString();
        auto password = query.value(2).toString();
        auto isActive = query.value(3).toBool();

        auto firstName = query.value(4).toString();
        auto lastName = query.value(5).toString();
        auto birthDay = query.value(6).toDate();
        auto email = query.value(7).toString();
        auto tel = query.value(8).toString();

        UserModel user (id, firstName, lastName, birthDay, email, tel, login, password, isActive);
        return user;
    } else {

        UserModel user;
        return user;
    }
}
