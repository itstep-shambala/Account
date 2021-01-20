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
    QSqlDatabase db;
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("account.sqlite");
        db.open();
        //Осуществляем запрос
        QSqlQuery query;
        query.exec("SELECT id, first_name, last_name, birth_day, email, tel FROM table_person");

        int i=0;
        while(query.next())
        {
            QListWidgetItem *newItem = new QListWidgetItem;
            newItem->setText(query.value(0).toString() + " " + query.value(1).toString() + " " + query.value(2).toString() + " " + query.value(3).toString() + " " + query.value(4).toString()
                              + " " + query.value(5).toString());
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
        //Осуществляем запрос
        QSqlQuery query;
        QString sql = QStringLiteral("SELECT first_name, last_name, birth_day, email, tel FROM table_person WHERE id = %1;").arg(ui->list_users->currentRow());
        query.exec(sql);
        ui->id->setText(QString::number(ui->list_users->currentRow()));
        while(query.next())
        {
            ui->firstName->setText(query.value(0).toString());
            ui->lastName->setText(query.value(1).toString());
            ui->dateBirthday->setDate(query.value(2).toDate());
            ui->email->setText(query.value(3).toString());
            ui->tel->setText(query.value(4).toString());
        }
        db.close();
}

void UserWindowDesign::on_pushButton_update_clicked()
{
    QString id=ui->id->text();
    QString firstName=ui->firstName->text();
    QString lastName=ui->lastName->text();
    QDate dateBirthday=ui->dateBirthday->date();
    QString email=ui->email->text();
    QString tel=ui->tel->text();
    QSqlDatabase db;
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("account.sqlite");
        db.open();
        //Осуществляем запрос
        QSqlQuery query;
        query.exec("UPDATE table_person SET first_name = '"+firstName+"', last_name = '"+lastName+"', birth_day = '"+dateBirthday.toString()+"', email = '"+email+"', tel = '"+tel+"' "
                     "WHERE id = "+id+"");
        db.close();
}

void UserWindowDesign::on_pushButton_cancel_clicked()
{
    ui->firstName->clear();
    ui->lastName->clear();
    ui->dateBirthday->clear();
    ui->email->clear();
    ui->tel->clear();

}
