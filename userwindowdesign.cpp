#include "userwindowdesign.h"
#include "ui_userwindowdesign.h"

UserWindowDesign::UserWindowDesign(QWidget *parent, int id) :
    QMainWindow(parent),
    ui(new Ui::UserWindowDesign)
{
    ui->setupUi(this);
    this->id = id;
    FillingUserTable();
}

UserWindowDesign::~UserWindowDesign()
{
    delete ui;
}

void UserWindowDesign::FillingUserTable()
{
    DBConnect db;
    QVector <AccountModel> ListUsers=db.UserTable();
    for (int i=0;i<ListUsers.size();i++)
    {
        QListWidgetItem *newItem = new QListWidgetItem;
        newItem->setText(QString::number(ListUsers[i].id) + " " + ListUsers[i].login);
        ui->list_users->insertItem(i, newItem);
    }
}

//выбор пользователя
void UserWindowDesign::on_list_users_itemDoubleClicked(QListWidgetItem *item)
{
    item=ui->list_users->item(ui->list_users->currentRow());
    DBConnect db;
    PersonModel personModel=db.SelectPerson(ui->list_users->currentRow());
    ui->id->setText(QString::number(personModel.id));
    ui->firstName->setText(personModel.firstName);
    ui->lastName->setText(personModel.lastName);
    ui->dateBirthday->setDate(personModel.birthDay);
    ui->email->setText(personModel.email);
    ui->tel->setText(personModel.tel);
}

//обновление данных
void UserWindowDesign::on_pushButton_update_clicked()
{
    //загрузка новых данных в БД
    QString id=ui->id->text();
    QString firstName=ui->firstName->text();
    QString lastName=ui->lastName->text();
    QDate dateBirthday=ui->dateBirthday->date();
    QString email=ui->email->text();
    QString tel=ui->tel->text();
    DBConnect db;
    db.Update(id.toInt(), firstName, lastName, dateBirthday, email, tel);
    //обновление БД в таблице
    FillingUserTable();
}

//отмена изменений
void UserWindowDesign::on_pushButton_cancel_clicked()
{
    ui->firstName->clear();
    ui->lastName->clear();
    ui->dateBirthday->clear();
    ui->email->clear();
    ui->tel->clear();
}
