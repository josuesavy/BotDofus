#include "floodform.h"
#include "ui_floodform.h"

FloodForm::FloodForm(ProcessEngine *engine, const ConnectionInfos &infos, SocketIO *sender, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FloodForm)
{
    ui->setupUi(this);

    // Liste d'initialisations
    m_engine = engine;
    m_infos = infos;
    m_sender = sender;

    ui->tableWidgetFlood->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
}

FloodForm::~FloodForm()
{
    delete ui;
}

SocketIO *FloodForm::getSocket()
{
    return m_sender;
}

ConnectionInfos FloodForm::getConnectionInfos() const
{
    return m_infos;
}

void FloodForm::updateInterface(bool directCall)
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

const BotData &FloodForm::getData() const
{
    return m_engine->getData(m_sender);
}

void FloodForm::on_pushButtonAddFlood_clicked()
{
    // Declarations
    QDialog *dialog = new QDialog(this);
    QGridLayout *layout = new QGridLayout(dialog);

    QLineEdit *lineEditMessage = new QLineEdit(dialog);

    QRadioButton *radioButtonPublic = new QRadioButton(dialog);
    QGroupBox *groupBoxPublic = new QGroupBox(dialog);
    QGridLayout *gridLayoutPublic = new QGridLayout(groupBoxPublic);
    QLabel *label1 = new QLabel(groupBoxPublic);
    QComboBox *comboBoxCanal = new QComboBox(groupBoxPublic);
    QLabel *label2 = new QLabel(groupBoxPublic);
    QTimeEdit *timeEditInterval = new QTimeEdit(QTime(0,0,10), groupBoxPublic);

    QRadioButton *radioButtonPrivate = new QRadioButton(dialog);
    QGroupBox *groupBoxPrivate = new QGroupBox(dialog);
    QVBoxLayout *vBoxLayoutPrivate = new QVBoxLayout(groupBoxPrivate);
    QCheckBox *checkBoxEnterMap = new QCheckBox(groupBoxPrivate);
    QCheckBox *checkBoxExitMap = new QCheckBox(groupBoxPrivate);

    QHBoxLayout *hBoxLayout = new QHBoxLayout(dialog);
    QPushButton *pushButtonAdd = new QPushButton(dialog);
    QPushButton *pushButtonCancel = new QPushButton(dialog);

    // Connections
    connect(radioButtonPublic, SIGNAL(clicked(bool)), groupBoxPublic, SLOT(setChecked(bool)));
    connect(radioButtonPrivate, SIGNAL(clicked(bool)), groupBoxPrivate, SLOT(setChecked(bool)));

    connect(pushButtonAdd, &QPushButton::clicked, dialog, &QDialog::accept);
    connect(pushButtonCancel, &QPushButton::clicked, dialog, &QDialog::reject);

    // Setting up
    gridLayoutPublic->addWidget(label1, 0,0);
    gridLayoutPublic->addWidget(comboBoxCanal, 0,1);
    gridLayoutPublic->addWidget(label2, 1,0);
    gridLayoutPublic->addWidget(timeEditInterval, 1,1);
    groupBoxPublic->setLayout(gridLayoutPublic);

    vBoxLayoutPrivate->addWidget(checkBoxEnterMap);
    vBoxLayoutPrivate->addWidget(checkBoxExitMap);
    groupBoxPrivate->setLayout(vBoxLayoutPrivate);

    hBoxLayout->addWidget(pushButtonAdd);
    hBoxLayout->addWidget(pushButtonCancel);

    layout->addWidget(lineEditMessage,0,0,1,2);
    layout->addWidget(radioButtonPublic,1,0);
    layout->addWidget(groupBoxPublic,1,1);
    layout->addWidget(radioButtonPrivate,2,0);
    layout->addWidget(groupBoxPrivate,2,1);
    layout->addLayout(hBoxLayout,3,0,1,2);

    // Editions
    lineEditMessage->setPlaceholderText("Message à flooder");

    radioButtonPublic->setText("Public");
    radioButtonPublic->setChecked(true);
    groupBoxPublic->setCheckable(true);
    label1->setText("Destinataires des messages");
    comboBoxCanal->addItem("Général");
    comboBoxCanal->addItem("Guilde");
    comboBoxCanal->addItem("Alliance");
    comboBoxCanal->addItem("Groupe");
    comboBoxCanal->addItem("Commerce");
    comboBoxCanal->addItem("Recrutement");
    label2->setText("Intervalle entre les messages");
    timeEditInterval->setTimeRange(QTime(0,0,1), QTime(23,59,59));
    timeEditInterval->setDisplayFormat("hh:mm:ss");
    timeEditInterval->setCurrentSection(QDateTimeEdit::SecondSection);

    radioButtonPrivate->setText("Privé");
    groupBoxPrivate->setCheckable(true);
    checkBoxEnterMap->setText("Quand quelqu'un entre sur la carte");
    checkBoxExitMap->setText("Quand quelqu'un quitte la carte");

    pushButtonAdd->setIcon(QIcon(":/icons/plus_16px.ico"));
    pushButtonAdd->setText("Ajouter");
    pushButtonCancel->setIcon(QIcon(":/icons/cancel_16px.ico"));
    pushButtonCancel->setText("Annuler");

    //dialog->setLayout(layout);
    if(dialog->exec() == QDialog::Accepted)
    {

    }
}
