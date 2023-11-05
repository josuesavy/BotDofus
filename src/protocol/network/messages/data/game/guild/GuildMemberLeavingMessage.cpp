#include "GuildMemberLeavingMessage.h"

void GuildMemberLeavingMessage::serialize(Writer *output)
{
  this->serializeAs_GuildMemberLeavingMessage(output);
}

void GuildMemberLeavingMessage::serializeAs_GuildMemberLeavingMessage(Writer *output)
{
  output->writeBool(this->kicked);
  if(this->memberId < 0 || this->memberId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GuildMemberLeavingMessage -"<<"Forbidden value (" << this->memberId << ") on element memberId.";
  }
  output->writeVarLong((double)this->memberId);
}

void GuildMemberLeavingMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildMemberLeavingMessage(input);
}

void GuildMemberLeavingMessage::deserializeAs_GuildMemberLeavingMessage(Reader *input)
{
  this->_kickedFunc(input);
  this->_memberIdFunc(input);
}

void GuildMemberLeavingMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildMemberLeavingMessage(tree);
}

void GuildMemberLeavingMessage::deserializeAsyncAs_GuildMemberLeavingMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GuildMemberLeavingMessage::_kickedFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildMemberLeavingMessage::_memberIdFunc, this, std::placeholders::_1));
}

void GuildMemberLeavingMessage::_kickedFunc(Reader *input)
{
  this->kicked = input->readBool();
}

void GuildMemberLeavingMessage::_memberIdFunc(Reader *input)
{
  this->memberId = input->readVarUhLong();
  if(this->memberId < 0 || this->memberId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GuildMemberLeavingMessage -"<<"Forbidden value (" << this->memberId << ") on element of GuildMemberLeavingMessage.memberId.";
  }
}

GuildMemberLeavingMessage::GuildMemberLeavingMessage()
{
  m_type = MessageEnum::GUILDMEMBERLEAVINGMESSAGE;
}

