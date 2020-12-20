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
    db = QSqlDatabase::addDatabase("SQLITE");
    db.setDatabaseName("account.sqlite");
    db.open();

    QString sql = "SELECT login FROM table_account WHERE login = '" + login + "' AND password = '" + password + "' AND is_active = 1;";
    QSqlQuery query;
    query.exec(sql);

    if (query.next()) {
        ui->statusbar->showMessage("Вход разрешён");
    } else {
        ui->statusbar->showMessage("Вход запрещён");
    }
}
