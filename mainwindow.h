#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "QtSql/QSqlDatabase"
#include "QSqlQuery"

#include "accountinfo.h"
#include "userwindowdesign.h"

#include "dbconnect.h"
#include "accountmodel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_button_Clear_clicked();

    void on_button_Cancel_clicked();

    void on_button_Submit_clicked();

private:
    Ui::MainWindow *ui;
    AccountInfo *accountInfo;
    UserWindowDesign *userWindow;
};
#endif // MAINWINDOW_H
