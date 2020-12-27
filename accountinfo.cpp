#include "accountinfo.h"
#include "ui_accountinfo.h"

AccountInfo::AccountInfo(QWidget *parent, int id) :
    QMainWindow(parent),
    ui(new Ui::AccountInfo)
{
    ui->setupUi(this);
    this->id = id;
    InitValue();
}

AccountInfo::~AccountInfo()
{
    delete ui;
}

void AccountInfo::InitValue()
{
    DBConnect db;
    PersonModel person = db.SelectPerson(id);

    ui->input_FirstName->setText(person.firstName);
    ui->input_LastName->setText(person.lastName);
    ui->input_birthday->setDate(person.birthDay);
    ui->input_email->setText(person.email);
    ui->input_tel->setText(person.tel);
}
