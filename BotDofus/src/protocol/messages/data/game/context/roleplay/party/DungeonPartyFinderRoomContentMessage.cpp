#include "DungeonPartyFinderRoomContentMessage.h"

void DungeonPartyFinderRoomContentMessage::serialize(Writer *output)
{
  this->serializeAs_DungeonPartyFinderRoomContentMessage(output);
}

void DungeonPartyFinderRoomContentMessage::serializeAs_DungeonPartyFinderRoomContentMessage(Writer *output)
{
  if(this->dungeonId < 0)
  {
    qDebug()<<"ERREUR - DungeonPartyFinderRoomContentMessage -"<<"Forbidden value (" << this->dungeonId << ") on element dungeonId.";
  }
  output->writeVarShort((int)this->dungeonId);
  output->writeShort((short)this->players.size());
  for(uint _i2 = 0; _i2 < this->players.size(); _i2++)
  {
    (this->players[_i2]).serializeAs_DungeonPartyFinderPlayer(output);
  }
}

void DungeonPartyFinderRoomContentMessage::deserialize(Reader *input)
{
  this->deserializeAs_DungeonPartyFinderRoomContentMessage(input);
}

void DungeonPartyFinderRoomContentMessage::deserializeAs_DungeonPartyFinderRoomContentMessage(Reader *input)
{
  DungeonPartyFinderPlayer _item2 ;
  this->_dungeonIdFunc(input);
  uint _playersLen = input->readUShort();
  for(uint _i2 = 0; _i2 < _playersLen; _i2++)
  {
    _item2 = DungeonPartyFinderPlayer();
    _item2.deserialize(input);
    this->players.append(_item2);
  }
}

void DungeonPartyFinderRoomContentMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_DungeonPartyFinderRoomContentMessage(tree);
}

void DungeonPartyFinderRoomContentMessage::deserializeAsyncAs_DungeonPartyFinderRoomContentMessage(FuncTree tree)
{
  tree.addChild(std::bind(&DungeonPartyFinderRoomContentMessage::_dungeonIdFunc, this, std::placeholders::_1));
  this->_playerstree = tree.addChild(std::bind(&DungeonPartyFinderRoomContentMessage::_playerstreeFunc, this, std::placeholders::_1));
}

void DungeonPartyFinderRoomContentMessage::_dungeonIdFunc(Reader *input)
{
  this->dungeonId = input->readVarUhShort();
  if(this->dungeonId < 0)
  {
    qDebug()<<"ERREUR - DungeonPartyFinderRoomContentMessage -"<<"Forbidden value (" << this->dungeonId << ") on element of DungeonPartyFinderRoomContentMessage.dungeonId.";
  }
}

void DungeonPartyFinderRoomContentMessage::_playerstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_playerstree.addChild(std::bind(&DungeonPartyFinderRoomContentMessage::_playersFunc, this, std::placeholders::_1));
  }
}

void DungeonPartyFinderRoomContentMessage::_playersFunc(Reader *input)
{
  DungeonPartyFinderPlayer _item = DungeonPartyFinderPlayer();
  _item.deserialize(input);
  this->players.append(_item);
}

DungeonPartyFinderRoomContentMessage::DungeonPartyFinderRoomContentMessage()
{
  m_type = MessageEnum::DUNGEONPARTYFINDERROOMCONTENTMESSAGE;
}

