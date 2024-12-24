#include "AlternativeMonstersInGroupLightInformations.h"

void AlternativeMonstersInGroupLightInformations::serialize(Writer *output)
{
  this->serializeAs_AlternativeMonstersInGroupLightInformations(output);
}

void AlternativeMonstersInGroupLightInformations::serializeAs_AlternativeMonstersInGroupLightInformations(Writer *output)
{
  output->writeInt((int)this->playerCount);
  output->writeShort((short)this->monsters.size());
  for(uint _i2 = 0; _i2 < this->monsters.size(); _i2++)
  {
    (this->monsters[_i2]).serializeAs_MonsterInGroupLightInformations(output);
  }
}

void AlternativeMonstersInGroupLightInformations::deserialize(Reader *input)
{
  this->deserializeAs_AlternativeMonstersInGroupLightInformations(input);
}

void AlternativeMonstersInGroupLightInformations::deserializeAs_AlternativeMonstersInGroupLightInformations(Reader *input)
{
  MonsterInGroupLightInformations _item2 ;
  this->_playerCountFunc(input);
  uint _monstersLen = uint(input->readUShort());
  for(uint _i2 = 0; _i2 < _monstersLen; _i2++)
  {
    _item2 = MonsterInGroupLightInformations();
    _item2.deserialize(input);
    this->monsters.append(_item2);
  }
}

void AlternativeMonstersInGroupLightInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AlternativeMonstersInGroupLightInformations(tree);
}

void AlternativeMonstersInGroupLightInformations::deserializeAsyncAs_AlternativeMonstersInGroupLightInformations(FuncTree tree)
{
  tree.addChild(std::bind(&AlternativeMonstersInGroupLightInformations::_playerCountFunc, this, std::placeholders::_1));
  this->_monsterstree = tree.addChild(std::bind(&AlternativeMonstersInGroupLightInformations::_monsterstreeFunc, this, std::placeholders::_1));
}

void AlternativeMonstersInGroupLightInformations::_playerCountFunc(Reader *input)
{
  this->playerCount = input->readInt();
}

void AlternativeMonstersInGroupLightInformations::_monsterstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_monsterstree.addChild(std::bind(&AlternativeMonstersInGroupLightInformations::_monstersFunc, this, std::placeholders::_1));
  }
}

void AlternativeMonstersInGroupLightInformations::_monstersFunc(Reader *input)
{
  MonsterInGroupLightInformations _item = MonsterInGroupLightInformations();
  _item.deserialize(input);
  this->monsters.append(_item);
}

AlternativeMonstersInGroupLightInformations::AlternativeMonstersInGroupLightInformations()
{
  m_types<<ClassEnum::ALTERNATIVEMONSTERSINGROUPLIGHTINFORMATIONS;
}

bool AlternativeMonstersInGroupLightInformations::operator==(const AlternativeMonstersInGroupLightInformations &compared)
{
  if(playerCount == compared.playerCount)
  if(monsters == compared.monsters)
  if(_monsterstree == compared._monsterstree)
  return true;
  
  return false;
}

