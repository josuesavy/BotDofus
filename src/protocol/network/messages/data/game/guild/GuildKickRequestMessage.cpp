#include "GuildKickRequestMessage.h"

void GuildKickRequestMessage::serialize(Writer *output)
{
  this->serializeAs_GuildKickRequestMessage(output);
}

void GuildKickRequestMessage::serializeAs_GuildKickRequestMessage(Writer *output)
{
  if(this->kickedId < 0 || this->kickedId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GuildKickRequestMessage -"<<"Forbidden value (" << this->kickedId << ") on element kickedId.";
  }
  output->writeVarLong((double)this->kickedId);
}

void GuildKickRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildKickRequestMessage(input);
}

void GuildKickRequestMessage::deserializeAs_GuildKickRequestMessage(Reader *input)
{
  this->_kickedIdFunc(input);
}

void GuildKickRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildKickRequestMessage(tree);
}

void GuildKickRequestMessage::deserializeAsyncAs_GuildKickRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GuildKickRequestMessage::_kickedIdFunc, this, std::placeholders::_1));
}

void GuildKickRequestMessage::_kickedIdFunc(Reader *input)
{
  this->kickedId = input->readVarUhLong();
  if(this->kickedId < 0 || this->kickedId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GuildKickRequestMessage -"<<"Forbidden value (" << this->kickedId << ") on element of GuildKickRequestMessage.kickedId.";
  }
}

GuildKickRequestMessage::GuildKickRequestMessage()
{
  m_type = MessageEnum::GUILDKICKREQUESTMESSAGE;
}

