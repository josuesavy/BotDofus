#ifndef QTREEWIDGETITEMDELEGATE_H
#define QTREEWIDGETITEMDELEGATE_H

#include <QStyledItemDelegate>
#include <QPainter>
#include <QDebug>

#include <QNetworkReply>

#include "src/engines/DataHandler.h"

//#include "qtreewidgetitemdatadelegate.h"

class QTreeWidgetItemDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    QTreeWidgetItemDelegate(QWidget* parent = nullptr);

    void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const override;
    QSize sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index ) const;

public:
    void drawSkin(QPainter* painter, QImage img, const QPoint &center) const;
    void drawStatus(QPainter* painter, uint connectionState, uint botState, const QPoint &center) const;
    void drawPseudo(QPainter* painter, QString data) const;
};

#endif // QTREEWIDGETITEMDELEGATE_H
