#include "GameFightPlacementPossiblePositionsMessage.h"

void GameFightPlacementPossiblePositionsMessage::serialize(Writer *output)
{
  this->serializeAs_GameFightPlacementPossiblePositionsMessage(output);
}

void GameFightPlacementPossiblePositionsMessage::serializeAs_GameFightPlacementPossiblePositionsMessage(Writer *output)
{
  output->writeShort((short)this->positionsForChallengers.size());
  for(uint _i1 = 0; _i1 < this->positionsForChallengers.size(); _i1++)
  {
    if(this->positionsForChallengers[_i1] < 0 || this->positionsForChallengers[_i1] > 559)
    {
      qDebug()<<"ERREUR - GameFightPlacementPossiblePositionsMessage -"<<"Forbidden value (" << this->positionsForChallengers[_i1] << ") on element 1 (starting at 1) of positionsForChallengers.";
    }
    output->writeVarShort((int)this->positionsForChallengers[_i1]);
  }
  output->writeShort((short)this->positionsForDefenders.size());
  for(uint _i2 = 0; _i2 < this->positionsForDefenders.size(); _i2++)
  {
    if(this->positionsForDefenders[_i2] < 0 || this->positionsForDefenders[_i2] > 559)
    {
      qDebug()<<"ERREUR - GameFightPlacementPossiblePositionsMessage -"<<"Forbidden value (" << this->positionsForDefenders[_i2] << ") on element 2 (starting at 1) of positionsForDefenders.";
    }
    output->writeVarShort((int)this->positionsForDefenders[_i2]);
  }
  output->writeByte(this->teamNumber);
}

void GameFightPlacementPossiblePositionsMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameFightPlacementPossiblePositionsMessage(input);
}

void GameFightPlacementPossiblePositionsMessage::deserializeAs_GameFightPlacementPossiblePositionsMessage(Reader *input)
{
  uint _val1 = 0;
  uint _val2 = 0;
  uint _positionsForChallengersLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _positionsForChallengersLen; _i1++)
  {
    _val1 = input->readVarUhShort();
    if(_val1 < 0 || _val1 > 559)
    {
      qDebug()<<"ERREUR - GameFightPlacementPossiblePositionsMessage -"<<"Forbidden value (" << _val1 << ") on elements of positionsForChallengers.";
    }
    this->positionsForChallengers.append(_val1);
  }
  uint _positionsForDefendersLen = input->readUShort();
  for(uint _i2 = 0; _i2 < _positionsForDefendersLen; _i2++)
  {
    _val2 = input->readVarUhShort();
    if(_val2 < 0 || _val2 > 559)
    {
      qDebug()<<"ERREUR - GameFightPlacementPossiblePositionsMessage -"<<"Forbidden value (" << _val2 << ") on elements of positionsForDefenders.";
    }
    this->positionsForDefenders.append(_val2);
  }
  this->_teamNumberFunc(input);
}

void GameFightPlacementPossiblePositionsMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameFightPlacementPossiblePositionsMessage(tree);
}

void GameFightPlacementPossiblePositionsMessage::deserializeAsyncAs_GameFightPlacementPossiblePositionsMessage(FuncTree tree)
{
  this->_positionsForChallengerstree = tree.addChild(std::bind(&GameFightPlacementPossiblePositionsMessage::_positionsForChallengerstreeFunc, this, std::placeholders::_1));
  this->_positionsForDefenderstree = tree.addChild(std::bind(&GameFightPlacementPossiblePositionsMessage::_positionsForDefenderstreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightPlacementPossiblePositionsMessage::_teamNumberFunc, this, std::placeholders::_1));
}

void GameFightPlacementPossiblePositionsMessage::_positionsForChallengerstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_positionsForChallengerstree.addChild(std::bind(&GameFightPlacementPossiblePositionsMessage::_positionsForChallengersFunc, this, std::placeholders::_1));
  }
}

void GameFightPlacementPossiblePositionsMessage::_positionsForChallengersFunc(Reader *input)
{
  uint _val = input->readVarUhShort();
  if(_val < 0 || _val > 559)
  {
    qDebug()<<"ERREUR - GameFightPlacementPossiblePositionsMessage -"<<"Forbidden value (" << _val << ") on elements of positionsForChallengers.";
  }
  this->positionsForChallengers.append(_val);
}

void GameFightPlacementPossiblePositionsMessage::_positionsForDefenderstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_positionsForDefenderstree.addChild(std::bind(&GameFightPlacementPossiblePositionsMessage::_positionsForDefendersFunc, this, std::placeholders::_1));
  }
}

void GameFightPlacementPossiblePositionsMessage::_positionsForDefendersFunc(Reader *input)
{
  uint _val = input->readVarUhShort();
  if(_val < 0 || _val > 559)
  {
    qDebug()<<"ERREUR - GameFightPlacementPossiblePositionsMessage -"<<"Forbidden value (" << _val << ") on elements of positionsForDefenders.";
  }
  this->positionsForDefenders.append(_val);
}

void GameFightPlacementPossiblePositionsMessage::_teamNumberFunc(Reader *input)
{
  this->teamNumber = input->readByte();
  if(this->teamNumber < 0)
  {
    qDebug()<<"ERREUR - GameFightPlacementPossiblePositionsMessage -"<<"Forbidden value (" << this->teamNumber << ") on element of GameFightPlacementPossiblePositionsMessage.teamNumber.";
  }
}

GameFightPlacementPossiblePositionsMessage::GameFightPlacementPossiblePositionsMessage()
{
  m_type = MessageEnum::GAMEFIGHTPLACEMENTPOSSIBLEPOSITIONSMESSAGE;
}

