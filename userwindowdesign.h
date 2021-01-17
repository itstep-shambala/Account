#ifndef USERWINDOWDESIGN_H
#define USERWINDOWDESIGN_H

#include <QMainWindow>

namespace Ui {
class UserWindowDesign;
}

class UserWindowDesign : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserWindowDesign(QWidget *parent = nullptr);
    ~UserWindowDesign();

private:
    Ui::UserWindowDesign *ui;
};

#endif // USERWINDOWDESIGN_H
