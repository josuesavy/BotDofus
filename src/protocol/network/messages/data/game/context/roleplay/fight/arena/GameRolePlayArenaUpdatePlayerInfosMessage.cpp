#include "GameRolePlayArenaUpdatePlayerInfosMessage.h"

void GameRolePlayArenaUpdatePlayerInfosMessage::serialize(Writer *output)
{
  this->serializeAs_GameRolePlayArenaUpdatePlayerInfosMessage(output);
}

void GameRolePlayArenaUpdatePlayerInfosMessage::serializeAs_GameRolePlayArenaUpdatePlayerInfosMessage(Writer *output)
{
  output->writeShort((short)this->arenaRanks.size());
  for(uint _i1 = 0; _i1 < this->arenaRanks.size(); _i1++)
  {
    (this->arenaRanks[_i1]).serializeAs_ArenaRankInfos(output);
  }
  if(this->banEndDate < -9007199254740992 || this->banEndDate > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameRolePlayArenaUpdatePlayerInfosMessage -"<<"Forbidden value (" << this->banEndDate << ") on element banEndDate.";
  }
  output->writeDouble(this->banEndDate);
}

void GameRolePlayArenaUpdatePlayerInfosMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameRolePlayArenaUpdatePlayerInfosMessage(input);
}

void GameRolePlayArenaUpdatePlayerInfosMessage::deserializeAs_GameRolePlayArenaUpdatePlayerInfosMessage(Reader *input)
{
  ArenaRankInfos _item1 ;
  uint _arenaRanksLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _arenaRanksLen; _i1++)
  {
    _item1 = ArenaRankInfos();
    _item1.deserialize(input);
    this->arenaRanks.append(_item1);
  }
  this->_banEndDateFunc(input);
}

void GameRolePlayArenaUpdatePlayerInfosMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameRolePlayArenaUpdatePlayerInfosMessage(tree);
}

void GameRolePlayArenaUpdatePlayerInfosMessage::deserializeAsyncAs_GameRolePlayArenaUpdatePlayerInfosMessage(FuncTree tree)
{
  this->_arenaRankstree = tree.addChild(std::bind(&GameRolePlayArenaUpdatePlayerInfosMessage::_arenaRankstreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameRolePlayArenaUpdatePlayerInfosMessage::_banEndDateFunc, this, std::placeholders::_1));
}

void GameRolePlayArenaUpdatePlayerInfosMessage::_arenaRankstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_arenaRankstree.addChild(std::bind(&GameRolePlayArenaUpdatePlayerInfosMessage::_arenaRanksFunc, this, std::placeholders::_1));
  }
}

void GameRolePlayArenaUpdatePlayerInfosMessage::_arenaRanksFunc(Reader *input)
{
  ArenaRankInfos _item = ArenaRankInfos();
  _item.deserialize(input);
  this->arenaRanks.append(_item);
}

void GameRolePlayArenaUpdatePlayerInfosMessage::_banEndDateFunc(Reader *input)
{
  this->banEndDate = input->readDouble();
  if(this->banEndDate < -9007199254740992 || this->banEndDate > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameRolePlayArenaUpdatePlayerInfosMessage -"<<"Forbidden value (" << this->banEndDate << ") on element of GameRolePlayArenaUpdatePlayerInfosMessage.banEndDate.";
  }
}

GameRolePlayArenaUpdatePlayerInfosMessage::GameRolePlayArenaUpdatePlayerInfosMessage()
{
  m_type = MessageEnum::GAMEROLEPLAYARENAUPDATEPLAYERINFOSMESSAGE;
}

