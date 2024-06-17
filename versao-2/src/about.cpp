#include "about.h"
#include "ui_about.h"


About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{
    STUDY_PROFILE_FUNCTION();
    ui->setupUi(this);
}

About::~About()
{
    STUDY_PROFILE_FUNCTION();
    delete ui;
}

void About::on_pushButton_clicked()
{
    STUDY_PROFILE_FUNCTION();
    accept();
}

