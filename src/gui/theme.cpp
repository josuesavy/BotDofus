/****************************************************************************
**
** Arsenic
** Copyright (C) 2015-2017 Garten. Tout droit réservé.
** Contact: josue.savy@gmail.com
**
****************************************************************************/

#include "theme.h"

Theme::Theme()
{

}

QStyle *Theme::style()
{
    return QStyleFactory::create("Fusion");
}

QFont Theme::font(QFont m_font)
{
    QFont defaultFont = m_font;
    defaultFont.setFamily("Sans serif");

#ifdef Q_OS_WIN
    defaultFont.setPointSize(defaultFont.pointSize());
#endif
#ifdef Q_OS_LINUX
    defaultFont.setPointSize(defaultFont.pointSize()-2);
#endif
#ifdef Q_OS_MAC
    defaultFont.setPointSize(defaultFont.pointSize()-2);
#endif

    return defaultFont;
}

QPalette Theme::palette()
{
    QPalette darkPalette;
    darkPalette.setColor(QPalette::Window,QColor(53,53,53));
    darkPalette.setColor(QPalette::WindowText,Qt::white);
    darkPalette.setColor(QPalette::Disabled,QPalette::WindowText,QColor(127,127,127));
    darkPalette.setColor(QPalette::Base,QColor(42,42,42));
    darkPalette.setColor(QPalette::AlternateBase,QColor(66,66,66));
    darkPalette.setColor(QPalette::ToolTipBase,Qt::white);
    darkPalette.setColor(QPalette::ToolTipText,Qt::white);
    darkPalette.setColor(QPalette::Text,Qt::white);
    darkPalette.setColor(QPalette::Disabled,QPalette::Text,QColor(127,127,127));
    darkPalette.setColor(QPalette::Dark,QColor(35,35,35));
    darkPalette.setColor(QPalette::Shadow,QColor(20,20,20));
    darkPalette.setColor(QPalette::Button,QColor(53,53,53));
    darkPalette.setColor(QPalette::ButtonText,Qt::white);
    darkPalette.setColor(QPalette::Disabled,QPalette::ButtonText,QColor(127,127,127));
    darkPalette.setColor(QPalette::BrightText,Qt::red);
    darkPalette.setColor(QPalette::Link,QColor(42,130,218));
    darkPalette.setColor(QPalette::Highlight,QColor(42,130,218));
    darkPalette.setColor(QPalette::Disabled,QPalette::Highlight,QColor(80,80,80));
    darkPalette.setColor(QPalette::HighlightedText,Qt::white);
    darkPalette.setColor(QPalette::Disabled,QPalette::HighlightedText,QColor(127,127,127));

    return darkPalette;
}

QString Theme::styleSheet()
{
    return "QToolTip { color: #ffffff; background-color: #282828; border: 1px solid #2a82dA; border-radius:4px; }";
}
