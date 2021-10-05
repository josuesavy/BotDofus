#include "GameMapMovementMessage.h"

void GameMapMovementMessage::serialize(Writer *output)
{
  this->serializeAs_GameMapMovementMessage(output);
}

void GameMapMovementMessage::serializeAs_GameMapMovementMessage(Writer *output)
{
  output->writeShort((short)this->keyMovements.size());
  for(uint _i1 = 0; _i1 < this->keyMovements.size(); _i1++)
  {
    if(this->keyMovements[_i1] < 0)
    {
      qDebug()<<"ERREUR - GameMapMovementMessage -"<<"Forbidden value (" << this->keyMovements[_i1] << ") on element 1 (starting at 1) of keyMovements.";
    }
    output->writeShort((short)this->keyMovements[_i1]);
  }
  output->writeShort((short)this->forcedDirection);
  if(this->actorId < -9.007199254740992E15 || this->actorId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameMapMovementMessage -"<<"Forbidden value (" << this->actorId << ") on element actorId.";
  }
  output->writeDouble(this->actorId);
}

void GameMapMovementMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameMapMovementMessage(input);
}

void GameMapMovementMessage::deserializeAs_GameMapMovementMessage(Reader *input)
{
  uint _val1 = 0;
  uint _keyMovementsLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _keyMovementsLen; _i1++)
  {
    _val1 = input->readShort();
    if(_val1 < 0)
    {
      qDebug()<<"ERREUR - GameMapMovementMessage -"<<"Forbidden value (" << _val1 << ") on elements of keyMovements.";
    }
    this->keyMovements.append(_val1);
  }
  this->_forcedDirectionFunc(input);
  this->_actorIdFunc(input);
}

void GameMapMovementMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameMapMovementMessage(tree);
}

void GameMapMovementMessage::deserializeAsyncAs_GameMapMovementMessage(FuncTree tree)
{
  this->_keyMovementstree = tree.addChild(std::bind(&GameMapMovementMessage::_keyMovementstreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameMapMovementMessage::_forcedDirectionFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameMapMovementMessage::_actorIdFunc, this, std::placeholders::_1));
}

void GameMapMovementMessage::_keyMovementstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_keyMovementstree.addChild(std::bind(&GameMapMovementMessage::_keyMovementsFunc, this, std::placeholders::_1));
  }
}

void GameMapMovementMessage::_keyMovementsFunc(Reader *input)
{
  uint _val = input->readShort();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - GameMapMovementMessage -"<<"Forbidden value (" << _val << ") on elements of keyMovements.";
  }
  this->keyMovements.append(_val);
}

void GameMapMovementMessage::_forcedDirectionFunc(Reader *input)
{
  this->forcedDirection = input->readShort();
}

void GameMapMovementMessage::_actorIdFunc(Reader *input)
{
  this->actorId = input->readDouble();
  if(this->actorId < -9.007199254740992E15 || this->actorId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameMapMovementMessage -"<<"Forbidden value (" << this->actorId << ") on element of GameMapMovementMessage.actorId.";
  }
}

GameMapMovementMessage::GameMapMovementMessage()
{
  m_type = MessageEnum::GAMEMAPMOVEMENTMESSAGE;
}

