#include "HouseGuildRightsMessage.h"

void HouseGuildRightsMessage::serialize(Writer *output)
{
  this->serializeAs_HouseGuildRightsMessage(output);
}

void HouseGuildRightsMessage::serializeAs_HouseGuildRightsMessage(Writer *output)
{
  if(this->houseId < 0)
  {
    qDebug()<<"ERREUR - HouseGuildRightsMessage -"<<"Forbidden value (" << this->houseId << ") on element houseId.";
  }
  output->writeVarInt((int)this->houseId);
  if(this->instanceId < 0)
  {
    qDebug()<<"ERREUR - HouseGuildRightsMessage -"<<"Forbidden value (" << this->instanceId << ") on element instanceId.";
  }
  output->writeInt((int)this->instanceId);
  output->writeBool(this->secondHand);
  this->guildInfo->serializeAs_GuildInformations(output);
  if(this->rights < 0)
  {
    qDebug()<<"ERREUR - HouseGuildRightsMessage -"<<"Forbidden value (" << this->rights << ") on element rights.";
  }
  output->writeVarInt((int)this->rights);
}

void HouseGuildRightsMessage::deserialize(Reader *input)
{
  this->deserializeAs_HouseGuildRightsMessage(input);
}

void HouseGuildRightsMessage::deserializeAs_HouseGuildRightsMessage(Reader *input)
{
  this->_houseIdFunc(input);
  this->_instanceIdFunc(input);
  this->_secondHandFunc(input);
  this->guildInfo = QSharedPointer<GuildInformations>(new GuildInformations() );
  this->guildInfo->deserialize(input);
  this->_rightsFunc(input);
}

void HouseGuildRightsMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_HouseGuildRightsMessage(tree);
}

void HouseGuildRightsMessage::deserializeAsyncAs_HouseGuildRightsMessage(FuncTree tree)
{
  tree.addChild(std::bind(&HouseGuildRightsMessage::_houseIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HouseGuildRightsMessage::_instanceIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HouseGuildRightsMessage::_secondHandFunc, this, std::placeholders::_1));
  this->_guildInfotree = tree.addChild(std::bind(&HouseGuildRightsMessage::_guildInfotreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HouseGuildRightsMessage::_rightsFunc, this, std::placeholders::_1));
}

void HouseGuildRightsMessage::_houseIdFunc(Reader *input)
{
  this->houseId = input->readVarUhInt();
  if(this->houseId < 0)
  {
    qDebug()<<"ERREUR - HouseGuildRightsMessage -"<<"Forbidden value (" << this->houseId << ") on element of HouseGuildRightsMessage.houseId.";
  }
}

void HouseGuildRightsMessage::_instanceIdFunc(Reader *input)
{
  this->instanceId = input->readInt();
  if(this->instanceId < 0)
  {
    qDebug()<<"ERREUR - HouseGuildRightsMessage -"<<"Forbidden value (" << this->instanceId << ") on element of HouseGuildRightsMessage.instanceId.";
  }
}

void HouseGuildRightsMessage::_secondHandFunc(Reader *input)
{
  this->secondHand = input->readBool();
}

void HouseGuildRightsMessage::_guildInfotreeFunc(Reader *input)
{
  this->guildInfo = QSharedPointer<GuildInformations>(new GuildInformations() );
  this->guildInfo->deserializeAsync(this->_guildInfotree);
}

void HouseGuildRightsMessage::_rightsFunc(Reader *input)
{
  this->rights = input->readVarUhInt();
  if(this->rights < 0)
  {
    qDebug()<<"ERREUR - HouseGuildRightsMessage -"<<"Forbidden value (" << this->rights << ") on element of HouseGuildRightsMessage.rights.";
  }
}

HouseGuildRightsMessage::HouseGuildRightsMessage()
{
  m_type = MessageEnum::HOUSEGUILDRIGHTSMESSAGE;
}

