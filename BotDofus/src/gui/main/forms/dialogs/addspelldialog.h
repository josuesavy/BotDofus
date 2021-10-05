#ifndef ADDSPELLDIALOG_H
#define ADDSPELLDIALOG_H

#include <QDialog>

#include "src/engines/DataHandler.h"

namespace Ui {
class AddSpellDialog;
}

class AddSpellDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddSpellDialog(QWidget *parent = nullptr, QMap<int, Spell> spells = QMap<int, Spell>());
    ~AddSpellDialog();

    int getSpell();
    SpellCible getTarget();
    int getNbrCast();

private slots:
    void on_comboBoxTarget_currentIndexChanged(int index);

    void on_spinBoxNbrCast_valueChanged(int arg1);

private:
    Ui::AddSpellDialog *ui;

    QMap<int, Spell> m_spells;
    uint m_spell;
    SpellCible m_target;
    int m_nbrCast;
};

#endif // ADDSPELLDIALOG_H
