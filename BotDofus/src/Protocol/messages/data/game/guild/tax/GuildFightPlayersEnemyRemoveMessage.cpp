#include "GuildFightPlayersEnemyRemoveMessage.h"

void GuildFightPlayersEnemyRemoveMessage::serialize(Writer *output)
{
  this->serializeAs_GuildFightPlayersEnemyRemoveMessage(output);
}

void GuildFightPlayersEnemyRemoveMessage::serializeAs_GuildFightPlayersEnemyRemoveMessage(Writer *output)
{
  if(this->fightId < 0 || this->fightId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildFightPlayersEnemyRemoveMessage -"<<"Forbidden value (" << this->fightId << ") on element fightId.";
  }
  output->writeDouble(this->fightId);
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildFightPlayersEnemyRemoveMessage -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  output->writeVarLong((double)this->playerId);
}

void GuildFightPlayersEnemyRemoveMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildFightPlayersEnemyRemoveMessage(input);
}

void GuildFightPlayersEnemyRemoveMessage::deserializeAs_GuildFightPlayersEnemyRemoveMessage(Reader *input)
{
  this->_fightIdFunc(input);
  this->_playerIdFunc(input);
}

void GuildFightPlayersEnemyRemoveMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildFightPlayersEnemyRemoveMessage(tree);
}

void GuildFightPlayersEnemyRemoveMessage::deserializeAsyncAs_GuildFightPlayersEnemyRemoveMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GuildFightPlayersEnemyRemoveMessage::_fightIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildFightPlayersEnemyRemoveMessage::_playerIdFunc, this, std::placeholders::_1));
}

void GuildFightPlayersEnemyRemoveMessage::_fightIdFunc(Reader *input)
{
  this->fightId = input->readDouble();
  if(this->fightId < 0 || this->fightId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildFightPlayersEnemyRemoveMessage -"<<"Forbidden value (" << this->fightId << ") on element of GuildFightPlayersEnemyRemoveMessage.fightId.";
  }
}

void GuildFightPlayersEnemyRemoveMessage::_playerIdFunc(Reader *input)
{
  this->playerId = input->readVarUhLong();
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildFightPlayersEnemyRemoveMessage -"<<"Forbidden value (" << this->playerId << ") on element of GuildFightPlayersEnemyRemoveMessage.playerId.";
  }
}

GuildFightPlayersEnemyRemoveMessage::GuildFightPlayersEnemyRemoveMessage()
{
  m_type = MessageEnum::GUILDFIGHTPLAYERSENEMYREMOVEMESSAGE;
}

