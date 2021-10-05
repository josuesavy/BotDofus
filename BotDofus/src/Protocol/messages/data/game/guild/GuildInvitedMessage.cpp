#include "GuildInvitedMessage.h"

void GuildInvitedMessage::serialize(Writer *output)
{
  this->serializeAs_GuildInvitedMessage(output);
}

void GuildInvitedMessage::serializeAs_GuildInvitedMessage(Writer *output)
{
  if(this->recruterId < 0 || this->recruterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildInvitedMessage -"<<"Forbidden value (" << this->recruterId << ") on element recruterId.";
  }
  output->writeVarLong((double)this->recruterId);
  output->writeUTF(this->recruterName);
  this->guildInfo->serializeAs_BasicGuildInformations(output);
}

void GuildInvitedMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildInvitedMessage(input);
}

void GuildInvitedMessage::deserializeAs_GuildInvitedMessage(Reader *input)
{
  this->_recruterIdFunc(input);
  this->_recruterNameFunc(input);
  this->guildInfo = QSharedPointer<BasicGuildInformations>(new BasicGuildInformations() );
  this->guildInfo->deserialize(input);
}

void GuildInvitedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildInvitedMessage(tree);
}

void GuildInvitedMessage::deserializeAsyncAs_GuildInvitedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GuildInvitedMessage::_recruterIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildInvitedMessage::_recruterNameFunc, this, std::placeholders::_1));
  this->_guildInfotree = tree.addChild(std::bind(&GuildInvitedMessage::_guildInfotreeFunc, this, std::placeholders::_1));
}

void GuildInvitedMessage::_recruterIdFunc(Reader *input)
{
  this->recruterId = input->readVarUhLong();
  if(this->recruterId < 0 || this->recruterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildInvitedMessage -"<<"Forbidden value (" << this->recruterId << ") on element of GuildInvitedMessage.recruterId.";
  }
}

void GuildInvitedMessage::_recruterNameFunc(Reader *input)
{
  this->recruterName = input->readUTF();
}

void GuildInvitedMessage::_guildInfotreeFunc(Reader *input)
{
  this->guildInfo = QSharedPointer<BasicGuildInformations>(new BasicGuildInformations() );
  this->guildInfo->deserializeAsync(this->_guildInfotree);
}

GuildInvitedMessage::GuildInvitedMessage()
{
  m_type = MessageEnum::GUILDINVITEDMESSAGE;
}

