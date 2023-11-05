#include "gui/mainwindow.h"
#include "gui/connectiondialog.h"
#include "gui/theme.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Chargement du thème
    qApp->setStyle(Theme::style());
    //qApp->setFont(Theme::font(QApplication::font()));
    qApp->setPalette(Theme::palette());
    qApp->setStyleSheet(Theme::styleSheet());

    ConnectionDialog cd;
    cd.show();

    return a.exec();
}
