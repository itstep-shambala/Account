#include "userwindowdesign.h"
#include "ui_userwindowdesign.h"

UserWindowDesign::UserWindowDesign(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserWindowDesign)
{
    ui->setupUi(this);
}

UserWindowDesign::~UserWindowDesign()
{
    delete ui;
}
