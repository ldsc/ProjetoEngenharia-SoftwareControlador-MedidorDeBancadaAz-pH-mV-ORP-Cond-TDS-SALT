#ifndef ABOUT_H
#define ABOUT_H

#include <QDialog>

// classe responsável pelos textos e botões escritos na janela about

namespace Ui {
class About;
}

class About : public QDialog
{
    Q_OBJECT

public:
    explicit About(QWidget *parent = nullptr);
    ~About();

private slots:
    void on_pushButton_clicked();

private:
    Ui::About *ui;
};

#endif // ABOUT_H
