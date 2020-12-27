#include "accountinfo.h"
#include "ui_accountinfo.h"

AccountInfo::AccountInfo(QWidget *parent, int id) :
    QMainWindow(parent),
    ui(new Ui::AccountInfo)
{
    ui->setupUi(this);
    idAccount = id;
    InitValue();
}

AccountInfo::~AccountInfo()
{
    delete ui;
}

void AccountInfo::InitValue()
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("account.sqlite");
    db.open();

    QString sql = QStringLiteral("SELECT first_name, last_name, birth_day, email, tel FROM table_person WHERE id = %1;").arg(idAccount);
    QSqlQuery query;
    query.exec(sql);
    db.close();
    while (query.next()) {
        auto firstName = query.value(0).toString();
        auto lastName = query.value(1).toString();
        auto birthDay = query.value(2).toDate();
        auto email = query.value(3).toString();
        auto tel = query.value(4).toString();

        ui->input_FirstName->setText(firstName);
        ui->input_LastName->setText(lastName);
        ui->input_birthday->setDate(birthDay);
        ui->input_email->setText(email);
        ui->input_tel->setText(tel);
    }
}
