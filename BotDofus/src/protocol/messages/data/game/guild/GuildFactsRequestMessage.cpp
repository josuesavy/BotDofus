#include "GuildFactsRequestMessage.h"

void GuildFactsRequestMessage::serialize(Writer *output)
{
  this->serializeAs_GuildFactsRequestMessage(output);
}

void GuildFactsRequestMessage::serializeAs_GuildFactsRequestMessage(Writer *output)
{
  if(this->guildId < 0)
  {
    qDebug()<<"ERREUR - GuildFactsRequestMessage -"<<"Forbidden value (" << this->guildId << ") on element guildId.";
  }
  output->writeVarInt((int)this->guildId);
}

void GuildFactsRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildFactsRequestMessage(input);
}

void GuildFactsRequestMessage::deserializeAs_GuildFactsRequestMessage(Reader *input)
{
  this->_guildIdFunc(input);
}

void GuildFactsRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildFactsRequestMessage(tree);
}

void GuildFactsRequestMessage::deserializeAsyncAs_GuildFactsRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GuildFactsRequestMessage::_guildIdFunc, this, std::placeholders::_1));
}

void GuildFactsRequestMessage::_guildIdFunc(Reader *input)
{
  this->guildId = input->readVarUhInt();
  if(this->guildId < 0)
  {
    qDebug()<<"ERREUR - GuildFactsRequestMessage -"<<"Forbidden value (" << this->guildId << ") on element of GuildFactsRequestMessage.guildId.";
  }
}

GuildFactsRequestMessage::GuildFactsRequestMessage()
{
  m_type = MessageEnum::GUILDFACTSREQUESTMESSAGE;
}

