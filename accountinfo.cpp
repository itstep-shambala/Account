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
   // PersonModel person = db.SelectPerson(id);
   // AccountModel account = db.SelectUser(id);
    UserModel user = db.SelectInfo(id);
    ui->input_FirstName->setText(user.firstName);
    ui->input_LastName->setText(user.lastName);
    ui->input_birthday->setDate(user.birthDay);
    ui->input_email->setText(user.email);
    ui->input_tel->setText(user.tel);
    ui->input_login->setText(user.login);
    ui->input_password->setText(user.password);
    if (user.isActive>0){
   ui->input_isActive->setText("active");}
    else{ui->input_isActive->setText("not active");}
}
