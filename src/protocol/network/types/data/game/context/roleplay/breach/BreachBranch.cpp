#include "BreachBranch.h"

void BreachBranch::serialize(Writer *output)
{
  this->serializeAs_BreachBranch(output);
}

void BreachBranch::serializeAs_BreachBranch(Writer *output)
{
  if(this->room < 0)
  {
    qDebug()<<"ERREUR - BreachBranch -"<<"Forbidden value (" << this->room << ") on element room.";
  }
  output->writeByte(this->room);
  if(this->element < 0)
  {
    qDebug()<<"ERREUR - BreachBranch -"<<"Forbidden value (" << this->element << ") on element element.";
  }
  output->writeInt((int)this->element);
  output->writeShort((short)this->bosses.size());
  for(uint _i3 = 0; _i3 < this->bosses.size(); _i3++)
  {
    (this->bosses[_i3]).serializeAs_MonsterInGroupLightInformations(output);
  }
  if(this->map < 0 || this->map > 9007199254740992)
  {
    qDebug()<<"ERREUR - BreachBranch -"<<"Forbidden value (" << this->map << ") on element map.";
  }
  output->writeDouble(this->map);
  output->writeShort((short)this->score);
  output->writeShort((short)this->relativeScore);
  output->writeShort((short)this->monsters.size());
  for(uint _i7 = 0; _i7 < this->monsters.size(); _i7++)
  {
    (this->monsters[_i7]).serializeAs_MonsterInGroupLightInformations(output);
  }
}

void BreachBranch::deserialize(Reader *input)
{
  this->deserializeAs_BreachBranch(input);
}

void BreachBranch::deserializeAs_BreachBranch(Reader *input)
{
  MonsterInGroupLightInformations _item3 ;
  MonsterInGroupLightInformations _item7 ;
  this->_roomFunc(input);
  this->_elementFunc(input);
  uint _bossesLen = uint(input->readUShort());
  for(uint _i3 = 0; _i3 < _bossesLen; _i3++)
  {
    _item3 = MonsterInGroupLightInformations();
    _item3.deserialize(input);
    this->bosses.append(_item3);
  }
  this->_mapFunc(input);
  this->_scoreFunc(input);
  this->_relativeScoreFunc(input);
  uint _monstersLen = uint(input->readUShort());
  for(uint _i7 = 0; _i7 < _monstersLen; _i7++)
  {
    _item7 = MonsterInGroupLightInformations();
    _item7.deserialize(input);
    this->monsters.append(_item7);
  }
}

void BreachBranch::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_BreachBranch(tree);
}

void BreachBranch::deserializeAsyncAs_BreachBranch(FuncTree tree)
{
  tree.addChild(std::bind(&BreachBranch::_roomFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&BreachBranch::_elementFunc, this, std::placeholders::_1));
  this->_bossestree = tree.addChild(std::bind(&BreachBranch::_bossestreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&BreachBranch::_mapFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&BreachBranch::_scoreFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&BreachBranch::_relativeScoreFunc, this, std::placeholders::_1));
  this->_monsterstree = tree.addChild(std::bind(&BreachBranch::_monsterstreeFunc, this, std::placeholders::_1));
}

void BreachBranch::_roomFunc(Reader *input)
{
  this->room = input->readByte();
  if(this->room < 0)
  {
    qDebug()<<"ERREUR - BreachBranch -"<<"Forbidden value (" << this->room << ") on element of BreachBranch.room.";
  }
}

void BreachBranch::_elementFunc(Reader *input)
{
  this->element = input->readInt();
  if(this->element < 0)
  {
    qDebug()<<"ERREUR - BreachBranch -"<<"Forbidden value (" << this->element << ") on element of BreachBranch.element.";
  }
}

void BreachBranch::_bossestreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_bossestree.addChild(std::bind(&BreachBranch::_bossesFunc, this, std::placeholders::_1));
  }
}

void BreachBranch::_bossesFunc(Reader *input)
{
  MonsterInGroupLightInformations _item = MonsterInGroupLightInformations();
  _item.deserialize(input);
  this->bosses.append(_item);
}

void BreachBranch::_mapFunc(Reader *input)
{
  this->map = input->readDouble();
  if(this->map < 0 || this->map > 9007199254740992)
  {
    qDebug()<<"ERREUR - BreachBranch -"<<"Forbidden value (" << this->map << ") on element of BreachBranch.map.";
  }
}

void BreachBranch::_scoreFunc(Reader *input)
{
  this->score = input->readShort();
}

void BreachBranch::_relativeScoreFunc(Reader *input)
{
  this->relativeScore = input->readShort();
}

void BreachBranch::_monsterstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_monsterstree.addChild(std::bind(&BreachBranch::_monstersFunc, this, std::placeholders::_1));
  }
}

void BreachBranch::_monstersFunc(Reader *input)
{
  MonsterInGroupLightInformations _item = MonsterInGroupLightInformations();
  _item.deserialize(input);
  this->monsters.append(_item);
}

BreachBranch::BreachBranch()
{
  m_types<<ClassEnum::BREACHBRANCH;
}

bool BreachBranch::operator==(const BreachBranch &compared)
{
  if(room == compared.room)
  if(element == compared.element)
  if(bosses == compared.bosses)
  if(map == compared.map)
  if(score == compared.score)
  if(relativeScore == compared.relativeScore)
  if(monsters == compared.monsters)
  if(_bossestree == compared._bossestree)
  if(_monsterstree == compared._monsterstree)
  return true;
  
  return false;
}

