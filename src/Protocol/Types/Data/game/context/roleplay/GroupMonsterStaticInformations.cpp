#include "GroupMonsterStaticInformations.h"

void GroupMonsterStaticInformations::serialize(Writer *output)
{
  this->serializeAs_GroupMonsterStaticInformations(output);
}

void GroupMonsterStaticInformations::serializeAs_GroupMonsterStaticInformations(Writer *output)
{
  this->mainCreatureLightInfos.serializeAs_MonsterInGroupLightInformations(output);
  output->writeShort((short)this->underlings.size());
  for(uint _i2 = 0; _i2 < this->underlings.size(); _i2++)
  {
    qSharedPointerCast<MonsterInGroupInformations>(this->underlings[_i2])->serializeAs_MonsterInGroupInformations(output);
  }
}

void GroupMonsterStaticInformations::deserialize(Reader *input)
{
  this->deserializeAs_GroupMonsterStaticInformations(input);
}

void GroupMonsterStaticInformations::deserializeAs_GroupMonsterStaticInformations(Reader *input)
{
  QSharedPointer<MonsterInGroupInformations> _item2 ;
  this->mainCreatureLightInfos = MonsterInGroupLightInformations();
  this->mainCreatureLightInfos.deserialize(input);
  uint _underlingsLen = input->readUShort();
  for(uint _i2 = 0; _i2 < _underlingsLen; _i2++)
  {
    _item2 = QSharedPointer<MonsterInGroupInformations>(new MonsterInGroupInformations() );
    _item2->deserialize(input);
    this->underlings.append(_item2);
  }
}

void GroupMonsterStaticInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GroupMonsterStaticInformations(tree);
}

void GroupMonsterStaticInformations::deserializeAsyncAs_GroupMonsterStaticInformations(FuncTree tree)
{
  this->_mainCreatureLightInfostree = tree.addChild(std::bind(&GroupMonsterStaticInformations::_mainCreatureLightInfostreeFunc, this, std::placeholders::_1));
  this->_underlingstree = tree.addChild(std::bind(&GroupMonsterStaticInformations::_underlingstreeFunc, this, std::placeholders::_1));
}

void GroupMonsterStaticInformations::_mainCreatureLightInfostreeFunc(Reader *input)
{
  this->mainCreatureLightInfos = MonsterInGroupLightInformations();
  this->mainCreatureLightInfos.deserializeAsync(this->_mainCreatureLightInfostree);
}

void GroupMonsterStaticInformations::_underlingstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_underlingstree.addChild(std::bind(&GroupMonsterStaticInformations::_underlingsFunc, this, std::placeholders::_1));
  }
}

void GroupMonsterStaticInformations::_underlingsFunc(Reader *input)
{
  QSharedPointer<MonsterInGroupInformations> _item = QSharedPointer<MonsterInGroupInformations>(new MonsterInGroupInformations() );
  _item->deserialize(input);
  this->underlings.append(_item);
}

GroupMonsterStaticInformations::GroupMonsterStaticInformations()
{
  m_types<<ClassEnum::GROUPMONSTERSTATICINFORMATIONS;
}

bool GroupMonsterStaticInformations::operator==(const GroupMonsterStaticInformations &compared)
{
  if(mainCreatureLightInfos == compared.mainCreatureLightInfos)
  if(underlings == compared.underlings)
  if(_mainCreatureLightInfostree == compared._mainCreatureLightInfostree)
  if(_underlingstree == compared._underlingstree)
  return true;
  
  return false;
}

