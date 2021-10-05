#include "HaapiCancelBidRequestMessage.h"

void HaapiCancelBidRequestMessage::serialize(Writer *output)
{
  this->serializeAs_HaapiCancelBidRequestMessage(output);
}

void HaapiCancelBidRequestMessage::serializeAs_HaapiCancelBidRequestMessage(Writer *output)
{
  if(this->id < 0 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - HaapiCancelBidRequestMessage -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  output->writeVarLong((double)this->id);
  output->writeByte(this->type);
}

void HaapiCancelBidRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_HaapiCancelBidRequestMessage(input);
}

void HaapiCancelBidRequestMessage::deserializeAs_HaapiCancelBidRequestMessage(Reader *input)
{
  this->_idFunc(input);
  this->_typeFunc(input);
}

void HaapiCancelBidRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_HaapiCancelBidRequestMessage(tree);
}

void HaapiCancelBidRequestMessage::deserializeAsyncAs_HaapiCancelBidRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&HaapiCancelBidRequestMessage::_idFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HaapiCancelBidRequestMessage::_typeFunc, this, std::placeholders::_1));
}

void HaapiCancelBidRequestMessage::_idFunc(Reader *input)
{
  this->id = input->readVarUhLong();
  if(this->id < 0 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - HaapiCancelBidRequestMessage -"<<"Forbidden value (" << this->id << ") on element of HaapiCancelBidRequestMessage.id.";
  }
}

void HaapiCancelBidRequestMessage::_typeFunc(Reader *input)
{
  this->type = input->readByte();
  if(this->type < 0)
  {
    qDebug()<<"ERREUR - HaapiCancelBidRequestMessage -"<<"Forbidden value (" << this->type << ") on element of HaapiCancelBidRequestMessage.type.";
  }
}

HaapiCancelBidRequestMessage::HaapiCancelBidRequestMessage()
{
  m_type = MessageEnum::HAAPICANCELBIDREQUESTMESSAGE;
}

