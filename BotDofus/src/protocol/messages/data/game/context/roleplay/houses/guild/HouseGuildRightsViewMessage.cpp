#include "HouseGuildRightsViewMessage.h"

void HouseGuildRightsViewMessage::serialize(Writer *output)
{
  this->serializeAs_HouseGuildRightsViewMessage(output);
}

void HouseGuildRightsViewMessage::serializeAs_HouseGuildRightsViewMessage(Writer *output)
{
  if(this->houseId < 0)
  {
    qDebug()<<"ERREUR - HouseGuildRightsViewMessage -"<<"Forbidden value (" << this->houseId << ") on element houseId.";
  }
  output->writeVarInt((int)this->houseId);
  if(this->instanceId < 0)
  {
    qDebug()<<"ERREUR - HouseGuildRightsViewMessage -"<<"Forbidden value (" << this->instanceId << ") on element instanceId.";
  }
  output->writeInt((int)this->instanceId);
}

void HouseGuildRightsViewMessage::deserialize(Reader *input)
{
  this->deserializeAs_HouseGuildRightsViewMessage(input);
}

void HouseGuildRightsViewMessage::deserializeAs_HouseGuildRightsViewMessage(Reader *input)
{
  this->_houseIdFunc(input);
  this->_instanceIdFunc(input);
}

void HouseGuildRightsViewMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_HouseGuildRightsViewMessage(tree);
}

void HouseGuildRightsViewMessage::deserializeAsyncAs_HouseGuildRightsViewMessage(FuncTree tree)
{
  tree.addChild(std::bind(&HouseGuildRightsViewMessage::_houseIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HouseGuildRightsViewMessage::_instanceIdFunc, this, std::placeholders::_1));
}

void HouseGuildRightsViewMessage::_houseIdFunc(Reader *input)
{
  this->houseId = input->readVarUhInt();
  if(this->houseId < 0)
  {
    qDebug()<<"ERREUR - HouseGuildRightsViewMessage -"<<"Forbidden value (" << this->houseId << ") on element of HouseGuildRightsViewMessage.houseId.";
  }
}

void HouseGuildRightsViewMessage::_instanceIdFunc(Reader *input)
{
  this->instanceId = input->readInt();
  if(this->instanceId < 0)
  {
    qDebug()<<"ERREUR - HouseGuildRightsViewMessage -"<<"Forbidden value (" << this->instanceId << ") on element of HouseGuildRightsViewMessage.instanceId.";
  }
}

HouseGuildRightsViewMessage::HouseGuildRightsViewMessage()
{
  m_type = MessageEnum::HOUSEGUILDRIGHTSVIEWMESSAGE;
}

