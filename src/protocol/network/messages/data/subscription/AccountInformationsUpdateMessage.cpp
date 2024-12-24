#include "AccountInformationsUpdateMessage.h"

void AccountInformationsUpdateMessage::serialize(Writer *output)
{
  this->serializeAs_AccountInformationsUpdateMessage(output);
}

void AccountInformationsUpdateMessage::serializeAs_AccountInformationsUpdateMessage(Writer *output)
{
  if(this->subscriptionEndDate < 0 || this->subscriptionEndDate > 9007199254740992)
  {
    qDebug()<<"ERREUR - AccountInformationsUpdateMessage -"<<"Forbidden value (" << this->subscriptionEndDate << ") on element subscriptionEndDate.";
  }
  output->writeDouble(this->subscriptionEndDate);
}

void AccountInformationsUpdateMessage::deserialize(Reader *input)
{
  this->deserializeAs_AccountInformationsUpdateMessage(input);
}

void AccountInformationsUpdateMessage::deserializeAs_AccountInformationsUpdateMessage(Reader *input)
{
  this->_subscriptionEndDateFunc(input);
}

void AccountInformationsUpdateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AccountInformationsUpdateMessage(tree);
}

void AccountInformationsUpdateMessage::deserializeAsyncAs_AccountInformationsUpdateMessage(FuncTree tree)
{
  tree.addChild(std::bind(&AccountInformationsUpdateMessage::_subscriptionEndDateFunc, this, std::placeholders::_1));
}

void AccountInformationsUpdateMessage::_subscriptionEndDateFunc(Reader *input)
{
  this->subscriptionEndDate = input->readDouble();
  if(this->subscriptionEndDate < 0 || this->subscriptionEndDate > 9007199254740992)
  {
    qDebug()<<"ERREUR - AccountInformationsUpdateMessage -"<<"Forbidden value (" << this->subscriptionEndDate << ") on element of AccountInformationsUpdateMessage.subscriptionEndDate.";
  }
}

AccountInformationsUpdateMessage::AccountInformationsUpdateMessage()
{
  m_type = MessageEnum::ACCOUNTINFORMATIONSUPDATEMESSAGE;
}

