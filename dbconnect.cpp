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
    QString role;

    QString sql = "SELECT table_account.id, table_account.login, table_account.password, table_account.is_active, table_role.role FROM table_account, table_account_role, table_role WHERE login = '"+ login + "' AND password = '"+ password +"' AND is_active = 1 AND table_account_role.account_id = table_account.id AND table_account_role.role_id = table_role.id;";

    QSqlQuery query;
    query.exec(sql);
    db.close();

    if (query.next()) {
        id = query.value(0).toInt();
        login = query.value(1).toString();
        password = query.value(2).toString();
        isActive = query.value(3).toBool();
        role = query.value(4).toString();

        AccountModel accountModel(id, login, password, isActive, role);
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

//заполнение таблицы
QVector <AccountModel> DBConnect::UserTable()
{
    //Осуществляем запрос
    QVector <AccountModel> Temp;
    QSqlQuery query;
    query.exec("SELECT id, first_name, last_name, birth_day, email, tel FROM table_person");
    db.close();

    while(query.next())
    {
        AccountModel accountModel(query.value(0).toInt(), query.value(1).toString());
        Temp.push_back(accountModel);
    }
    return Temp;
}

//обновление данных
void DBConnect::Update(int id, QString firstName, QString lastName, QDate birthDay, QString email, QString tel)
{
    //Осуществляем запрос
    QSqlQuery query;
    query.exec("UPDATE table_person SET first_name = '"+firstName+"', last_name = '"+lastName+"', birth_day = '"+birthDay.toString()+"', email = '"+email+"', tel = '"+tel+"' "
                 "WHERE id = "+id+"");
    db.close();
}
