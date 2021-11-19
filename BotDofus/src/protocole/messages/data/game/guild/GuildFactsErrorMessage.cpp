#include "GuildFactsErrorMessage.h"

void GuildFactsErrorMessage::serialize(Writer *output)
{
  this->serializeAs_GuildFactsErrorMessage(output);
}

void GuildFactsErrorMessage::serializeAs_GuildFactsErrorMessage(Writer *output)
{
  if(this->guildId < 0)
  {
    qDebug()<<"ERREUR - GuildFactsErrorMessage -"<<"Forbidden value (" << this->guildId << ") on element guildId.";
  }
  output->writeVarInt((int)this->guildId);
}

void GuildFactsErrorMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildFactsErrorMessage(input);
}

void GuildFactsErrorMessage::deserializeAs_GuildFactsErrorMessage(Reader *input)
{
  this->_guildIdFunc(input);
}

void GuildFactsErrorMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildFactsErrorMessage(tree);
}

void GuildFactsErrorMessage::deserializeAsyncAs_GuildFactsErrorMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GuildFactsErrorMessage::_guildIdFunc, this, std::placeholders::_1));
}

void GuildFactsErrorMessage::_guildIdFunc(Reader *input)
{
  this->guildId = input->readVarUhInt();
  if(this->guildId < 0)
  {
    qDebug()<<"ERREUR - GuildFactsErrorMessage -"<<"Forbidden value (" << this->guildId << ") on element of GuildFactsErrorMessage.guildId.";
  }
}

GuildFactsErrorMessage::GuildFactsErrorMessage()
{
  m_type = MessageEnum::GUILDFACTSERRORMESSAGE;
}

