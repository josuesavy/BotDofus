#include "inventoryform.h"
#include "ui_inventoryform.h"

InventoryForm::InventoryForm(ProcessEngine *engine, const ConnectionInfos &infos, SocketIO *sender, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InventoryForm)
{
    ui->setupUi(this);

    // Liste d'initialisations
    m_engine = engine;
    m_infos = infos;
    m_sender = sender;

    ui->tabWidgetInventory->setCurrentIndex(0);
    ui->tableWidgetResources->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Stretch);
    ui->tableWidgetEquipment->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Stretch);
    ui->tableWidgetUsableItems->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Stretch);
    ui->tableWidgetQuestItems->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Stretch);
}

InventoryForm::~InventoryForm()
{
    resetInventory();

    delete ui;
}

SocketIO *InventoryForm::getSocket()
{
    return m_sender;
}

ConnectionInfos InventoryForm::getConnectionInfos() const
{
    return m_infos;
}

const BotData &InventoryForm::getData() const
{
    return m_engine->getData(m_sender);
}

void InventoryForm::updateInterface()
{
    const BotData &infos = getData();

    if (infos.connectionData.connectionState == ConnectionState::CONNECTED)
    {
        QModelIndex currentEquipementIndex = ui->tableWidgetEquipment->currentIndex();
        QModelIndex currentUsableIndex = ui->tableWidgetUsableItems->currentIndex();
        QModelIndex currentResourceIndex = ui->tableWidgetResources->currentIndex();
        QModelIndex currentQuestIndex = ui->tableWidgetQuestItems->currentIndex();

        uint level = 0;
        if(infos.mapData.gameContext == GameContextEnum::ROLE_PLAY)
            level = infos.mapData.playersOnMap[infos.mapData.botId].level;

        else if(infos.mapData.gameContext == GameContextEnum::FIGHT)
            level = infos.fightData.fighters[infos.fightData.botFightData.botId].level;

        resetInventory();

        // Filling inventories
        m_inventoryContent = infos.playerData.inventoryContent;

        int indexEquipment = 0, indexConsumable = 0, indexResource = 0, indexQuest = 0, j = 0;
        foreach(InventoryObject i, m_inventoryContent)
        {
            QSharedPointer<ItemData> c = D2OManagerSingleton::get()->getItem(i.GID);
            QSharedPointer<ItemTypeData> itemTypeData = qSharedPointerCast<ItemTypeData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::ITEMTYPES, c->getTypeId()));

            // Alimentation de la liste des equipements
            if(itemTypeData->getCategoryId() == (uint)InventoryCategorie::EQUIPEMENT_CATEGORY)
            {
                ui->tableWidgetEquipment->insertRow(ui->tableWidgetEquipment->rowCount());
                ui->tableWidgetEquipment->setItem(indexEquipment, 0, new QTableWidgetItem(QIcon(D2PManagerSingleton::get()->getImage(QString::number(c->getIconId()))), c->getName()));
                ui->tableWidgetEquipment->setItem(indexEquipment, 1, new QTableWidgetItem(QString::number(i.quantity)));
                QTableWidgetItem *tableWidgetItemTemp = new QTableWidgetItem(QString::number(i.GID));
                tableWidgetItemTemp->setData(Qt::UserRole, i.UID);
                ui->tableWidgetEquipment->setItem(indexEquipment, 2, tableWidgetItemTemp);

                if(!i.isEquipped)
                    ui->tableWidgetEquipment->setItem(indexEquipment, 3, new QTableWidgetItem(QString("Not equipped")));
                else
                    ui->tableWidgetEquipment->setItem(indexEquipment, 3, new QTableWidgetItem(itemTypeData->getName()));


                if(!i.isEquipped)
                    pushButtonEquipEquipement = new QPushButton("Equip");
                else
                    pushButtonEquipEquipement = new QPushButton("Unequip");

                if (c->getLevel() <= level)
                {
                    connect(pushButtonEquipEquipement, SIGNAL(clicked()), this, SLOT(equipEquipement()));
                    ui->tableWidgetEquipment->setCellWidget(indexEquipment, 4, pushButtonEquipEquipement);
                }
                else
                {
                    pushButtonEquipEquipement = nullptr;
                    ui->tableWidgetEquipment->setItem(indexEquipment, 4, new QTableWidgetItem(QString("Lvl.%1 required").arg(c->getLevel())));
                }


                pushButtonThrowEquipement = new QPushButton("Throw");
                connect(pushButtonThrowEquipement, SIGNAL(clicked()), this, SLOT(throwEquipement()));
                ui->tableWidgetEquipment->setCellWidget(indexEquipment, 5, pushButtonThrowEquipement);

                pushButtonDeleteEquipement = new QPushButton("Delete");
                connect(pushButtonDeleteEquipement, SIGNAL(clicked()), this, SLOT(deleteEquipement()));
                ui->tableWidgetEquipment->setCellWidget(indexEquipment, 6, pushButtonDeleteEquipement);

                indexEquipment++;
            }

            // Alimentation de la liste des objets utilisable
            if(itemTypeData->getCategoryId() == (uint)InventoryCategorie::CONSUMABLES_CATEGORY)
            {
                ui->tableWidgetUsableItems->insertRow(ui->tableWidgetUsableItems->rowCount());
                ui->tableWidgetUsableItems->setItem(indexConsumable, 0, new QTableWidgetItem(QIcon(D2PManagerSingleton::get()->getImage(QString::number(c->getIconId()))), c->getName()));
                ui->tableWidgetUsableItems->setItem(indexConsumable, 1, new QTableWidgetItem(QString::number(i.quantity)));
                QTableWidgetItem *tableWidgetItemTemp = new QTableWidgetItem(QString::number(i.GID));
                tableWidgetItemTemp->setData(Qt::UserRole, i.UID);
                ui->tableWidgetUsableItems->setItem(indexConsumable, 2, tableWidgetItemTemp);

                pushButtonUseUsableItem = new QPushButton("Use");
                connect(pushButtonUseUsableItem, SIGNAL(clicked()), this, SLOT(useUsable()));
                ui->tableWidgetUsableItems->setCellWidget(indexConsumable, 3, pushButtonUseUsableItem);

                pushButtonThrowUsableItem = new QPushButton("Throw");
                connect(pushButtonThrowUsableItem, SIGNAL(clicked()), this, SLOT(throwUsable()));
                ui->tableWidgetUsableItems->setCellWidget(indexConsumable, 4, pushButtonThrowUsableItem);

                pushButtonDeleteUsableItem = new QPushButton("Delete");
                connect(pushButtonDeleteUsableItem, SIGNAL(clicked()), this, SLOT(deleteUsable()));
                ui->tableWidgetUsableItems->setCellWidget(indexConsumable, 5, pushButtonDeleteUsableItem);

                indexConsumable++;
            }

            // Alimentation de la liste des ressources
            if(itemTypeData->getCategoryId() == (uint)InventoryCategorie::RESSOURCES_CATEGORY)
            {
                ui->tableWidgetResources->insertRow(ui->tableWidgetResources->rowCount());
                ui->tableWidgetResources->setItem(indexResource, 0, new QTableWidgetItem(QIcon(D2PManagerSingleton::get()->getImage(QString::number(c->getIconId()))), c->getName()));
                ui->tableWidgetResources->setItem(indexResource, 1, new QTableWidgetItem(QString::number(i.quantity)));
                QTableWidgetItem *tableWidgetItemTemp = new QTableWidgetItem(QString::number(i.GID));
                tableWidgetItemTemp->setData(Qt::UserRole, i.UID);
                ui->tableWidgetResources->setItem(indexResource, 2, tableWidgetItemTemp);

                pushButtonThrowResource = new QPushButton("Throw");
                connect(pushButtonThrowResource, SIGNAL(clicked()), this, SLOT(throwResource()));
                ui->tableWidgetResources->setCellWidget(indexResource, 3, pushButtonThrowResource);

                pushButtonDeleteResource = new QPushButton("Delete");
                connect(pushButtonDeleteResource, SIGNAL(clicked()), this, SLOT(deleteResource()));
                ui->tableWidgetResources->setCellWidget(indexResource, 4, pushButtonDeleteResource);

                indexResource++;
            }

            // Alimentation de la liste des objets de quete
            if(itemTypeData->getCategoryId() == (uint)InventoryCategorie::QUEST_CATEGORY)
            {
                ui->tableWidgetQuestItems->insertRow(ui->tableWidgetQuestItems->rowCount());
                ui->tableWidgetQuestItems->setItem(indexQuest, 0, new QTableWidgetItem(QIcon(D2PManagerSingleton::get()->getImage(QString::number(c->getIconId()))), c->getName()));
                ui->tableWidgetQuestItems->setItem(indexQuest, 1, new QTableWidgetItem(QString::number(i.quantity)));
                QTableWidgetItem *tableWidgetItemTemp = new QTableWidgetItem(QString::number(i.GID));
                tableWidgetItemTemp->setData(Qt::UserRole, i.UID);
                ui->tableWidgetQuestItems->setItem(indexQuest, 2, tableWidgetItemTemp);

                indexQuest++;
            }

            j++;
        }

        ui->tableWidgetEquipment->setCurrentIndex(currentEquipementIndex);
        ui->tableWidgetUsableItems->setCurrentIndex(currentUsableIndex);
        ui->tableWidgetResources->setCurrentIndex(currentResourceIndex);
        ui->tableWidgetQuestItems->setCurrentIndex(currentQuestIndex);
    }

    if (infos.connectionData.connectionState == ConnectionState::TRANSITION)
    {
        resetInventory();
    }

    if (infos.connectionData.connectionState == ConnectionState::DISCONNECTED)
    {
        resetInventory();
    }
}

void InventoryForm::resetInventory()
{
    // Empty all inventories categories
    m_inventoryContent.clear();

    ui->tableWidgetEquipment->setRowCount(0);
    ui->tableWidgetUsableItems->setRowCount(0);
    ui->tableWidgetResources->setRowCount(0);
    ui->tableWidgetQuestItems->setRowCount(0);
}

void InventoryForm::equipEquipement()
{
    QPushButton *pushButttonSender = qobject_cast<QPushButton *>(sender());
    if(pushButttonSender)
    {
        int row = ui->tableWidgetEquipment->indexAt(pushButttonSender->pos()).row();

        int indexGID = ui->tableWidgetEquipment->item(row, 2)->text().toInt();
        int indexUID = ui->tableWidgetEquipment->item(row, 2)->data(Qt::UserRole).toUInt();
        bool isEquipped = false;

        for(int i=0; i < getData().playerData.inventoryContent.size(); i++)
        {
            if(indexGID == getData().playerData.inventoryContent.at(i).GID && indexUID == getData().playerData.inventoryContent.at(i).UID)
            {
                isEquipped = getData().playerData.inventoryContent.at(i).isEquipped;
                break;
            }
        }

        if(isEquipped)
        {
            qDebug()<<"ACCOUNTFORM - UNEQUIP ITEM"<<indexUID;
            m_engine->getStatsManager().unequipItem(m_sender, indexUID);
        }
        else
        {
            qDebug()<<"ACCOUNTFORM - EQUIP ITEM"<<indexUID;
            m_engine->getStatsManager().equipItem(m_sender, indexUID);
        }
    }
}

void InventoryForm::throwEquipement()
{
    QPushButton *pushButttonSender = qobject_cast<QPushButton *>(sender());
    if(pushButttonSender)
    {
        int row = ui->tableWidgetEquipment->indexAt(pushButttonSender->pos()).row();

        int indexUID = ui->tableWidgetEquipment->item(row, 2)->data(Qt::UserRole).toUInt();
        int quantity = ui->tableWidgetEquipment->item(row, 1)->text().toInt();

        if(quantity > 1)
        {
            bool ok;
            int q = QInputDialog::getInt(this, tr("Confirmation"), tr("Quantity"), quantity, 0, quantity, 1, &ok);
            if (ok && q != 0)
                quantity = q;
            else
                return;
        }

        qDebug()<<"ACCOUNTFORM - DESTROY"<<indexUID<<" - QUANTITY"<<quantity;
        m_engine->getStatsManager().throwItem(m_sender, indexUID, quantity);

        ui->tableWidgetEquipment->removeRow(row);
    }
}

void InventoryForm::deleteEquipement()
{
    QPushButton *pushButttonSender = qobject_cast<QPushButton *>(sender());
    if(pushButttonSender)
    {
        int row = ui->tableWidgetEquipment->indexAt(pushButttonSender->pos()).row();

        int indexUID = ui->tableWidgetEquipment->item(row, 2)->data(Qt::UserRole).toUInt();
        int quantity = ui->tableWidgetEquipment->item(row, 1)->text().toInt();

        if(quantity > 1)
        {
            bool ok;
            int q = QInputDialog::getInt(this, tr("Confirmation"), tr("Quantity"), quantity, 0, quantity, 1, &ok);
            if (ok && q != 0)
                quantity = q;
            else
                return;
        }

        qDebug()<<"ACCOUNTFORM - DESTROY"<<indexUID<<" - QUANTITY"<<quantity;
        m_engine->getStatsManager().destroyItem(m_sender, indexUID, quantity);

        ui->tableWidgetEquipment->removeRow(row);
    }
}

void InventoryForm::useUsable()
{
    QPushButton *pushButttonSender = qobject_cast<QPushButton *>(sender());
    if(pushButttonSender)
    {
        int row = ui->tableWidgetUsableItems->indexAt(pushButttonSender->pos()).row();

        int indexUID = ui->tableWidgetEquipment->item(row, 2)->data(Qt::UserRole).toUInt();

        qDebug()<<"ACCOUNTFORM - USE ITEM"<<indexUID;
        m_engine->getStatsManager().useItem(m_sender, indexUID);
    }
}

void InventoryForm::throwUsable()
{
    QPushButton *pushButttonSender = qobject_cast<QPushButton *>(sender());
    if(pushButttonSender)
    {
        int row = ui->tableWidgetUsableItems->indexAt(pushButttonSender->pos()).row();

        int indexUID = ui->tableWidgetEquipment->item(row, 2)->data(Qt::UserRole).toUInt();
        int quantity = ui->tableWidgetEquipment->item(row, 1)->text().toInt();

        if(quantity > 1)
        {
            bool ok;
            int q = QInputDialog::getInt(this, tr("Confirmation"), tr("Quantity"), quantity, 0, quantity, 1, &ok);
            if (ok && q != 0)
                quantity = q;
            else
                return;
        }

        qDebug()<<"ACCOUNTFORM - DESTROY"<<indexUID<<" - QUANTITY"<<quantity;
        m_engine->getStatsManager().throwItem(m_sender, indexUID, quantity);

        ui->tableWidgetEquipment->removeRow(row);
    }
}

void InventoryForm::deleteUsable()
{
    QPushButton *pushButttonSender = qobject_cast<QPushButton *>(sender());
    if(pushButttonSender)
    {
        int row = ui->tableWidgetUsableItems->indexAt(pushButttonSender->pos()).row();

        int indexUID = ui->tableWidgetEquipment->item(row, 2)->data(Qt::UserRole).toUInt();
        int quantity = ui->tableWidgetUsableItems->item(row, 1)->text().toInt();

        if(quantity > 1)
        {
            bool ok;
            int q = QInputDialog::getInt(this, tr("Confirmation"), tr("Quantity"), quantity, 0, quantity, 1, &ok);
            if (ok && q != 0)
                quantity = q;
            else
                return;
        }

        qDebug()<<"ACCOUNTFORM - DESTROY"<<indexUID<<" - QUANTITY"<<quantity;
        m_engine->getStatsManager().destroyItem(m_sender, indexUID, quantity);

        ui->tableWidgetUsableItems->removeRow(row);
    }
}

void InventoryForm::throwResource()
{
    QPushButton *pushButttonSender = qobject_cast<QPushButton *>(sender());
    if(pushButttonSender)
    {
        int row = ui->tableWidgetResources->indexAt(pushButttonSender->pos()).row();

        int indexUID = ui->tableWidgetEquipment->item(row, 2)->data(Qt::UserRole).toUInt();
        int quantity = ui->tableWidgetResources->item(row, 1)->text().toInt();

        if(quantity > 1)
        {
            bool ok;
            int q = QInputDialog::getInt(this, tr("Confirmation"), tr("Quantity"), quantity, 0, quantity, 1, &ok);
            if (ok && q != 0)
                quantity = q;
            else
                return;
        }

        qDebug()<<"ACCOUNTFORM - DESTROY"<<indexUID<<" - QUANTITY"<<quantity;
        m_engine->getStatsManager().throwItem(m_sender, indexUID, quantity);

        ui->tableWidgetResources->removeRow(row);
    }
}

void InventoryForm::deleteResource()
{
    QPushButton *pushButttonSender = qobject_cast<QPushButton *>(sender());
    if(pushButttonSender)
    {
        int row = ui->tableWidgetResources->indexAt(pushButttonSender->pos()).row();

        int indexUID = ui->tableWidgetEquipment->item(row, 2)->data(Qt::UserRole).toUInt();
        int quantity = ui->tableWidgetResources->item(row, 1)->text().toInt();

        if(quantity > 1)
        {
            bool ok;
            int q = QInputDialog::getInt(this, tr("Confirmation"), tr("Quantity"), quantity, 0, quantity, 1, &ok);
            if (ok && q != 0)
                quantity = q;
            else
                return;
        }

        qDebug()<<"ACCOUNTFORM - DESTROY"<<indexUID<<" - QUANTITY"<<quantity;
        m_engine->getStatsManager().destroyItem(m_sender, indexUID, quantity);

        ui->tableWidgetResources->removeRow(row);
    }
}
