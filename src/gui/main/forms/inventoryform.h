#ifndef INVENTORYFORM_H
#define INVENTORYFORM_H

#include <QWidget>
#include <QInputDialog>
#include <QPushButton>

#include "src/Engines/Core/Process/ProcessEngine.h"
#include "src/Engines/Storage/DataHandler.h"

namespace Ui {
class InventoryForm;
}

class InventoryForm : public QWidget
{
    Q_OBJECT

public:
    explicit InventoryForm(ProcessEngine *engine, const ConnectionInfos &infos, SocketIO *sender, QWidget *parent = nullptr);
    ~InventoryForm();

    SocketIO *getSocket();
    ConnectionInfos getConnectionInfos() const;

public slots:
    void updateInterface(bool directCall = true);

private slots:
    // Equipement
    void equipEquipement();
    void throwEquipement();
    void deleteEquipement();

    // Usable
    void useUsable();
    void throwUsable();
    void deleteUsable();

    // Resource
    void throwResource();
    void deleteResource();

private:
    Ui::InventoryForm *ui;

    SocketIO *m_sender;
    ProcessEngine *m_engine;
    ConnectionInfos m_infos;

    const BotData &getData() const;

    QList<InventoryObject> m_inventoryContent;

    QPushButton *pushButtonEquipEquipement;
    QPushButton *pushButtonThrowEquipement;
    QPushButton *pushButtonDeleteEquipement;

    QPushButton *pushButtonUseUsableItem;
    QPushButton *pushButtonThrowUsableItem;
    QPushButton *pushButtonDeleteUsableItem;

    QPushButton *pushButtonThrowResource;
    QPushButton *pushButtonDeleteResource;
};

#endif // INVENTORYFORM_H
