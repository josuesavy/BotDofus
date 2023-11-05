#include "addspelldialog.h"
#include "ui_addspelldialog.h"

AddSpellDialog::AddSpellDialog(QWidget *parent, QMap<int, Spell> spells) :
    QDialog(parent),
    ui(new Ui::AddSpellDialog)
{
    ui->setupUi(this);

    m_spells = spells;

    foreach(const Spell &spell, m_spells)
    {
        QSharedPointer<SpellData> spellData = qSharedPointerCast<SpellData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SPELLS, spell.spellID));
        ui->comboBoxSpells->addItem(spellData->getName(), spell.spellID);
    }

    ui->comboBoxTarget->addItem("Ennemi");
    ui->comboBoxTarget->addItem("Allié");
    ui->comboBoxTarget->addItem("Direction");
    ui->comboBoxTarget->addItem("Moi");

    ui->spinBoxNbrCast->setMinimum(1);
}

AddSpellDialog::~AddSpellDialog()
{
    delete ui;
}

int AddSpellDialog::getSpell()
{
    return ui->comboBoxSpells->currentData(Qt::UserRole).toInt();
}

SpellCible AddSpellDialog::getTarget()
{
    return m_target;
}

int AddSpellDialog::getNbrCast()
{
    return m_nbrCast;
}

void AddSpellDialog::on_comboBoxTarget_currentIndexChanged(int index)
{
    switch ((SpellCible)index)
    {
    case SpellCible::ALLY:
        m_target = SpellCible::ALLY;
        break;

    case SpellCible::SELF:
        m_target = SpellCible::SELF;
        break;

    case SpellCible::ENEMY:
        m_target = SpellCible::ENEMY;
        break;

    case SpellCible::DIRECTION:
        m_target = SpellCible::DIRECTION;
        break;
    }
}

void AddSpellDialog::on_spinBoxNbrCast_valueChanged(int arg1)
{
    m_nbrCast = arg1;
}
