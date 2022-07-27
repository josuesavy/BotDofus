#include "GuildJoinedMessage.h"

void GuildJoinedMessage::serialize(Writer *output)
{
  this->serializeAs_GuildJoinedMessage(output);
}

void GuildJoinedMessage::serializeAs_GuildJoinedMessage(Writer *output)
{
  this->guildInfo->serializeAs_GuildInformations(output);
  if(this->rankId < 0)
  {
    qDebug()<<"ERREUR - GuildJoinedMessage -"<<"Forbidden value (" << this->rankId << ") on element rankId.";
  }
  output->writeVarInt((int)this->rankId);
}

void GuildJoinedMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildJoinedMessage(input);
}

void GuildJoinedMessage::deserializeAs_GuildJoinedMessage(Reader *input)
{
  this->guildInfo = QSharedPointer<GuildInformations>(new GuildInformations() );
  this->guildInfo->deserialize(input);
  this->_rankIdFunc(input);
}

void GuildJoinedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildJoinedMessage(tree);
}

void GuildJoinedMessage::deserializeAsyncAs_GuildJoinedMessage(FuncTree tree)
{
  this->_guildInfotree = tree.addChild(std::bind(&GuildJoinedMessage::_guildInfotreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildJoinedMessage::_rankIdFunc, this, std::placeholders::_1));
}

void GuildJoinedMessage::_guildInfotreeFunc(Reader *input)
{
  this->guildInfo = QSharedPointer<GuildInformations>(new GuildInformations() );
  this->guildInfo->deserializeAsync(this->_guildInfotree);
}

void GuildJoinedMessage::_rankIdFunc(Reader *input)
{
  this->rankId = input->readVarUhInt();
  if(this->rankId < 0)
  {
    qDebug()<<"ERREUR - GuildJoinedMessage -"<<"Forbidden value (" << this->rankId << ") on element of GuildJoinedMessage.rankId.";
  }
}

GuildJoinedMessage::GuildJoinedMessage()
{
  m_type = MessageEnum::GUILDJOINEDMESSAGE;
}

