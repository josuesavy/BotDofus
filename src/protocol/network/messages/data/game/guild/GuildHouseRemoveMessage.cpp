#include "GuildHouseRemoveMessage.h"

void GuildHouseRemoveMessage::serialize(Writer *output)
{
  this->serializeAs_GuildHouseRemoveMessage(output);
}

void GuildHouseRemoveMessage::serializeAs_GuildHouseRemoveMessage(Writer *output)
{
  if(this->houseId < 0)
  {
    qDebug()<<"ERREUR - GuildHouseRemoveMessage -"<<"Forbidden value (" << this->houseId << ") on element houseId.";
  }
  output->writeVarInt((int)this->houseId);
  if(this->instanceId < 0)
  {
    qDebug()<<"ERREUR - GuildHouseRemoveMessage -"<<"Forbidden value (" << this->instanceId << ") on element instanceId.";
  }
  output->writeInt((int)this->instanceId);
  output->writeBool(this->secondHand);
}

void GuildHouseRemoveMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildHouseRemoveMessage(input);
}

void GuildHouseRemoveMessage::deserializeAs_GuildHouseRemoveMessage(Reader *input)
{
  this->_houseIdFunc(input);
  this->_instanceIdFunc(input);
  this->_secondHandFunc(input);
}

void GuildHouseRemoveMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildHouseRemoveMessage(tree);
}

void GuildHouseRemoveMessage::deserializeAsyncAs_GuildHouseRemoveMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GuildHouseRemoveMessage::_houseIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildHouseRemoveMessage::_instanceIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildHouseRemoveMessage::_secondHandFunc, this, std::placeholders::_1));
}

void GuildHouseRemoveMessage::_houseIdFunc(Reader *input)
{
  this->houseId = input->readVarUhInt();
  if(this->houseId < 0)
  {
    qDebug()<<"ERREUR - GuildHouseRemoveMessage -"<<"Forbidden value (" << this->houseId << ") on element of GuildHouseRemoveMessage.houseId.";
  }
}

void GuildHouseRemoveMessage::_instanceIdFunc(Reader *input)
{
  this->instanceId = input->readInt();
  if(this->instanceId < 0)
  {
    qDebug()<<"ERREUR - GuildHouseRemoveMessage -"<<"Forbidden value (" << this->instanceId << ") on element of GuildHouseRemoveMessage.instanceId.";
  }
}

void GuildHouseRemoveMessage::_secondHandFunc(Reader *input)
{
  this->secondHand = input->readBool();
}

GuildHouseRemoveMessage::GuildHouseRemoveMessage()
{
  m_type = MessageEnum::GUILDHOUSEREMOVEMESSAGE;
}

