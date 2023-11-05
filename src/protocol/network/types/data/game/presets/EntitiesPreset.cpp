#include "EntitiesPreset.h"

void EntitiesPreset::serialize(Writer *output)
{
  this->serializeAs_EntitiesPreset(output);
}

void EntitiesPreset::serializeAs_EntitiesPreset(Writer *output)
{
  Preset::serializeAs_Preset(output);
  if(this->iconId < 0)
  {
    qDebug()<<"ERREUR - EntitiesPreset -"<<"Forbidden value (" << this->iconId << ") on element iconId.";
  }
  output->writeShort((short)this->iconId);
  output->writeShort((short)this->entityIds.size());
  for(uint _i2 = 0; _i2 < this->entityIds.size(); _i2++)
  {
    if(this->entityIds[_i2] < 0)
    {
      qDebug()<<"ERREUR - EntitiesPreset -"<<"Forbidden value (" << this->entityIds[_i2] << ") on element 2 (starting at 1) of entityIds.";
    }
    output->writeVarShort((int)this->entityIds[_i2]);
  }
}

void EntitiesPreset::deserialize(Reader *input)
{
  this->deserializeAs_EntitiesPreset(input);
}

void EntitiesPreset::deserializeAs_EntitiesPreset(Reader *input)
{
  uint _val2 = 0;
  Preset::deserialize(input);
  this->_iconIdFunc(input);
  uint _entityIdsLen = uint(input->readUShort());
  for(uint _i2 = 0; _i2 < _entityIdsLen; _i2++)
  {
    _val2 = input->readVarUhShort();
    if(_val2 < 0)
    {
      qDebug()<<"ERREUR - EntitiesPreset -"<<"Forbidden value (" << _val2 << ") on elements of entityIds.";
    }
    this->entityIds.append(_val2);
  }
}

void EntitiesPreset::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_EntitiesPreset(tree);
}

void EntitiesPreset::deserializeAsyncAs_EntitiesPreset(FuncTree tree)
{
  Preset::deserializeAsync(tree);
  tree.addChild(std::bind(&EntitiesPreset::_iconIdFunc, this, std::placeholders::_1));
  this->_entityIdstree = tree.addChild(std::bind(&EntitiesPreset::_entityIdstreeFunc, this, std::placeholders::_1));
}

void EntitiesPreset::_iconIdFunc(Reader *input)
{
  this->iconId = input->readShort();
  if(this->iconId < 0)
  {
    qDebug()<<"ERREUR - EntitiesPreset -"<<"Forbidden value (" << this->iconId << ") on element of EntitiesPreset.iconId.";
  }
}

void EntitiesPreset::_entityIdstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_entityIdstree.addChild(std::bind(&EntitiesPreset::_entityIdsFunc, this, std::placeholders::_1));
  }
}

void EntitiesPreset::_entityIdsFunc(Reader *input)
{
  uint _val = input->readVarUhShort();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - EntitiesPreset -"<<"Forbidden value (" << _val << ") on elements of entityIds.";
  }
  this->entityIds.append(_val);
}

EntitiesPreset::EntitiesPreset()
{
  m_types<<ClassEnum::ENTITIESPRESET;
}

bool EntitiesPreset::operator==(const EntitiesPreset &compared)
{
  if(iconId == compared.iconId)
  if(entityIds == compared.entityIds)
  if(_entityIdstree == compared._entityIdstree)
  return true;
  
  return false;
}

