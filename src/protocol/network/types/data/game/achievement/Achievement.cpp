#include "Achievement.h"

void Achievement::serialize(Writer *output)
{
  this->serializeAs_Achievement(output);
}

void Achievement::serializeAs_Achievement(Writer *output)
{
  if(this->id < 0)
  {
    qDebug()<<"ERREUR - Achievement -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  output->writeVarShort((int)this->id);
  output->writeShort((short)this->finishedObjective.size());
  for(uint _i2 = 0; _i2 < this->finishedObjective.size(); _i2++)
  {
    (this->finishedObjective[_i2] as com.ankamagames.dofus.network.types.game.achievement.AchievementObjective).serializeAs_AchievementObjective(output);
  }
  output->writeShort((short)this->startedObjectives.size());
  for(uint _i3 = 0; _i3 < this->startedObjectives.size(); _i3++)
  {
    (this->startedObjectives[_i3] as com.ankamagames.dofus.network.types.game.achievement.AchievementStartedObjective).serializeAs_AchievementStartedObjective(output);
  }
}

void Achievement::deserialize(Reader *input)
{
  this->deserializeAs_Achievement(input);
}

void Achievement::deserializeAs_Achievement(Reader *input)
{
  com.ankamagames.dofus.network.types.game.achievement.AchievementObjective _item2 ;
  com.ankamagames.dofus.network.types.game.achievement.AchievementStartedObjective _item3 ;
  this->_idFunc(input);
  uint _finishedObjectiveLen = uint(input->readUShort());
  for(uint _i2 = 0; _i2 < _finishedObjectiveLen; _i2++)
  {
    _item2 = new com.ankamagames.dofus.network.types.game.achievement.AchievementObjective();
    _item2.deserialize(input);
    this->finishedObjective.append(_item2);
  }
  uint _startedObjectivesLen = uint(input->readUShort());
  for(uint _i3 = 0; _i3 < _startedObjectivesLen; _i3++)
  {
    _item3 = new com.ankamagames.dofus.network.types.game.achievement.AchievementStartedObjective();
    _item3.deserialize(input);
    this->startedObjectives.append(_item3);
  }
}

void Achievement::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_Achievement(tree);
}

void Achievement::deserializeAsyncAs_Achievement(FuncTree tree)
{
  tree.addChild(std::bind(&Achievement::_idFunc, this, std::placeholders::_1));
  this->_finishedObjectivetree = tree.addChild(std::bind(&Achievement::_finishedObjectivetreeFunc, this, std::placeholders::_1));
  this->_startedObjectivestree = tree.addChild(std::bind(&Achievement::_startedObjectivestreeFunc, this, std::placeholders::_1));
}

void Achievement::_idFunc(Reader *input)
{
  this->id = input->readVarUhShort();
  if(this->id < 0)
  {
    qDebug()<<"ERREUR - Achievement -"<<"Forbidden value (" << this->id << ") on element of Achievement.id.";
  }
}

void Achievement::_finishedObjectivetreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_finishedObjectivetree.addChild(std::bind(&Achievement::_finishedObjectiveFunc, this, std::placeholders::_1));
  }
}

void Achievement::_finishedObjectiveFunc(Reader *input)
{
   _item = new com.ankamagames.dofus.network.types.game.achievement.AchievementObjective();
  _item.deserialize(input);
  this->finishedObjective.append(_item);
}

void Achievement::_startedObjectivestreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_startedObjectivestree.addChild(std::bind(&Achievement::_startedObjectivesFunc, this, std::placeholders::_1));
  }
}

void Achievement::_startedObjectivesFunc(Reader *input)
{
   _item = new com.ankamagames.dofus.network.types.game.achievement.AchievementStartedObjective();
  _item.deserialize(input);
  this->startedObjectives.append(_item);
}

Achievement::Achievement()
{
  m_types<<ClassEnum::ACHIEVEMENT;
}

bool Achievement::operator==(const Achievement &compared)
{
  if(id == compared.id)
  if(finishedObjective == compared.finishedObjective)
  if(startedObjectives == compared.startedObjectives)
  if(_finishedObjectivetree == compared._finishedObjectivetree)
  if(_startedObjectivestree == compared._startedObjectivestree)
  return true;
  
  return false;
}

