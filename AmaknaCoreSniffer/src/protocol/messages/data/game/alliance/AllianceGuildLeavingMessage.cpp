#include "AllianceGuildLeavingMessage.h"

void AllianceGuildLeavingMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceGuildLeavingMessage(output);
}

void AllianceGuildLeavingMessage::serializeAs_AllianceGuildLeavingMessage(Writer *output)
{
  output->writeBool(this->kicked);
  if(this->guildId < 0)
  {
    qDebug()<<"ERREUR - AllianceGuildLeavingMessage -"<<"Forbidden value (" << this->guildId << ") on element guildId.";
  }
  output->writeVarInt((int)this->guildId);
}

void AllianceGuildLeavingMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceGuildLeavingMessage(input);
}

void AllianceGuildLeavingMessage::deserializeAs_AllianceGuildLeavingMessage(Reader *input)
{
  this->_kickedFunc(input);
  this->_guildIdFunc(input);
}

void AllianceGuildLeavingMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceGuildLeavingMessage(tree);
}

void AllianceGuildLeavingMessage::deserializeAsyncAs_AllianceGuildLeavingMessage(FuncTree tree)
{
  tree.addChild(std::bind(&AllianceGuildLeavingMessage::_kickedFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AllianceGuildLeavingMessage::_guildIdFunc, this, std::placeholders::_1));
}

void AllianceGuildLeavingMessage::_kickedFunc(Reader *input)
{
  this->kicked = input->readBool();
}

void AllianceGuildLeavingMessage::_guildIdFunc(Reader *input)
{
  this->guildId = input->readVarUhInt();
  if(this->guildId < 0)
  {
    qDebug()<<"ERREUR - AllianceGuildLeavingMessage -"<<"Forbidden value (" << this->guildId << ") on element of AllianceGuildLeavingMessage.guildId.";
  }
}

AllianceGuildLeavingMessage::AllianceGuildLeavingMessage()
{
  m_type = MessageEnum::ALLIANCEGUILDLEAVINGMESSAGE;
}

