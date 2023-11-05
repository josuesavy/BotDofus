#include "FightStartingPositions.h"

void FightStartingPositions::serialize(Writer *output)
{
  this->serializeAs_FightStartingPositions(output);
}

void FightStartingPositions::serializeAs_FightStartingPositions(Writer *output)
{
  output->writeShort((short)this->positionsForChallengers.size());
  for(uint _i1 = 0; _i1 < this->positionsForChallengers.size(); _i1++)
  {
    if(this->positionsForChallengers[_i1] < 0 || this->positionsForChallengers[_i1] > 559)
    {
      qDebug()<<"ERREUR - FightStartingPositions -"<<"Forbidden value (" << this->positionsForChallengers[_i1] << ") on element 1 (starting at 1) of positionsForChallengers.";
    }
    output->writeVarShort((int)this->positionsForChallengers[_i1]);
  }
  output->writeShort((short)this->positionsForDefenders.size());
  for(uint _i2 = 0; _i2 < this->positionsForDefenders.size(); _i2++)
  {
    if(this->positionsForDefenders[_i2] < 0 || this->positionsForDefenders[_i2] > 559)
    {
      qDebug()<<"ERREUR - FightStartingPositions -"<<"Forbidden value (" << this->positionsForDefenders[_i2] << ") on element 2 (starting at 1) of positionsForDefenders.";
    }
    output->writeVarShort((int)this->positionsForDefenders[_i2]);
  }
}

void FightStartingPositions::deserialize(Reader *input)
{
  this->deserializeAs_FightStartingPositions(input);
}

void FightStartingPositions::deserializeAs_FightStartingPositions(Reader *input)
{
  uint _val1 = 0;
  uint _val2 = 0;
  uint _positionsForChallengersLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _positionsForChallengersLen; _i1++)
  {
    _val1 = input->readVarUhShort();
    if(_val1 < 0 || _val1 > 559)
    {
      qDebug()<<"ERREUR - FightStartingPositions -"<<"Forbidden value (" << _val1 << ") on elements of positionsForChallengers.";
    }
    this->positionsForChallengers.append(_val1);
  }
  uint _positionsForDefendersLen = uint(input->readUShort());
  for(uint _i2 = 0; _i2 < _positionsForDefendersLen; _i2++)
  {
    _val2 = input->readVarUhShort();
    if(_val2 < 0 || _val2 > 559)
    {
      qDebug()<<"ERREUR - FightStartingPositions -"<<"Forbidden value (" << _val2 << ") on elements of positionsForDefenders.";
    }
    this->positionsForDefenders.append(_val2);
  }
}

void FightStartingPositions::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_FightStartingPositions(tree);
}

void FightStartingPositions::deserializeAsyncAs_FightStartingPositions(FuncTree tree)
{
  this->_positionsForChallengerstree = tree.addChild(std::bind(&FightStartingPositions::_positionsForChallengerstreeFunc, this, std::placeholders::_1));
  this->_positionsForDefenderstree = tree.addChild(std::bind(&FightStartingPositions::_positionsForDefenderstreeFunc, this, std::placeholders::_1));
}

void FightStartingPositions::_positionsForChallengerstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_positionsForChallengerstree.addChild(std::bind(&FightStartingPositions::_positionsForChallengersFunc, this, std::placeholders::_1));
  }
}

void FightStartingPositions::_positionsForChallengersFunc(Reader *input)
{
  uint _val = input->readVarUhShort();
  if(_val < 0 || _val > 559)
  {
    qDebug()<<"ERREUR - FightStartingPositions -"<<"Forbidden value (" << _val << ") on elements of positionsForChallengers.";
  }
  this->positionsForChallengers.append(_val);
}

void FightStartingPositions::_positionsForDefenderstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_positionsForDefenderstree.addChild(std::bind(&FightStartingPositions::_positionsForDefendersFunc, this, std::placeholders::_1));
  }
}

void FightStartingPositions::_positionsForDefendersFunc(Reader *input)
{
  uint _val = input->readVarUhShort();
  if(_val < 0 || _val > 559)
  {
    qDebug()<<"ERREUR - FightStartingPositions -"<<"Forbidden value (" << _val << ") on elements of positionsForDefenders.";
  }
  this->positionsForDefenders.append(_val);
}

FightStartingPositions::FightStartingPositions()
{
  m_types<<ClassEnum::FIGHTSTARTINGPOSITIONS;
}

bool FightStartingPositions::operator==(const FightStartingPositions &compared)
{
  if(positionsForChallengers == compared.positionsForChallengers)
  if(positionsForDefenders == compared.positionsForDefenders)
  if(_positionsForChallengerstree == compared._positionsForChallengerstree)
  if(_positionsForDefenderstree == compared._positionsForDefenderstree)
  return true;
  
  return false;
}

