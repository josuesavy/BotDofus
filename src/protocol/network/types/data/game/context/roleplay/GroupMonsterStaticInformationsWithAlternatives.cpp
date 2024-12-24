#include "GroupMonsterStaticInformationsWithAlternatives.h"

void GroupMonsterStaticInformationsWithAlternatives::serialize(Writer *output)
{
  this->serializeAs_GroupMonsterStaticInformationsWithAlternatives(output);
}

void GroupMonsterStaticInformationsWithAlternatives::serializeAs_GroupMonsterStaticInformationsWithAlternatives(Writer *output)
{
  GroupMonsterStaticInformations::serializeAs_GroupMonsterStaticInformations(output);
  output->writeShort((short)this->alternatives.size());
  for(uint _i1 = 0; _i1 < this->alternatives.size(); _i1++)
  {
    (this->alternatives[_i1]).serializeAs_AlternativeMonstersInGroupLightInformations(output);
  }
}

void GroupMonsterStaticInformationsWithAlternatives::deserialize(Reader *input)
{
  this->deserializeAs_GroupMonsterStaticInformationsWithAlternatives(input);
}

void GroupMonsterStaticInformationsWithAlternatives::deserializeAs_GroupMonsterStaticInformationsWithAlternatives(Reader *input)
{
  AlternativeMonstersInGroupLightInformations _item1 ;
  GroupMonsterStaticInformations::deserialize(input);
  uint _alternativesLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _alternativesLen; _i1++)
  {
    _item1 = AlternativeMonstersInGroupLightInformations();
    _item1.deserialize(input);
    this->alternatives.append(_item1);
  }
}

void GroupMonsterStaticInformationsWithAlternatives::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GroupMonsterStaticInformationsWithAlternatives(tree);
}

void GroupMonsterStaticInformationsWithAlternatives::deserializeAsyncAs_GroupMonsterStaticInformationsWithAlternatives(FuncTree tree)
{
  GroupMonsterStaticInformations::deserializeAsync(tree);
  this->_alternativestree = tree.addChild(std::bind(&GroupMonsterStaticInformationsWithAlternatives::_alternativestreeFunc, this, std::placeholders::_1));
}

void GroupMonsterStaticInformationsWithAlternatives::_alternativestreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_alternativestree.addChild(std::bind(&GroupMonsterStaticInformationsWithAlternatives::_alternativesFunc, this, std::placeholders::_1));
  }
}

void GroupMonsterStaticInformationsWithAlternatives::_alternativesFunc(Reader *input)
{
  AlternativeMonstersInGroupLightInformations _item = AlternativeMonstersInGroupLightInformations();
  _item.deserialize(input);
  this->alternatives.append(_item);
}

GroupMonsterStaticInformationsWithAlternatives::GroupMonsterStaticInformationsWithAlternatives()
{
  m_types<<ClassEnum::GROUPMONSTERSTATICINFORMATIONSWITHALTERNATIVES;
}

bool GroupMonsterStaticInformationsWithAlternatives::operator==(const GroupMonsterStaticInformationsWithAlternatives &compared)
{
  if(alternatives == compared.alternatives)
  if(_alternativestree == compared._alternativestree)
  return true;
  
  return false;
}

