#include "DungeonPartyFinderRoomContentUpdateMessage.h"

void DungeonPartyFinderRoomContentUpdateMessage::serialize(Writer *output)
{
  this->serializeAs_DungeonPartyFinderRoomContentUpdateMessage(output);
}

void DungeonPartyFinderRoomContentUpdateMessage::serializeAs_DungeonPartyFinderRoomContentUpdateMessage(Writer *output)
{
  if(this->dungeonId < 0)
  {
    qDebug()<<"ERREUR - DungeonPartyFinderRoomContentUpdateMessage -"<<"Forbidden value (" << this->dungeonId << ") on element dungeonId.";
  }
  output->writeVarShort((int)this->dungeonId);
  output->writeShort((short)this->addedPlayers.size());
  for(uint _i2 = 0; _i2 < this->addedPlayers.size(); _i2++)
  {
    (this->addedPlayers[_i2]).serializeAs_DungeonPartyFinderPlayer(output);
  }
  output->writeShort((short)this->removedPlayersIds.size());
  for(uint _i3 = 0; _i3 < this->removedPlayersIds.size(); _i3++)
  {
    if(this->removedPlayersIds[_i3] < 0 || this->removedPlayersIds[_i3] > 9007199254740992)
    {
      qDebug()<<"ERREUR - DungeonPartyFinderRoomContentUpdateMessage -"<<"Forbidden value (" << this->removedPlayersIds[_i3] << ") on element 3 (starting at 1) of removedPlayersIds.";
    }
    output->writeVarLong((double)this->removedPlayersIds[_i3]);
  }
}

void DungeonPartyFinderRoomContentUpdateMessage::deserialize(Reader *input)
{
  this->deserializeAs_DungeonPartyFinderRoomContentUpdateMessage(input);
}

void DungeonPartyFinderRoomContentUpdateMessage::deserializeAs_DungeonPartyFinderRoomContentUpdateMessage(Reader *input)
{
  DungeonPartyFinderPlayer _item2 ;
  double _val3 = NULL;
  this->_dungeonIdFunc(input);
  uint _addedPlayersLen = uint(input->readUShort());
  for(uint _i2 = 0; _i2 < _addedPlayersLen; _i2++)
  {
    _item2 = DungeonPartyFinderPlayer();
    _item2.deserialize(input);
    this->addedPlayers.append(_item2);
  }
  uint _removedPlayersIdsLen = uint(input->readUShort());
  for(uint _i3 = 0; _i3 < _removedPlayersIdsLen; _i3++)
  {
    _val3 = input->readVarUhLong();
    if(_val3 < 0 || _val3 > 9007199254740992)
    {
      qDebug()<<"ERREUR - DungeonPartyFinderRoomContentUpdateMessage -"<<"Forbidden value (" << _val3 << ") on elements of removedPlayersIds.";
    }
    this->removedPlayersIds.append(_val3);
  }
}

void DungeonPartyFinderRoomContentUpdateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_DungeonPartyFinderRoomContentUpdateMessage(tree);
}

void DungeonPartyFinderRoomContentUpdateMessage::deserializeAsyncAs_DungeonPartyFinderRoomContentUpdateMessage(FuncTree tree)
{
  tree.addChild(std::bind(&DungeonPartyFinderRoomContentUpdateMessage::_dungeonIdFunc, this, std::placeholders::_1));
  this->_addedPlayerstree = tree.addChild(std::bind(&DungeonPartyFinderRoomContentUpdateMessage::_addedPlayerstreeFunc, this, std::placeholders::_1));
  this->_removedPlayersIdstree = tree.addChild(std::bind(&DungeonPartyFinderRoomContentUpdateMessage::_removedPlayersIdstreeFunc, this, std::placeholders::_1));
}

void DungeonPartyFinderRoomContentUpdateMessage::_dungeonIdFunc(Reader *input)
{
  this->dungeonId = input->readVarUhShort();
  if(this->dungeonId < 0)
  {
    qDebug()<<"ERREUR - DungeonPartyFinderRoomContentUpdateMessage -"<<"Forbidden value (" << this->dungeonId << ") on element of DungeonPartyFinderRoomContentUpdateMessage.dungeonId.";
  }
}

void DungeonPartyFinderRoomContentUpdateMessage::_addedPlayerstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_addedPlayerstree.addChild(std::bind(&DungeonPartyFinderRoomContentUpdateMessage::_addedPlayersFunc, this, std::placeholders::_1));
  }
}

void DungeonPartyFinderRoomContentUpdateMessage::_addedPlayersFunc(Reader *input)
{
  DungeonPartyFinderPlayer _item = DungeonPartyFinderPlayer();
  _item.deserialize(input);
  this->addedPlayers.append(_item);
}

void DungeonPartyFinderRoomContentUpdateMessage::_removedPlayersIdstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_removedPlayersIdstree.addChild(std::bind(&DungeonPartyFinderRoomContentUpdateMessage::_removedPlayersIdsFunc, this, std::placeholders::_1));
  }
}

void DungeonPartyFinderRoomContentUpdateMessage::_removedPlayersIdsFunc(Reader *input)
{
  double _val = input->readVarUhLong();
  if(_val < 0 || _val > 9007199254740992)
  {
    qDebug()<<"ERREUR - DungeonPartyFinderRoomContentUpdateMessage -"<<"Forbidden value (" << _val << ") on elements of removedPlayersIds.";
  }
  this->removedPlayersIds.append(_val);
}

DungeonPartyFinderRoomContentUpdateMessage::DungeonPartyFinderRoomContentUpdateMessage()
{
  m_type = MessageEnum::DUNGEONPARTYFINDERROOMCONTENTUPDATEMESSAGE;
}

