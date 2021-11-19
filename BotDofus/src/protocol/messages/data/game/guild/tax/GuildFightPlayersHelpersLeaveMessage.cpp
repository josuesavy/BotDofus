#include "GuildFightPlayersHelpersLeaveMessage.h"

void GuildFightPlayersHelpersLeaveMessage::serialize(Writer *output)
{
  this->serializeAs_GuildFightPlayersHelpersLeaveMessage(output);
}

void GuildFightPlayersHelpersLeaveMessage::serializeAs_GuildFightPlayersHelpersLeaveMessage(Writer *output)
{
  if(this->fightId < 0 || this->fightId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildFightPlayersHelpersLeaveMessage -"<<"Forbidden value (" << this->fightId << ") on element fightId.";
  }
  output->writeDouble(this->fightId);
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildFightPlayersHelpersLeaveMessage -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  output->writeVarLong((double)this->playerId);
}

void GuildFightPlayersHelpersLeaveMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildFightPlayersHelpersLeaveMessage(input);
}

void GuildFightPlayersHelpersLeaveMessage::deserializeAs_GuildFightPlayersHelpersLeaveMessage(Reader *input)
{
  this->_fightIdFunc(input);
  this->_playerIdFunc(input);
}

void GuildFightPlayersHelpersLeaveMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildFightPlayersHelpersLeaveMessage(tree);
}

void GuildFightPlayersHelpersLeaveMessage::deserializeAsyncAs_GuildFightPlayersHelpersLeaveMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GuildFightPlayersHelpersLeaveMessage::_fightIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildFightPlayersHelpersLeaveMessage::_playerIdFunc, this, std::placeholders::_1));
}

void GuildFightPlayersHelpersLeaveMessage::_fightIdFunc(Reader *input)
{
  this->fightId = input->readDouble();
  if(this->fightId < 0 || this->fightId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildFightPlayersHelpersLeaveMessage -"<<"Forbidden value (" << this->fightId << ") on element of GuildFightPlayersHelpersLeaveMessage.fightId.";
  }
}

void GuildFightPlayersHelpersLeaveMessage::_playerIdFunc(Reader *input)
{
  this->playerId = input->readVarUhLong();
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildFightPlayersHelpersLeaveMessage -"<<"Forbidden value (" << this->playerId << ") on element of GuildFightPlayersHelpersLeaveMessage.playerId.";
  }
}

GuildFightPlayersHelpersLeaveMessage::GuildFightPlayersHelpersLeaveMessage()
{
  m_type = MessageEnum::GUILDFIGHTPLAYERSHELPERSLEAVEMESSAGE;
}

