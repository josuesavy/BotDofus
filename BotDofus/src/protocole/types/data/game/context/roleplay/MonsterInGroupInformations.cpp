#include "MonsterInGroupInformations.h"

void MonsterInGroupInformations::serialize(Writer *output)
{
  this->serializeAs_MonsterInGroupInformations(output);
}

void MonsterInGroupInformations::serializeAs_MonsterInGroupInformations(Writer *output)
{
  MonsterInGroupLightInformations::serializeAs_MonsterInGroupLightInformations(output);
  this->look->serializeAs_EntityLook(output);
}

void MonsterInGroupInformations::deserialize(Reader *input)
{
  this->deserializeAs_MonsterInGroupInformations(input);
}

void MonsterInGroupInformations::deserializeAs_MonsterInGroupInformations(Reader *input)
{
  MonsterInGroupLightInformations::deserialize(input);
  this->look = QSharedPointer<EntityLook>(new EntityLook() );
  this->look->deserialize(input);
}

void MonsterInGroupInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_MonsterInGroupInformations(tree);
}

void MonsterInGroupInformations::deserializeAsyncAs_MonsterInGroupInformations(FuncTree tree)
{
  MonsterInGroupLightInformations::deserializeAsync(tree);
  this->_looktree = tree.addChild(std::bind(&MonsterInGroupInformations::_looktreeFunc, this, std::placeholders::_1));
}

void MonsterInGroupInformations::_looktreeFunc(Reader *input)
{
  this->look = QSharedPointer<EntityLook>(new EntityLook() );
  this->look->deserializeAsync(this->_looktree);
}

MonsterInGroupInformations::MonsterInGroupInformations()
{
  m_types<<ClassEnum::MONSTERINGROUPINFORMATIONS;
}

bool MonsterInGroupInformations::operator==(const MonsterInGroupInformations &compared)
{
  if(look == compared.look)
  if(_looktree == compared._looktree)
  return true;
  
  return false;
}

