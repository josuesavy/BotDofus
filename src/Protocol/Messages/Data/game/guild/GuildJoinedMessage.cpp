#include "GuildJoinedMessage.h"

void GuildJoinedMessage::serialize(Writer *output)
{
  this->serializeAs_GuildJoinedMessage(output);
}

void GuildJoinedMessage::serializeAs_GuildJoinedMessage(Writer *output)
{
  this->guildInfo->serializeAs_GuildInformations(output);
  if(this->memberRights < 0)
  {
    qDebug()<<"ERREUR - GuildJoinedMessage -"<<"Forbidden value (" << this->memberRights << ") on element memberRights.";
  }
  output->writeVarInt((int)this->memberRights);
}

void GuildJoinedMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildJoinedMessage(input);
}

void GuildJoinedMessage::deserializeAs_GuildJoinedMessage(Reader *input)
{
  this->guildInfo = QSharedPointer<GuildInformations>(new GuildInformations() );
  this->guildInfo->deserialize(input);
  this->_memberRightsFunc(input);
}

void GuildJoinedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildJoinedMessage(tree);
}

void GuildJoinedMessage::deserializeAsyncAs_GuildJoinedMessage(FuncTree tree)
{
  this->_guildInfotree = tree.addChild(std::bind(&GuildJoinedMessage::_guildInfotreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildJoinedMessage::_memberRightsFunc, this, std::placeholders::_1));
}

void GuildJoinedMessage::_guildInfotreeFunc(Reader *input)
{
  this->guildInfo = QSharedPointer<GuildInformations>(new GuildInformations() );
  this->guildInfo->deserializeAsync(this->_guildInfotree);
}

void GuildJoinedMessage::_memberRightsFunc(Reader *input)
{
  this->memberRights = input->readVarUhInt();
  if(this->memberRights < 0)
  {
    qDebug()<<"ERREUR - GuildJoinedMessage -"<<"Forbidden value (" << this->memberRights << ") on element of GuildJoinedMessage.memberRights.";
  }
}

GuildJoinedMessage::GuildJoinedMessage()
{
  m_type = MessageEnum::GUILDJOINEDMESSAGE;
}

