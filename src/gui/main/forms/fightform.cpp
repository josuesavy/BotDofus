#include "fightform.h"
#include "ui_fightform.h"

FightForm::FightForm(ProcessEngine *engine, const ConnectionInfos &infos, SocketIO *sender, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FightForm)
{
    ui->setupUi(this);

    // Liste d'initialisations
    m_engine = engine;
    m_infos = infos;
    m_sender = sender;

    ui->tabWidgetFight->setCurrentIndex(0);

    ui->tableWidgetSpells->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Stretch);
}

FightForm::~FightForm()
{
    delete ui;
}

SocketIO *FightForm::getSocket()
{
    return m_sender;
}

ConnectionInfos FightForm::getConnectionInfos() const
{
    return m_infos;
}

void FightForm::updateInterface(bool directCall)
{
    const BotData &infos = getData();

    if (infos.connectionData.connectionState == ConnectionState::CONNECTED)
    {

    }

    if (infos.connectionData.connectionState == ConnectionState::TRANSITION)
    {

    }

    if (infos.connectionData.connectionState == ConnectionState::DISCONNECTED)
    {

    }
}

const BotData &FightForm::getData() const
{
    return m_engine->getData(m_sender);
}

void FightForm::on_pushButtonMoveTopSpell_clicked()
{
    int index = ui->tableWidgetSpells->row(ui->tableWidgetSpells->selectedItems().first());

    if(ui->tableWidgetSpells->selectedItems().count() > 0 && index != 0)
    {
        QList<RequestedSpell> rs = m_engine->getFightModule().getRequestedSpells(m_sender);
        rs.move(index, index-1);
        m_engine->getFightModule().setRequestedSpells(m_sender, rs);

        QList<QTableWidgetItem*> sourceItems;
        QList<QTableWidgetItem*> destItems;

        for(int i = 0; i < ui->tableWidgetSpells->columnCount(); i++)
        {
            sourceItems << ui->tableWidgetSpells->takeItem(index, i);
            destItems << ui->tableWidgetSpells->takeItem(index-1, i);
        }

        for(int i = 0; i < ui->tableWidgetSpells->columnCount(); i++)
        {
            ui->tableWidgetSpells->setItem(index, i, destItems.at(i));
            ui->tableWidgetSpells->setItem(index-1, i, sourceItems.at(i));
        }

        ui->tableWidgetSpells->selectRow(index-1);
    }
}

void FightForm::on_pushButtonMoveDownSpell_clicked()
{
    int index = ui->tableWidgetSpells->row(ui->tableWidgetSpells->selectedItems().first());

    QList<RequestedSpell> rs = m_engine->getFightModule().getRequestedSpells(m_sender);

    if(ui->tableWidgetSpells->selectedItems().count() > 0 && index != rs.size()-1)
    {
        rs.move(index, index+1);
        m_engine->getFightModule().setRequestedSpells(m_sender, rs);

        QList<QTableWidgetItem*> sourceItems;
        QList<QTableWidgetItem*> destItems;

        for(int i = 0; i < ui->tableWidgetSpells->columnCount(); i++)
        {
            sourceItems << ui->tableWidgetSpells->takeItem(index, i);
            destItems << ui->tableWidgetSpells->takeItem(index+1, i);
        }

        for(int i = 0; i < ui->tableWidgetSpells->columnCount(); i++)
        {
            ui->tableWidgetSpells->setItem(index, i, destItems.at(i));
            ui->tableWidgetSpells->setItem(index+1, i, sourceItems.at(i));
        }

        ui->tableWidgetSpells->selectRow(index+1);
    }
}

void FightForm::on_pushButtonAddSpell_clicked()
{
    const BotData &infos = getData();

    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle("Ajouter un sort");
    QLabel *label1 = new QLabel("Sort");
    QComboBox *combobox1 = new QComboBox(dialog);

    QSharedPointer<SpellData> spellData;
    foreach(const Spell &spell, infos.playerData.spells)
    {
        spellData = qSharedPointerCast<SpellData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SPELLS, spell.spellID));
        combobox1->addItem(spellData->getName(), spell.spellID);
    }

    QLabel *label2 = new QLabel("Cible");
    QComboBox *combobox2 = new QComboBox(dialog);
    combobox2->addItem("Ennemi");
    combobox2->addItem("Allié");
    combobox2->addItem("Direction");
    combobox2->addItem("Moi");

    QLabel *label3 = new QLabel("Nombre de lancé");
    QSpinBox *spinbox1 = new QSpinBox(dialog);
    spinbox1->setMinimum(1);
    QDialogButtonBox *dialogButtonBox = new QDialogButtonBox(QDialogButtonBox::Ok|QDialogButtonBox::Cancel, Qt::Horizontal, dialog);

    connect(dialogButtonBox, &QDialogButtonBox::accepted, dialog, &QDialog::accept);
    connect(dialogButtonBox, &QDialogButtonBox::rejected, dialog, &QDialog::reject);

    QFormLayout *layout = new QFormLayout;
    layout->addRow(label1, combobox1);
    layout->addRow(label2, combobox2);
    layout->addRow(label3, spinbox1);
    layout->addRow(dialogButtonBox);

    dialog->setLayout(layout);

    if(dialog->exec() == QDialog::Accepted)
    {
        while(ui->tableWidgetSpells->rowCount() > 0)
            ui->tableWidgetSpells->removeRow(0);

        // Creation d'un sort à jouer en combat
        RequestedSpell r;
        r.spellID = combobox1->currentData().toInt();
        r.castNb = spinbox1->value();
        r.spellCible = (SpellCible)combobox2->currentIndex();

        // On le rajoute à ceux déjà présent
        QList<RequestedSpell> rs = m_engine->getFightModule().getRequestedSpells(m_sender);
        rs << r;

        // Actualisation des sorts avec le nouveau
        m_engine->getFightModule().setRequestedSpells(m_sender, rs);

        int indexSpell = 0;
        QSharedPointer<SpellData> spellData;
        foreach(const RequestedSpell &r, rs)
        {
            spellData = qSharedPointerCast<SpellData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SPELLS, r.spellID));

            ui->tableWidgetSpells->insertRow(ui->tableWidgetSpells->rowCount());
            ui->tableWidgetSpells->setItem(indexSpell, 0, new QTableWidgetItem(spellData->getName()));
            if(r.spellCible == SpellCible::ENEMY)
                ui->tableWidgetSpells->setItem(indexSpell, 1, new QTableWidgetItem("Ennemie"));
            else if(r.spellCible == SpellCible::ALLY)
                ui->tableWidgetSpells->setItem(indexSpell, 1, new QTableWidgetItem("Allié"));
            else if(r.spellCible == SpellCible::DIRECTION)
                ui->tableWidgetSpells->setItem(indexSpell, 1, new QTableWidgetItem("Direction"));
            else if(r.spellCible == SpellCible::SELF)
                ui->tableWidgetSpells->setItem(indexSpell, 1, new QTableWidgetItem("Moi"));
            ui->tableWidgetSpells->setItem(indexSpell, 2, new QTableWidgetItem(QString::number(r.castNb)));

            indexSpell++;
        }
    }
}

void FightForm::on_pushButtonDeleteSpell_clicked()
{
    int indexRow = ui->tableWidgetSpells->currentRow();

    QList<RequestedSpell> rs = m_engine->getFightModule().getRequestedSpells(m_sender);
    rs.removeAt(indexRow);
    m_engine->getFightModule().setRequestedSpells(m_sender, rs);

    for(int i = 0; i < ui->tableWidgetSpells->columnCount(); i++)
    {
        delete ui->tableWidgetSpells->item(indexRow, i);
    }

    ui->tableWidgetSpells->removeRow(indexRow);
}

void FightForm::on_comboBoxPositionFight_currentIndexChanged(int index)
{
    switch (index) {
    case 0: // Aucun
        m_engine->getFightModule().setFightPlacementPosition(m_sender, FightPlacementPosition::NONE);
        break;
    case 1: // Proche des ennemies
        m_engine->getFightModule().setFightPlacementPosition(m_sender, FightPlacementPosition::NEARFUL);
        break;
    case 2: // Loin des ennemies
        m_engine->getFightModule().setFightPlacementPosition(m_sender, FightPlacementPosition::FARTHER);
        break;
    }
}

void FightForm::on_comboBoxCloseFight_currentIndexChanged(int index)
{
    switch (index) {
    case 0: // Aucun
        m_engine->getFightModule().setClosed(m_sender, false);
        break;
    case 1: // Bloquer si quelqu'un entre
        // TODO : make a cup of coffe LOL
        break;
    case 2: // Bloquer
        m_engine->getFightModule().setClosed(m_sender, true);
        break;
    }
}

void FightForm::on_comboBoxSpectator_currentIndexChanged(int index)
{
    switch (index) {
    case 0: // Aucun
        m_engine->getFightModule().setSecret(m_sender, false);
        break;
    case 1: // Bloquer si quelqu'un entre
        // TODO : make a cup of coffe LOL
        break;
    case 2: // Bloquer
        m_engine->getFightModule().setSecret(m_sender, true);
        break;
    }
}

void FightForm::on_comboBoxBehavior_currentIndexChanged(int index)
{
    switch (index)
    {
    case 0: // Fuyard, Craintif
        m_engine->getFightModule().setFightIA(m_sender, FightIA::FEARFUL);
        break;
    case 1: // Agressif
        m_engine->getFightModule().setFightIA(m_sender, FightIA::AGGRESSIVE);
        break;
    case 2: // Passif
        m_engine->getFightModule().setFightIA(m_sender, FightIA::FOLLOWER);
        break;
    }
}

void FightForm::on_spinBoxRegenerationMin_valueChanged(int arg1)
{
    m_engine->getStatsModule().setRegenerationRatio(m_sender, arg1, ui->spinBoxRegenerationMax->value());
}

void FightForm::on_spinBoxRegenerationMax_valueChanged(int arg1)
{
    m_engine->getStatsModule().setRegenerationRatio(m_sender, ui->spinBoxRegenerationMin->value(), arg1);
}
