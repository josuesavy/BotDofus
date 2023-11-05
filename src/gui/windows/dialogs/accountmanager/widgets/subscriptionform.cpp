#include "subscriptionform.h"
#include "ui_subscriptionform.h"

SubscriptionForm::SubscriptionForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SubscriptionForm)
{
    ui->setupUi(this);

    // Connexion du compte...
    // Choix du mode de paiement par defaut (Ogrine)
    // Choix de l'abonnement <b></b>...
    // Vous allez être débité
}

SubscriptionForm::~SubscriptionForm()
{
    delete ui;
}
