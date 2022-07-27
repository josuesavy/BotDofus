#ifndef CONFIGURATIONFORM_H
#define CONFIGURATIONFORM_H

#include <QWidget>

namespace Ui {
class ConfigurationForm;
}

class ConfigurationForm : public QWidget
{
    Q_OBJECT

public:
    explicit ConfigurationForm(QWidget *parent = nullptr);
    ~ConfigurationForm();

private:
    Ui::ConfigurationForm *ui;
};

#endif // CONFIGURATIONFORM_H
