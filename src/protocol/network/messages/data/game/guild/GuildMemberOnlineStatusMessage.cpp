#include "GuildMemberOnlineStatusMessage.h"

void GuildMemberOnlineStatusMessage::serialize(Writer *output)
{
  this->serializeAs_GuildMemberOnlineStatusMessage(output);
}

void GuildMemberOnlineStatusMessage::serializeAs_GuildMemberOnlineStatusMessage(Writer *output)
{
  if(this->memberId < 0 || this->memberId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GuildMemberOnlineStatusMessage -"<<"Forbidden value (" << this->memberId << ") on element memberId.";
  }
  output->writeVarLong((double)this->memberId);
  output->writeBool(this->online);
}

void GuildMemberOnlineStatusMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildMemberOnlineStatusMessage(input);
}

void GuildMemberOnlineStatusMessage::deserializeAs_GuildMemberOnlineStatusMessage(Reader *input)
{
  this->_memberIdFunc(input);
  this->_onlineFunc(input);
}

void GuildMemberOnlineStatusMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildMemberOnlineStatusMessage(tree);
}

void GuildMemberOnlineStatusMessage::deserializeAsyncAs_GuildMemberOnlineStatusMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GuildMemberOnlineStatusMessage::_memberIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildMemberOnlineStatusMessage::_onlineFunc, this, std::placeholders::_1));
}

void GuildMemberOnlineStatusMessage::_memberIdFunc(Reader *input)
{
  this->memberId = input->readVarUhLong();
  if(this->memberId < 0 || this->memberId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GuildMemberOnlineStatusMessage -"<<"Forbidden value (" << this->memberId << ") on element of GuildMemberOnlineStatusMessage.memberId.";
  }
}

void GuildMemberOnlineStatusMessage::_onlineFunc(Reader *input)
{
  this->online = input->readBool();
}

GuildMemberOnlineStatusMessage::GuildMemberOnlineStatusMessage()
{
  m_type = MessageEnum::GUILDMEMBERONLINESTATUSMESSAGE;
}

