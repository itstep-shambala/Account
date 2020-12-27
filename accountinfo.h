#ifndef ACCOUNTINFO_H
#define ACCOUNTINFO_H

#include <QMainWindow>

#include "QtSql/QSqlDatabase"
#include "QSqlQuery"

namespace Ui {
class AccountInfo;
}

class AccountInfo : public QMainWindow
{
    Q_OBJECT

public:
    explicit AccountInfo(QWidget *parent = nullptr, int id = 0);
    ~AccountInfo();

private:
    Ui::AccountInfo *ui;
    int idAccount;

    void InitValue();
};

#endif // ACCOUNTINFO_H
