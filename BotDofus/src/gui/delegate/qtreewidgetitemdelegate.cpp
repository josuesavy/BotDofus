#include "qtreewidgetitemdelegate.h"

QTreeWidgetItemDelegate::QTreeWidgetItemDelegate(QWidget *parent)
{

}

void QTreeWidgetItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();

    const QRect& rect = option.rect;
    const QPoint& center = rect.center() - rect.topLeft();
    const QPalette& palette = option.palette;

    painter->setRenderHint(QPainter::Antialiasing, true);

    if (option.state & QStyle::State_Selected)
        painter->fillRect(rect, palette.highlight());

    painter->translate(rect.x(), rect.y());

    QImage image = index.data(4).value<QPixmap>().toImage().scaled(38,38,Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    if(image.isNull())
        image = QImage(":/icons/user.png").scaled(38,38);

    drawSkin(painter, image, center);
    drawPseudo(painter, index.data(1).toString());
    drawStatus(painter, index.data(2).toUInt(), index.data(3).toUInt(), center);

    painter->restore();
}

QSize QTreeWidgetItemDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QSize result = QStyledItemDelegate::sizeHint(option, index);
    result.setHeight(45);
    return result;
}

void QTreeWidgetItemDelegate::drawSkin(QPainter *painter, QImage img, const QPoint &center) const
{
    painter->drawImage(QPoint(0, center.y() - img.height() / 2), img);
    painter->translate(img.width(), 0);
}

void QTreeWidgetItemDelegate::drawStatus(QPainter *painter, uint connectionState, uint botState, const QPoint &center) const
{
    const int radius = 7;

    // Draw status circle
    painter->save();

    const QPoint circleCenter(radius+5, 5 + center.y());
    QColor color;

    if(connectionState == (uint)ConnectionState::DISCONNECTED)
        painter->drawImage(circleCenter, QImage(":/icons/bullet_red_16px.ico"));
    else if (connectionState == (uint)ConnectionState::TRANSITION)
        painter->drawImage(circleCenter, QImage(":/icons/bullet_orange_16px.ico"));
    else
        painter->drawImage(circleCenter, QImage(":/icons/bullet_green_16px.ico"));

    painter->restore();

    painter->translate(radius/2, 10);

    // Draw status action
    painter->save();
    QFont font = QFont("Sans serif");
    font.setBold(false);
    painter->setFont(font);
    QFontMetrics metrics(font);

    QString action;

    if(connectionState == (uint)ConnectionState::DISCONNECTED)
        action = "Disconnected";
    else if (connectionState == (uint)ConnectionState::TRANSITION)
        action = "Connection";
    else
    {
        switch (botState)
        {
        case BotState::MOVING_STATE:            action = "Moving"; break;
        case BotState::MAP_TRANSITION_STATE:
        case BotState::CALCULATING_STATE:       action = "Busy"; break;
        case BotState::FARMING_STATE:           action = "Harvest"; break;
        case BotState::BANKING_STATE:           action = "Bank"; break;
        case BotState::INVALID_STATE:           action = "Invalide"; break;
        case BotState::CRAFTING_STATE:          action = "Craft"; break;
        case BotState::FIGHTING_STATE:          action = "Fight"; break;
        case BotState::INACTIVE_STATE:          action = "Inactive"; break;
        case BotState::EXCHANGING_STATE:        action = "Exchange"; break;
        case BotState::REGENERATING_STATE:      action = "Regeneration"; break;
        }
    }

    QRect bounds = metrics.boundingRect(action);
    bounds.translate(10, center.y() - 2 + bounds.height() / 2);
    bounds.setWidth(bounds.width() + 3);
    int flags = Qt::AlignCenter;
    painter->drawText(bounds, flags, action);
    painter->restore();
}

void QTreeWidgetItemDelegate::drawPseudo(QPainter *painter, QString data) const
{
    painter->save();

    QFont font = painter->font();
    font.setBold(false);
    font.setPointSize(font.pointSize()+2);
    painter->setFont(font);
    QFontMetrics metrics(font);
    const QString pseudo = data;
    QRect bounds = metrics.boundingRect(pseudo);
    bounds.translate(16, bounds.height());
    bounds.setWidth(bounds.width() + 3);
    int flags = Qt::AlignCenter;
    painter->drawText(bounds, flags, pseudo);

    painter->restore();
}
