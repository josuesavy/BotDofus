#include "gui/mainwindow.h"
#include "gui/connectiondialog.h"
#include "gui/theme.h"
#include "src/network/Sniffer.h"

#include <QApplication>
#include <QDebug>

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

//    Sniffer *sniffer = new Sniffer();

    return a.exec();
}
