#ifndef SUBSCRIPTIONFORM_H
#define SUBSCRIPTIONFORM_H

#include <QWidget>

namespace Ui {
class SubscriptionForm;
}

class SubscriptionForm : public QWidget
{
    Q_OBJECT

public:
    explicit SubscriptionForm(QWidget *parent = nullptr);
    ~SubscriptionForm();

private:
    Ui::SubscriptionForm *ui;
};

#endif // SUBSCRIPTIONFORM_H
