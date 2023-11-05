#include "gui/windows/mainwindow.h"
#include "gui/windows/dialogs/connectiondialog.h"
#include "gui/utils/theme.h"

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
