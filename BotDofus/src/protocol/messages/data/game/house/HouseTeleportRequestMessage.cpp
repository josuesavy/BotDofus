#include "HouseTeleportRequestMessage.h"

void HouseTeleportRequestMessage::serialize(Writer *output)
{
  this->serializeAs_HouseTeleportRequestMessage(output);
}

void HouseTeleportRequestMessage::serializeAs_HouseTeleportRequestMessage(Writer *output)
{
  if(this->houseId < 0)
  {
    qDebug()<<"ERREUR - HouseTeleportRequestMessage -"<<"Forbidden value (" << this->houseId << ") on element houseId.";
  }
  output->writeVarInt((int)this->houseId);
  if(this->houseInstanceId < 0)
  {
    qDebug()<<"ERREUR - HouseTeleportRequestMessage -"<<"Forbidden value (" << this->houseInstanceId << ") on element houseInstanceId.";
  }
  output->writeInt((int)this->houseInstanceId);
}

void HouseTeleportRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_HouseTeleportRequestMessage(input);
}

void HouseTeleportRequestMessage::deserializeAs_HouseTeleportRequestMessage(Reader *input)
{
  this->_houseIdFunc(input);
  this->_houseInstanceIdFunc(input);
}

void HouseTeleportRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_HouseTeleportRequestMessage(tree);
}

void HouseTeleportRequestMessage::deserializeAsyncAs_HouseTeleportRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&HouseTeleportRequestMessage::_houseIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HouseTeleportRequestMessage::_houseInstanceIdFunc, this, std::placeholders::_1));
}

void HouseTeleportRequestMessage::_houseIdFunc(Reader *input)
{
  this->houseId = input->readVarUhInt();
  if(this->houseId < 0)
  {
    qDebug()<<"ERREUR - HouseTeleportRequestMessage -"<<"Forbidden value (" << this->houseId << ") on element of HouseTeleportRequestMessage.houseId.";
  }
}

void HouseTeleportRequestMessage::_houseInstanceIdFunc(Reader *input)
{
  this->houseInstanceId = input->readInt();
  if(this->houseInstanceId < 0)
  {
    qDebug()<<"ERREUR - HouseTeleportRequestMessage -"<<"Forbidden value (" << this->houseInstanceId << ") on element of HouseTeleportRequestMessage.houseInstanceId.";
  }
}

HouseTeleportRequestMessage::HouseTeleportRequestMessage()
{
  m_type = MessageEnum::HOUSETELEPORTREQUESTMESSAGE;
}

