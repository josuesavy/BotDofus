#include "GameMapMovementRequestMessage.h"

void GameMapMovementRequestMessage::serialize(Writer *output)
{
  this->serializeAs_GameMapMovementRequestMessage(output);
}

void GameMapMovementRequestMessage::serializeAs_GameMapMovementRequestMessage(Writer *output)
{
  output->writeShort((short)this->keyMovements.size());
  for(uint _i1 = 0; _i1 < this->keyMovements.size(); _i1++)
  {
    if(this->keyMovements[_i1] < 0)
    {
      qDebug()<<"ERREUR - GameMapMovementRequestMessage -"<<"Forbidden value (" << this->keyMovements[_i1] << ") on element 1 (starting at 1) of keyMovements.";
    }
    output->writeShort((short)this->keyMovements[_i1]);
  }
  if(this->mapId < 0 || this->mapId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameMapMovementRequestMessage -"<<"Forbidden value (" << this->mapId << ") on element mapId.";
  }
  output->writeDouble(this->mapId);
}

void GameMapMovementRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameMapMovementRequestMessage(input);
}

void GameMapMovementRequestMessage::deserializeAs_GameMapMovementRequestMessage(Reader *input)
{
  uint _val1 = 0;
  uint _keyMovementsLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _keyMovementsLen; _i1++)
  {
    _val1 = input->readShort();
    if(_val1 < 0)
    {
      qDebug()<<"ERREUR - GameMapMovementRequestMessage -"<<"Forbidden value (" << _val1 << ") on elements of keyMovements.";
    }
    this->keyMovements.append(_val1);
  }
  this->_mapIdFunc(input);
}

void GameMapMovementRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameMapMovementRequestMessage(tree);
}

void GameMapMovementRequestMessage::deserializeAsyncAs_GameMapMovementRequestMessage(FuncTree tree)
{
  this->_keyMovementstree = tree.addChild(std::bind(&GameMapMovementRequestMessage::_keyMovementstreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameMapMovementRequestMessage::_mapIdFunc, this, std::placeholders::_1));
}

void GameMapMovementRequestMessage::_keyMovementstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_keyMovementstree.addChild(std::bind(&GameMapMovementRequestMessage::_keyMovementsFunc, this, std::placeholders::_1));
  }
}

void GameMapMovementRequestMessage::_keyMovementsFunc(Reader *input)
{
  uint _val = input->readShort();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - GameMapMovementRequestMessage -"<<"Forbidden value (" << _val << ") on elements of keyMovements.";
  }
  this->keyMovements.append(_val);
}

void GameMapMovementRequestMessage::_mapIdFunc(Reader *input)
{
  this->mapId = input->readDouble();
  if(this->mapId < 0 || this->mapId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameMapMovementRequestMessage -"<<"Forbidden value (" << this->mapId << ") on element of GameMapMovementRequestMessage.mapId.";
  }
}

GameMapMovementRequestMessage::GameMapMovementRequestMessage()
{
  m_type = MessageEnum::GAMEMAPMOVEMENTREQUESTMESSAGE;
  m_needsHash = true;
}

