#include "GuildFightPlayersEnemiesListMessage.h"

void GuildFightPlayersEnemiesListMessage::serialize(Writer *output)
{
  this->serializeAs_GuildFightPlayersEnemiesListMessage(output);
}

void GuildFightPlayersEnemiesListMessage::serializeAs_GuildFightPlayersEnemiesListMessage(Writer *output)
{
  if(this->fightId < 0 || this->fightId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildFightPlayersEnemiesListMessage -"<<"Forbidden value (" << this->fightId << ") on element fightId.";
  }
  output->writeDouble(this->fightId);
  output->writeShort((short)this->playerInfo.size());
  for(uint _i2 = 0; _i2 < this->playerInfo.size(); _i2++)
  {
    qSharedPointerCast<CharacterMinimalPlusLookInformations>(this->playerInfo[_i2])->serializeAs_CharacterMinimalPlusLookInformations(output);
  }
}

void GuildFightPlayersEnemiesListMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildFightPlayersEnemiesListMessage(input);
}

void GuildFightPlayersEnemiesListMessage::deserializeAs_GuildFightPlayersEnemiesListMessage(Reader *input)
{
  QSharedPointer<CharacterMinimalPlusLookInformations> _item2 ;
  this->_fightIdFunc(input);
  uint _playerInfoLen = input->readUShort();
  for(uint _i2 = 0; _i2 < _playerInfoLen; _i2++)
  {
    _item2 = QSharedPointer<CharacterMinimalPlusLookInformations>(new CharacterMinimalPlusLookInformations() );
    _item2->deserialize(input);
    this->playerInfo.append(_item2);
  }
}

void GuildFightPlayersEnemiesListMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildFightPlayersEnemiesListMessage(tree);
}

void GuildFightPlayersEnemiesListMessage::deserializeAsyncAs_GuildFightPlayersEnemiesListMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GuildFightPlayersEnemiesListMessage::_fightIdFunc, this, std::placeholders::_1));
  this->_playerInfotree = tree.addChild(std::bind(&GuildFightPlayersEnemiesListMessage::_playerInfotreeFunc, this, std::placeholders::_1));
}

void GuildFightPlayersEnemiesListMessage::_fightIdFunc(Reader *input)
{
  this->fightId = input->readDouble();
  if(this->fightId < 0 || this->fightId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildFightPlayersEnemiesListMessage -"<<"Forbidden value (" << this->fightId << ") on element of GuildFightPlayersEnemiesListMessage.fightId.";
  }
}

void GuildFightPlayersEnemiesListMessage::_playerInfotreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_playerInfotree.addChild(std::bind(&GuildFightPlayersEnemiesListMessage::_playerInfoFunc, this, std::placeholders::_1));
  }
}

void GuildFightPlayersEnemiesListMessage::_playerInfoFunc(Reader *input)
{
  QSharedPointer<CharacterMinimalPlusLookInformations> _item = QSharedPointer<CharacterMinimalPlusLookInformations>(new CharacterMinimalPlusLookInformations() );
  _item->deserialize(input);
  this->playerInfo.append(_item);
}

GuildFightPlayersEnemiesListMessage::GuildFightPlayersEnemiesListMessage()
{
  m_type = MessageEnum::GUILDFIGHTPLAYERSENEMIESLISTMESSAGE;
}

