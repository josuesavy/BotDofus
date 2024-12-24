#include "EntityLook.h"

void EntityLook::serialize(Writer *output)
{
  this->serializeAs_EntityLook(output);
}

void EntityLook::serializeAs_EntityLook(Writer *output)
{
  if(this->bonesId < 0)
  {
    qDebug()<<"ERREUR - EntityLook -"<<"Forbidden value (" << this->bonesId << ") on element bonesId.";
  }
  output->writeVarShort((int)this->bonesId);
  output->writeShort((short)this->skins.size());
  for(uint _i2 = 0; _i2 < this->skins.size(); _i2++)
  {
    if(this->skins[_i2] < 0)
    {
      qDebug()<<"ERREUR - EntityLook -"<<"Forbidden value (" << this->skins[_i2] << ") on element 2 (starting at 1) of skins.";
    }
    output->writeVarShort((int)this->skins[_i2]);
  }
  output->writeShort((short)this->indexedColors.size());
  for(uint _i3 = 0; _i3 < this->indexedColors.size(); _i3++)
  {
    output->writeInt((int)this->indexedColors[_i3]);
  }
  output->writeShort((short)this->scales.size());
  for(uint _i4 = 0; _i4 < this->scales.size(); _i4++)
  {
    output->writeVarShort((int)this->scales[_i4]);
  }
  output->writeShort((short)this->subentities.size());
  for(uint _i5 = 0; _i5 < this->subentities.size(); _i5++)
  {
    qSharedPointerCast<SubEntity>(this->subentities[_i5])->serializeAs_SubEntity(output);
  }
}

void EntityLook::deserialize(Reader *input)
{
  this->deserializeAs_EntityLook(input);
}

void EntityLook::deserializeAs_EntityLook(Reader *input)
{
  uint _val2 = 0;
  int _val3 = 0;
  int _val4 = 0;
  QSharedPointer<SubEntity> _item5 ;
  this->_bonesIdFunc(input);
  uint _skinsLen = uint(input->readUShort());
  for(uint _i2 = 0; _i2 < _skinsLen; _i2++)
  {
    _val2 = input->readVarUhShort();
    if(_val2 < 0)
    {
      qDebug()<<"ERREUR - EntityLook -"<<"Forbidden value (" << _val2 << ") on elements of skins.";
    }
    this->skins.append(_val2);
  }
  uint _indexedColorsLen = uint(input->readUShort());
  for(uint _i3 = 0; _i3 < _indexedColorsLen; _i3++)
  {
    _val3 = int(input->readInt());
    this->indexedColors.append(_val3);
  }
  uint _scalesLen = uint(input->readUShort());
  for(uint _i4 = 0; _i4 < _scalesLen; _i4++)
  {
    _val4 = input->readVarShort();
    this->scales.append(_val4);
  }
  uint _subentitiesLen = uint(input->readUShort());
  for(uint _i5 = 0; _i5 < _subentitiesLen; _i5++)
  {
    _item5 = QSharedPointer<SubEntity>(new SubEntity() );
    _item5->deserialize(input);
    this->subentities.append(_item5);
  }
}

void EntityLook::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_EntityLook(tree);
}

void EntityLook::deserializeAsyncAs_EntityLook(FuncTree tree)
{
  tree.addChild(std::bind(&EntityLook::_bonesIdFunc, this, std::placeholders::_1));
  this->_skinstree = tree.addChild(std::bind(&EntityLook::_skinstreeFunc, this, std::placeholders::_1));
  this->_indexedColorstree = tree.addChild(std::bind(&EntityLook::_indexedColorstreeFunc, this, std::placeholders::_1));
  this->_scalestree = tree.addChild(std::bind(&EntityLook::_scalestreeFunc, this, std::placeholders::_1));
  this->_subentitiestree = tree.addChild(std::bind(&EntityLook::_subentitiestreeFunc, this, std::placeholders::_1));
}

void EntityLook::_bonesIdFunc(Reader *input)
{
  this->bonesId = input->readVarUhShort();
  if(this->bonesId < 0)
  {
    qDebug()<<"ERREUR - EntityLook -"<<"Forbidden value (" << this->bonesId << ") on element of EntityLook.bonesId.";
  }
}

void EntityLook::_skinstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_skinstree.addChild(std::bind(&EntityLook::_skinsFunc, this, std::placeholders::_1));
  }
}

void EntityLook::_skinsFunc(Reader *input)
{
  uint _val = input->readVarUhShort();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - EntityLook -"<<"Forbidden value (" << _val << ") on elements of skins.";
  }
  this->skins.append(_val);
}

void EntityLook::_indexedColorstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_indexedColorstree.addChild(std::bind(&EntityLook::_indexedColorsFunc, this, std::placeholders::_1));
  }
}

void EntityLook::_indexedColorsFunc(Reader *input)
{
  int _val = int(input->readInt());
  this->indexedColors.append(_val);
}

void EntityLook::_scalestreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_scalestree.addChild(std::bind(&EntityLook::_scalesFunc, this, std::placeholders::_1));
  }
}

void EntityLook::_scalesFunc(Reader *input)
{
  int _val = input->readVarShort();
  this->scales.append(_val);
}

void EntityLook::_subentitiestreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_subentitiestree.addChild(std::bind(&EntityLook::_subentitiesFunc, this, std::placeholders::_1));
  }
}

void EntityLook::_subentitiesFunc(Reader *input)
{
  QSharedPointer<SubEntity> _item = QSharedPointer<SubEntity>(new SubEntity() );
  _item->deserialize(input);
  this->subentities.append(_item);
}

EntityLook::EntityLook()
{
  m_types<<ClassEnum::ENTITYLOOK;
}

bool EntityLook::operator==(const EntityLook &compared)
{
  if(bonesId == compared.bonesId)
  if(skins == compared.skins)
  if(indexedColors == compared.indexedColors)
  if(scales == compared.scales)
  if(subentities == compared.subentities)
  if(_skinstree == compared._skinstree)
  if(_indexedColorstree == compared._indexedColorstree)
  if(_scalestree == compared._scalestree)
  if(_subentitiestree == compared._subentitiestree)
  return true;
  
  return false;
}

