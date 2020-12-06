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

const BotData &FightForm::getData() const
{
    return m_engine->getData(m_sender);
}

void FightForm::updateInterface()
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

void FightForm::on_pushButtonMoveTopSpell_clicked()
{
    if (!ui->tableWidgetSpells->selectedItems().isEmpty())
    {
        int index = ui->tableWidgetSpells->row(ui->tableWidgetSpells->selectedItems().first());

        if (index)
        {
            QList<RequestedSpell> rs = m_engine->getFightManager().getRequestedSpells(m_sender);
            rs.move(index, index-1);
            m_engine->getFightManager().setRequestedSpells(m_sender, rs);

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
}

void FightForm::on_pushButtonMoveDownSpell_clicked()
{
    if (!ui->tableWidgetSpells->selectedItems().isEmpty())
    {
        int index = ui->tableWidgetSpells->row(ui->tableWidgetSpells->selectedItems().first());

        QList<RequestedSpell> rs = m_engine->getFightManager().getRequestedSpells(m_sender);

        if (index != rs.size()-1)
        {
            rs.move(index, index+1);
            m_engine->getFightManager().setRequestedSpells(m_sender, rs);

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
}

void FightForm::on_pushButtonAddSpell_clicked()
{
    const BotData &infos = getData();

    AddSpellDialog addSpellDialog(this, infos.playerData.spells);
    addSpellDialog.setParent(this, Qt::Dialog);
    if(addSpellDialog.exec() == QDialog::Accepted)
    {
        RequestedSpell requestedSpellToAdd;
        requestedSpellToAdd.spellID = addSpellDialog.getSpell();
        requestedSpellToAdd.castNb = addSpellDialog.getNbrCast();
        requestedSpellToAdd.spellCible = addSpellDialog.getTarget();

        QList<RequestedSpell> requestedSpells = m_engine->getFightManager().getRequestedSpells(m_sender);

        bool found = false;
        foreach (const RequestedSpell &requestedSpell, requestedSpells)
        {
            if (requestedSpell.spellID == requestedSpellToAdd.spellID)
            {
                found = true;
                break;
            }
        }

        if (!found)
        {
            while(ui->tableWidgetSpells->rowCount() > 0)
                ui->tableWidgetSpells->removeRow(0);

            requestedSpells << requestedSpellToAdd;

            m_engine->getFightManager().setRequestedSpells(m_sender, requestedSpells);

            int indexSpell = 0;
            QSharedPointer<SpellData> spellData;
            foreach(const RequestedSpell &requestedSpell, requestedSpells)
            {
                spellData = qSharedPointerCast<SpellData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SPELLS, requestedSpell.spellID));

                ui->tableWidgetSpells->insertRow(ui->tableWidgetSpells->rowCount());
                ui->tableWidgetSpells->setItem(indexSpell, 0, new QTableWidgetItem(spellData->getName()));

                if(requestedSpell.spellCible == SpellCible::ENEMY)
                    ui->tableWidgetSpells->setItem(indexSpell, 1, new QTableWidgetItem("Ennemie"));
                else if(requestedSpell.spellCible == SpellCible::ALLY)
                    ui->tableWidgetSpells->setItem(indexSpell, 1, new QTableWidgetItem("Allié"));
                else if(requestedSpell.spellCible == SpellCible::DIRECTION)
                    ui->tableWidgetSpells->setItem(indexSpell, 1, new QTableWidgetItem("Direction"));
                else if(requestedSpell.spellCible == SpellCible::SELF)
                    ui->tableWidgetSpells->setItem(indexSpell, 1, new QTableWidgetItem("Moi"));

                ui->tableWidgetSpells->setItem(indexSpell, 2, new QTableWidgetItem(QString::number(requestedSpell.castNb)));

                indexSpell++;
            }
        }

        else
            QMessageBox::critical(this, tr("Error"), tr("This spell has already been added."));
    }
}

void FightForm::on_pushButtonDeleteSpell_clicked()
{
    int indexRow = ui->tableWidgetSpells->currentRow();

    QList<RequestedSpell> rs = m_engine->getFightManager().getRequestedSpells(m_sender);
    rs.removeAt(indexRow);
    m_engine->getFightManager().setRequestedSpells(m_sender, rs);

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
        m_engine->getFightManager().setFightPlacementPosition(m_sender, FightPlacementPosition::NONE);
        break;
    case 1: // Proche des ennemies
        m_engine->getFightManager().setFightPlacementPosition(m_sender, FightPlacementPosition::NEARFUL);
        break;
    case 2: // Loin des ennemies
        m_engine->getFightManager().setFightPlacementPosition(m_sender, FightPlacementPosition::FARTHER);
        break;
    }
}

void FightForm::on_comboBoxCloseFight_currentIndexChanged(int index)
{
    switch (index) {
    case 0: // Aucun
        m_engine->getFightManager().setClosed(m_sender, false);
        break;
    case 1: // Bloquer si quelqu'un entre
        // TODO : make a cup of coffe LOL
        break;
    case 2: // Bloquer
        m_engine->getFightManager().setClosed(m_sender, true);
        break;
    }
}

void FightForm::on_comboBoxSpectator_currentIndexChanged(int index)
{
    switch (index) {
    case 0: // Aucun
        m_engine->getFightManager().setSecret(m_sender, false);
        break;
    case 1: // Bloquer si quelqu'un entre
        // TODO : make a cup of coffe LOL
        break;
    case 2: // Bloquer
        m_engine->getFightManager().setSecret(m_sender, true);
        break;
    }
}

void FightForm::on_comboBoxBehavior_currentIndexChanged(int index)
{
    switch (index)
    {
    case 0: // Fuyard, Craintif
        m_engine->getFightManager().setFightIA(m_sender, FightIA::FEARFUL);
        break;
    case 1: // Agressif
        m_engine->getFightManager().setFightIA(m_sender, FightIA::AGGRESSIVE);
        break;
    case 2: // Passif
        m_engine->getFightManager().setFightIA(m_sender, FightIA::FOLLOWER);
        break;
    }
}

void FightForm::on_spinBoxRegenerationMin_valueChanged(int arg1)
{
    m_engine->getStatsManager().setRegenerationRatio(m_sender, arg1, ui->spinBoxRegenerationMax->value());
}

void FightForm::on_spinBoxRegenerationMax_valueChanged(int arg1)
{
    m_engine->getStatsManager().setRegenerationRatio(m_sender, ui->spinBoxRegenerationMin->value(), arg1);
}
