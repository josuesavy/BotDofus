#include "HaapiConfirmationMessage.h"

void HaapiConfirmationMessage::serialize(Writer *output)
{
  this->serializeAs_HaapiConfirmationMessage(output);
}

void HaapiConfirmationMessage::serializeAs_HaapiConfirmationMessage(Writer *output)
{
  if(this->kamas < 0 || this->kamas > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - HaapiConfirmationMessage -"<<"Forbidden value (" << this->kamas << ") on element kamas.";
  }
  output->writeVarLong((double)this->kamas);
  if(this->amount < 0 || this->amount > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - HaapiConfirmationMessage -"<<"Forbidden value (" << this->amount << ") on element amount.";
  }
  output->writeVarLong((double)this->amount);
  if(this->rate < 0)
  {
    qDebug()<<"ERREUR - HaapiConfirmationMessage -"<<"Forbidden value (" << this->rate << ") on element rate.";
  }
  output->writeVarShort((int)this->rate);
  output->writeByte(this->action);
  output->writeUTF(this->transaction);
}

void HaapiConfirmationMessage::deserialize(Reader *input)
{
  this->deserializeAs_HaapiConfirmationMessage(input);
}

void HaapiConfirmationMessage::deserializeAs_HaapiConfirmationMessage(Reader *input)
{
  this->_kamasFunc(input);
  this->_amountFunc(input);
  this->_rateFunc(input);
  this->_actionFunc(input);
  this->_transactionFunc(input);
}

void HaapiConfirmationMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_HaapiConfirmationMessage(tree);
}

void HaapiConfirmationMessage::deserializeAsyncAs_HaapiConfirmationMessage(FuncTree tree)
{
  tree.addChild(std::bind(&HaapiConfirmationMessage::_kamasFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HaapiConfirmationMessage::_amountFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HaapiConfirmationMessage::_rateFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HaapiConfirmationMessage::_actionFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HaapiConfirmationMessage::_transactionFunc, this, std::placeholders::_1));
}

void HaapiConfirmationMessage::_kamasFunc(Reader *input)
{
  this->kamas = input->readVarUhLong();
  if(this->kamas < 0 || this->kamas > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - HaapiConfirmationMessage -"<<"Forbidden value (" << this->kamas << ") on element of HaapiConfirmationMessage.kamas.";
  }
}

void HaapiConfirmationMessage::_amountFunc(Reader *input)
{
  this->amount = input->readVarUhLong();
  if(this->amount < 0 || this->amount > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - HaapiConfirmationMessage -"<<"Forbidden value (" << this->amount << ") on element of HaapiConfirmationMessage.amount.";
  }
}

void HaapiConfirmationMessage::_rateFunc(Reader *input)
{
  this->rate = input->readVarUhShort();
  if(this->rate < 0)
  {
    qDebug()<<"ERREUR - HaapiConfirmationMessage -"<<"Forbidden value (" << this->rate << ") on element of HaapiConfirmationMessage.rate.";
  }
}

void HaapiConfirmationMessage::_actionFunc(Reader *input)
{
  this->action = input->readByte();
  if(this->action < 0)
  {
    qDebug()<<"ERREUR - HaapiConfirmationMessage -"<<"Forbidden value (" << this->action << ") on element of HaapiConfirmationMessage.action.";
  }
}

void HaapiConfirmationMessage::_transactionFunc(Reader *input)
{
  this->transaction = input->readUTF();
}

HaapiConfirmationMessage::HaapiConfirmationMessage()
{
  m_type = MessageEnum::HAAPICONFIRMATIONMESSAGE;
}

