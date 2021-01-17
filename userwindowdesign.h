#ifndef USERWINDOWDESIGN_H
#define USERWINDOWDESIGN_H

#include <QMainWindow>

#include "QtSql/QSqlDatabase"
#include "QSqlQuery"

#include "accountmodel.h"
#include "personmodel.h"
#include "dbconnect.h"
#include <QListWidget>

namespace Ui {
class UserWindowDesign;
}

class UserWindowDesign : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserWindowDesign(QWidget *parent = nullptr, int id = 0);
    ~UserWindowDesign();

private slots:
    void on_list_users_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::UserWindowDesign *ui;

    int id;
    void FillingUserTable ();
};

#endif // USERWINDOWDESIGN_H
