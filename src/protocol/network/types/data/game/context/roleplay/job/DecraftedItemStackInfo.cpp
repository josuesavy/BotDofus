#include "DecraftedItemStackInfo.h"

void DecraftedItemStackInfo::serialize(Writer *output)
{
  this->serializeAs_DecraftedItemStackInfo(output);
}

void DecraftedItemStackInfo::serializeAs_DecraftedItemStackInfo(Writer *output)
{
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - DecraftedItemStackInfo -"<<"Forbidden value (" << this->objectUID << ") on element objectUID.";
  }
  output->writeVarInt((int)this->objectUID);
  output->writeFloat(this->bonusMin);
  output->writeFloat(this->bonusMax);
  output->writeShort((short)this->runesId.size());
  for(uint _i4 = 0; _i4 < this->runesId.size(); _i4++)
  {
    if(this->runesId[_i4] < 0)
    {
      qDebug()<<"ERREUR - DecraftedItemStackInfo -"<<"Forbidden value (" << this->runesId[_i4] << ") on element 4 (starting at 1) of runesId.";
    }
    output->writeVarInt((int)this->runesId[_i4]);
  }
  output->writeShort((short)this->runesQty.size());
  for(uint _i5 = 0; _i5 < this->runesQty.size(); _i5++)
  {
    if(this->runesQty[_i5] < 0)
    {
      qDebug()<<"ERREUR - DecraftedItemStackInfo -"<<"Forbidden value (" << this->runesQty[_i5] << ") on element 5 (starting at 1) of runesQty.";
    }
    output->writeVarInt((int)this->runesQty[_i5]);
  }
}

void DecraftedItemStackInfo::deserialize(Reader *input)
{
  this->deserializeAs_DecraftedItemStackInfo(input);
}

void DecraftedItemStackInfo::deserializeAs_DecraftedItemStackInfo(Reader *input)
{
  uint _val4 = 0;
  uint _val5 = 0;
  this->_objectUIDFunc(input);
  this->_bonusMinFunc(input);
  this->_bonusMaxFunc(input);
  uint _runesIdLen = uint(input->readUShort());
  for(uint _i4 = 0; _i4 < _runesIdLen; _i4++)
  {
    _val4 = input->readVarUhInt();
    if(_val4 < 0)
    {
      qDebug()<<"ERREUR - DecraftedItemStackInfo -"<<"Forbidden value (" << _val4 << ") on elements of runesId.";
    }
    this->runesId.append(_val4);
  }
  uint _runesQtyLen = uint(input->readUShort());
  for(uint _i5 = 0; _i5 < _runesQtyLen; _i5++)
  {
    _val5 = input->readVarUhInt();
    if(_val5 < 0)
    {
      qDebug()<<"ERREUR - DecraftedItemStackInfo -"<<"Forbidden value (" << _val5 << ") on elements of runesQty.";
    }
    this->runesQty.append(_val5);
  }
}

void DecraftedItemStackInfo::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_DecraftedItemStackInfo(tree);
}

void DecraftedItemStackInfo::deserializeAsyncAs_DecraftedItemStackInfo(FuncTree tree)
{
  tree.addChild(std::bind(&DecraftedItemStackInfo::_objectUIDFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&DecraftedItemStackInfo::_bonusMinFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&DecraftedItemStackInfo::_bonusMaxFunc, this, std::placeholders::_1));
  this->_runesIdtree = tree.addChild(std::bind(&DecraftedItemStackInfo::_runesIdtreeFunc, this, std::placeholders::_1));
  this->_runesQtytree = tree.addChild(std::bind(&DecraftedItemStackInfo::_runesQtytreeFunc, this, std::placeholders::_1));
}

void DecraftedItemStackInfo::_objectUIDFunc(Reader *input)
{
  this->objectUID = input->readVarUhInt();
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - DecraftedItemStackInfo -"<<"Forbidden value (" << this->objectUID << ") on element of DecraftedItemStackInfo.objectUID.";
  }
}

void DecraftedItemStackInfo::_bonusMinFunc(Reader *input)
{
  this->bonusMin = input->readFloat();
}

void DecraftedItemStackInfo::_bonusMaxFunc(Reader *input)
{
  this->bonusMax = input->readFloat();
}

void DecraftedItemStackInfo::_runesIdtreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_runesIdtree.addChild(std::bind(&DecraftedItemStackInfo::_runesIdFunc, this, std::placeholders::_1));
  }
}

void DecraftedItemStackInfo::_runesIdFunc(Reader *input)
{
  uint _val = input->readVarUhInt();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - DecraftedItemStackInfo -"<<"Forbidden value (" << _val << ") on elements of runesId.";
  }
  this->runesId.append(_val);
}

void DecraftedItemStackInfo::_runesQtytreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_runesQtytree.addChild(std::bind(&DecraftedItemStackInfo::_runesQtyFunc, this, std::placeholders::_1));
  }
}

void DecraftedItemStackInfo::_runesQtyFunc(Reader *input)
{
  uint _val = input->readVarUhInt();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - DecraftedItemStackInfo -"<<"Forbidden value (" << _val << ") on elements of runesQty.";
  }
  this->runesQty.append(_val);
}

DecraftedItemStackInfo::DecraftedItemStackInfo()
{
  m_types<<ClassEnum::DECRAFTEDITEMSTACKINFO;
}

bool DecraftedItemStackInfo::operator==(const DecraftedItemStackInfo &compared)
{
  if(objectUID == compared.objectUID)
  if(bonusMin == compared.bonusMin)
  if(bonusMax == compared.bonusMax)
  if(runesId == compared.runesId)
  if(runesQty == compared.runesQty)
  if(_runesIdtree == compared._runesIdtree)
  if(_runesQtytree == compared._runesQtytree)
  return true;
  
  return false;
}

