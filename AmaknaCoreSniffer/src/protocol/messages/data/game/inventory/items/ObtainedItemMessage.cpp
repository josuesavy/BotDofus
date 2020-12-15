#include "ObtainedItemMessage.h"

void ObtainedItemMessage::serialize(Writer *output)
{
  this->serializeAs_ObtainedItemMessage(output);
}

void ObtainedItemMessage::serializeAs_ObtainedItemMessage(Writer *output)
{
  if(this->genericId < 0)
  {
    qDebug()<<"ERREUR - ObtainedItemMessage -"<<"Forbidden value (" << this->genericId << ") on element genericId.";
  }
  output->writeVarShort((int)this->genericId);
  if(this->baseQuantity < 0)
  {
    qDebug()<<"ERREUR - ObtainedItemMessage -"<<"Forbidden value (" << this->baseQuantity << ") on element baseQuantity.";
  }
  output->writeVarInt((int)this->baseQuantity);
}

void ObtainedItemMessage::deserialize(Reader *input)
{
  this->deserializeAs_ObtainedItemMessage(input);
}

void ObtainedItemMessage::deserializeAs_ObtainedItemMessage(Reader *input)
{
  this->_genericIdFunc(input);
  this->_baseQuantityFunc(input);
}

void ObtainedItemMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ObtainedItemMessage(tree);
}

void ObtainedItemMessage::deserializeAsyncAs_ObtainedItemMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ObtainedItemMessage::_genericIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ObtainedItemMessage::_baseQuantityFunc, this, std::placeholders::_1));
}

void ObtainedItemMessage::_genericIdFunc(Reader *input)
{
  this->genericId = input->readVarUhShort();
  if(this->genericId < 0)
  {
    qDebug()<<"ERREUR - ObtainedItemMessage -"<<"Forbidden value (" << this->genericId << ") on element of ObtainedItemMessage.genericId.";
  }
}

void ObtainedItemMessage::_baseQuantityFunc(Reader *input)
{
  this->baseQuantity = input->readVarUhInt();
  if(this->baseQuantity < 0)
  {
    qDebug()<<"ERREUR - ObtainedItemMessage -"<<"Forbidden value (" << this->baseQuantity << ") on element of ObtainedItemMessage.baseQuantity.";
  }
}

ObtainedItemMessage::ObtainedItemMessage()
{
  m_type = MessageEnum::OBTAINEDITEMMESSAGE;
}

