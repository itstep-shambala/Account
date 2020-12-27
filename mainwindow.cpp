#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_button_Clear_clicked()
{
    ui->input_Login->clear();
    ui->input_Password->clear();
    ui->statusbar->showMessage("Поля очищены");
}

void MainWindow::on_button_Cancel_clicked()
{
    QWidget::close();
}

void MainWindow::on_button_Submit_clicked()
{
    QString login = ui->input_Login->text();
    QString password = ui->input_Password->text();

    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("account.sqlite");
    db.open();

    QString sql = "SELECT id FROM table_account WHERE login = '" + login + "' AND password = '" + password + "' AND is_active = 1;";
    QSqlQuery query;
    query.exec(sql);
    db.close();

    if (query.next()) {
        ui->statusbar->showMessage("Вход разрешён");
        int idAccount = query.value(0).toInt();
        accountInfo = new AccountInfo(this, idAccount);
        hide();
        accountInfo->show();
    } else {
        ui->statusbar->showMessage("Вход запрещён");
    }
}
