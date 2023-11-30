#include <QDialog>
#include <qpushbutton.h>

class About : public QDialog
{
public:
    About()
    {
        QDialog *subDialog = new QDialog;
        subDialog->setWindowTitle("Sub Dialog");
        QPushButton *button = new QPushButton("Push to open new dialog", this);
        connect(button, SIGNAL(clicked()), subDialog, SLOT(show()));
    }
};
