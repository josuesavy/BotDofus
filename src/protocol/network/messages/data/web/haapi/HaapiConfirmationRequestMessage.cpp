#include "HaapiConfirmationRequestMessage.h"

void HaapiConfirmationRequestMessage::serialize(Writer *output)
{
  this->serializeAs_HaapiConfirmationRequestMessage(output);
}

void HaapiConfirmationRequestMessage::serializeAs_HaapiConfirmationRequestMessage(Writer *output)
{
  if(this->kamas < 0 || this->kamas > 9007199254740992)
  {
    qDebug()<<"ERREUR - HaapiConfirmationRequestMessage -"<<"Forbidden value (" << this->kamas << ") on element kamas.";
  }
  output->writeVarLong((double)this->kamas);
  if(this->ogrines < 0 || this->ogrines > 9007199254740992)
  {
    qDebug()<<"ERREUR - HaapiConfirmationRequestMessage -"<<"Forbidden value (" << this->ogrines << ") on element ogrines.";
  }
  output->writeVarLong((double)this->ogrines);
  if(this->rate < 0)
  {
    qDebug()<<"ERREUR - HaapiConfirmationRequestMessage -"<<"Forbidden value (" << this->rate << ") on element rate.";
  }
  output->writeVarShort((int)this->rate);
  output->writeByte(this->action);
}

void HaapiConfirmationRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_HaapiConfirmationRequestMessage(input);
}

void HaapiConfirmationRequestMessage::deserializeAs_HaapiConfirmationRequestMessage(Reader *input)
{
  this->_kamasFunc(input);
  this->_ogrinesFunc(input);
  this->_rateFunc(input);
  this->_actionFunc(input);
}

void HaapiConfirmationRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_HaapiConfirmationRequestMessage(tree);
}

void HaapiConfirmationRequestMessage::deserializeAsyncAs_HaapiConfirmationRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&HaapiConfirmationRequestMessage::_kamasFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HaapiConfirmationRequestMessage::_ogrinesFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HaapiConfirmationRequestMessage::_rateFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HaapiConfirmationRequestMessage::_actionFunc, this, std::placeholders::_1));
}

void HaapiConfirmationRequestMessage::_kamasFunc(Reader *input)
{
  this->kamas = input->readVarUhLong();
  if(this->kamas < 0 || this->kamas > 9007199254740992)
  {
    qDebug()<<"ERREUR - HaapiConfirmationRequestMessage -"<<"Forbidden value (" << this->kamas << ") on element of HaapiConfirmationRequestMessage.kamas.";
  }
}

void HaapiConfirmationRequestMessage::_ogrinesFunc(Reader *input)
{
  this->ogrines = input->readVarUhLong();
  if(this->ogrines < 0 || this->ogrines > 9007199254740992)
  {
    qDebug()<<"ERREUR - HaapiConfirmationRequestMessage -"<<"Forbidden value (" << this->ogrines << ") on element of HaapiConfirmationRequestMessage.ogrines.";
  }
}

void HaapiConfirmationRequestMessage::_rateFunc(Reader *input)
{
  this->rate = input->readVarUhShort();
  if(this->rate < 0)
  {
    qDebug()<<"ERREUR - HaapiConfirmationRequestMessage -"<<"Forbidden value (" << this->rate << ") on element of HaapiConfirmationRequestMessage.rate.";
  }
}

void HaapiConfirmationRequestMessage::_actionFunc(Reader *input)
{
  this->action = input->readByte();
  if(this->action < 0)
  {
    qDebug()<<"ERREUR - HaapiConfirmationRequestMessage -"<<"Forbidden value (" << this->action << ") on element of HaapiConfirmationRequestMessage.action.";
  }
}

HaapiConfirmationRequestMessage::HaapiConfirmationRequestMessage()
{
  m_type = MessageEnum::HAAPICONFIRMATIONREQUESTMESSAGE;
}

