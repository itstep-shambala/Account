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
  /*  DBConnect db;
    PersonModel person = db.SelectPerson(id);
    ui->list_users->addItem("dsasd");*/

    QSqlDatabase db;
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("account.sqlite");
        db.open();
        //Осуществляем запрос для подсчета количества строк
        QSqlQuery query;
        query.exec("SELECT id, first_name FROM table_person");

        int i=0;
        while(query.next())
        {
            QListWidgetItem *newItem = new QListWidgetItem;
            newItem->setText(query.value(0).toString() + " " + query.value(1).toString());
            ui->list_users->insertItem(i, newItem);
            i++;
        }
       db.close();



}

void UserWindowDesign::on_list_users_itemDoubleClicked(QListWidgetItem *item)
{
    item=ui->list_users->item(ui->list_users->currentRow());

    QSqlDatabase db;
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("account.sqlite");
        db.open();
        //Осуществляем запрос для подсчета количества строк
        QSqlQuery query;
        QString sql = QStringLiteral("SELECT first_name, last_name FROM table_person WHERE id = %1;").arg(ui->list_users->currentRow());

        query.exec(sql);

        while(query.next())
        {
            ui->firstName->setText(query.value(0).toString());
           // ui->lastName->setText(query.value(1).toString());

        }

}
