#include "mainwindow.h"
#include "Instrumentor.h"


#include <QApplication>
#include <QLocale>
#include <QTranslator>



int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "Pedro_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    STUDY_PROFILE_BEGIN_SESSION("Create Window", "Create-Profile.json");
    MainWindow w;
    STUDY_PROFILE_END_SESSION();

    w.show();

    STUDY_PROFILE_BEGIN_SESSION("exec Window", "RunTime-Profile.json");
    int exe = a.exec();
    STUDY_PROFILE_END_SESSION();

    return exe;
}
