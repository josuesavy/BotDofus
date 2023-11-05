#include "HouseGuildShareRequestMessage.h"

void HouseGuildShareRequestMessage::serialize(Writer *output)
{
  this->serializeAs_HouseGuildShareRequestMessage(output);
}

void HouseGuildShareRequestMessage::serializeAs_HouseGuildShareRequestMessage(Writer *output)
{
  if(this->houseId < 0)
  {
    qDebug()<<"ERREUR - HouseGuildShareRequestMessage -"<<"Forbidden value (" << this->houseId << ") on element houseId.";
  }
  output->writeVarInt((int)this->houseId);
  if(this->instanceId < 0)
  {
    qDebug()<<"ERREUR - HouseGuildShareRequestMessage -"<<"Forbidden value (" << this->instanceId << ") on element instanceId.";
  }
  output->writeInt((int)this->instanceId);
  output->writeBool(this->enable);
  if(this->rights < 0)
  {
    qDebug()<<"ERREUR - HouseGuildShareRequestMessage -"<<"Forbidden value (" << this->rights << ") on element rights.";
  }
  output->writeVarInt((int)this->rights);
}

void HouseGuildShareRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_HouseGuildShareRequestMessage(input);
}

void HouseGuildShareRequestMessage::deserializeAs_HouseGuildShareRequestMessage(Reader *input)
{
  this->_houseIdFunc(input);
  this->_instanceIdFunc(input);
  this->_enableFunc(input);
  this->_rightsFunc(input);
}

void HouseGuildShareRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_HouseGuildShareRequestMessage(tree);
}

void HouseGuildShareRequestMessage::deserializeAsyncAs_HouseGuildShareRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&HouseGuildShareRequestMessage::_houseIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HouseGuildShareRequestMessage::_instanceIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HouseGuildShareRequestMessage::_enableFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HouseGuildShareRequestMessage::_rightsFunc, this, std::placeholders::_1));
}

void HouseGuildShareRequestMessage::_houseIdFunc(Reader *input)
{
  this->houseId = input->readVarUhInt();
  if(this->houseId < 0)
  {
    qDebug()<<"ERREUR - HouseGuildShareRequestMessage -"<<"Forbidden value (" << this->houseId << ") on element of HouseGuildShareRequestMessage.houseId.";
  }
}

void HouseGuildShareRequestMessage::_instanceIdFunc(Reader *input)
{
  this->instanceId = input->readInt();
  if(this->instanceId < 0)
  {
    qDebug()<<"ERREUR - HouseGuildShareRequestMessage -"<<"Forbidden value (" << this->instanceId << ") on element of HouseGuildShareRequestMessage.instanceId.";
  }
}

void HouseGuildShareRequestMessage::_enableFunc(Reader *input)
{
  this->enable = input->readBool();
}

void HouseGuildShareRequestMessage::_rightsFunc(Reader *input)
{
  this->rights = input->readVarUhInt();
  if(this->rights < 0)
  {
    qDebug()<<"ERREUR - HouseGuildShareRequestMessage -"<<"Forbidden value (" << this->rights << ") on element of HouseGuildShareRequestMessage.rights.";
  }
}

HouseGuildShareRequestMessage::HouseGuildShareRequestMessage()
{
  m_type = MessageEnum::HOUSEGUILDSHAREREQUESTMESSAGE;
}

