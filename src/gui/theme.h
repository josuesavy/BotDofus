#ifndef THEME_H
#define THEME_H


#include <QStyle>
#include <QStyleFactory>
#include <QFont>
#include <QPalette>
#include <QDebug>

class Theme
{
public:
    Theme();

    static QStyle *style();
    static QFont font(QFont m_font);
    static QPalette palette();
    static QString styleSheet();
};

#endif // THEME_H
