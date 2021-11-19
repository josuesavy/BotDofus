#include "AllianceChangeGuildRightsMessage.h"

void AllianceChangeGuildRightsMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceChangeGuildRightsMessage(output);
}

void AllianceChangeGuildRightsMessage::serializeAs_AllianceChangeGuildRightsMessage(Writer *output)
{
  if(this->guildId < 0)
  {
    qDebug()<<"ERREUR - AllianceChangeGuildRightsMessage -"<<"Forbidden value (" << this->guildId << ") on element guildId.";
  }
  output->writeVarInt((int)this->guildId);
  if(this->rights < 0)
  {
    qDebug()<<"ERREUR - AllianceChangeGuildRightsMessage -"<<"Forbidden value (" << this->rights << ") on element rights.";
  }
  output->writeByte(this->rights);
}

void AllianceChangeGuildRightsMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceChangeGuildRightsMessage(input);
}

void AllianceChangeGuildRightsMessage::deserializeAs_AllianceChangeGuildRightsMessage(Reader *input)
{
  this->_guildIdFunc(input);
  this->_rightsFunc(input);
}

void AllianceChangeGuildRightsMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceChangeGuildRightsMessage(tree);
}

void AllianceChangeGuildRightsMessage::deserializeAsyncAs_AllianceChangeGuildRightsMessage(FuncTree tree)
{
  tree.addChild(std::bind(&AllianceChangeGuildRightsMessage::_guildIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AllianceChangeGuildRightsMessage::_rightsFunc, this, std::placeholders::_1));
}

void AllianceChangeGuildRightsMessage::_guildIdFunc(Reader *input)
{
  this->guildId = input->readVarUhInt();
  if(this->guildId < 0)
  {
    qDebug()<<"ERREUR - AllianceChangeGuildRightsMessage -"<<"Forbidden value (" << this->guildId << ") on element of AllianceChangeGuildRightsMessage.guildId.";
  }
}

void AllianceChangeGuildRightsMessage::_rightsFunc(Reader *input)
{
  this->rights = input->readByte();
  if(this->rights < 0)
  {
    qDebug()<<"ERREUR - AllianceChangeGuildRightsMessage -"<<"Forbidden value (" << this->rights << ") on element of AllianceChangeGuildRightsMessage.rights.";
  }
}

AllianceChangeGuildRightsMessage::AllianceChangeGuildRightsMessage()
{
  m_type = MessageEnum::ALLIANCECHANGEGUILDRIGHTSMESSAGE;
}

