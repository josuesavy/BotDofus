#include "ItemForPreset.h"

void ItemForPreset::serialize(Writer *output)
{
  this->serializeAs_ItemForPreset(output);
}

void ItemForPreset::serializeAs_ItemForPreset(Writer *output)
{
  output->writeShort((short)this->position);
  if(this->objGid < 0)
  {
    qDebug()<<"ERREUR - ItemForPreset -"<<"Forbidden value (" << this->objGid << ") on element objGid.";
  }
  output->writeVarInt((int)this->objGid);
  if(this->objUid < 0)
  {
    qDebug()<<"ERREUR - ItemForPreset -"<<"Forbidden value (" << this->objUid << ") on element objUid.";
  }
  output->writeVarInt((int)this->objUid);
}

void ItemForPreset::deserialize(Reader *input)
{
  this->deserializeAs_ItemForPreset(input);
}

void ItemForPreset::deserializeAs_ItemForPreset(Reader *input)
{
  this->_positionFunc(input);
  this->_objGidFunc(input);
  this->_objUidFunc(input);
}

void ItemForPreset::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ItemForPreset(tree);
}

void ItemForPreset::deserializeAsyncAs_ItemForPreset(FuncTree tree)
{
  tree.addChild(std::bind(&ItemForPreset::_positionFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ItemForPreset::_objGidFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ItemForPreset::_objUidFunc, this, std::placeholders::_1));
}

void ItemForPreset::_positionFunc(Reader *input)
{
  this->position = input->readShort();
  if(this->position < 0)
  {
    qDebug()<<"ERREUR - ItemForPreset -"<<"Forbidden value (" << this->position << ") on element of ItemForPreset.position.";
  }
}

void ItemForPreset::_objGidFunc(Reader *input)
{
  this->objGid = input->readVarUhInt();
  if(this->objGid < 0)
  {
    qDebug()<<"ERREUR - ItemForPreset -"<<"Forbidden value (" << this->objGid << ") on element of ItemForPreset.objGid.";
  }
}

void ItemForPreset::_objUidFunc(Reader *input)
{
  this->objUid = input->readVarUhInt();
  if(this->objUid < 0)
  {
    qDebug()<<"ERREUR - ItemForPreset -"<<"Forbidden value (" << this->objUid << ") on element of ItemForPreset.objUid.";
  }
}

ItemForPreset::ItemForPreset()
{
  m_types<<ClassEnum::ITEMFORPRESET;
}

bool ItemForPreset::operator==(const ItemForPreset &compared)
{
  if(position == compared.position)
  if(objGid == compared.objGid)
  if(objUid == compared.objUid)
  return true;
  
  return false;
}

