#include "SellerBuyerDescriptor.h"

void SellerBuyerDescriptor::serialize(Writer *output)
{
  this->serializeAs_SellerBuyerDescriptor(output);
}

void SellerBuyerDescriptor::serializeAs_SellerBuyerDescriptor(Writer *output)
{
  output->writeShort((short)this->quantities.size());
  for(uint _i1 = 0; _i1 < this->quantities.size(); _i1++)
  {
    if(this->quantities[_i1] < 0)
    {
      qDebug()<<"ERREUR - SellerBuyerDescriptor -"<<"Forbidden value (" << this->quantities[_i1] << ") on element 1 (starting at 1) of quantities.";
    }
    output->writeVarInt((int)this->quantities[_i1]);
  }
  output->writeShort((short)this->types.size());
  for(uint _i2 = 0; _i2 < this->types.size(); _i2++)
  {
    if(this->types[_i2] < 0)
    {
      qDebug()<<"ERREUR - SellerBuyerDescriptor -"<<"Forbidden value (" << this->types[_i2] << ") on element 2 (starting at 1) of types.";
    }
    output->writeVarInt((int)this->types[_i2]);
  }
  output->writeFloat(this->taxPercentage);
  output->writeFloat(this->taxModificationPercentage);
  if(this->maxItemLevel < 0 || this->maxItemLevel > 255)
  {
    qDebug()<<"ERREUR - SellerBuyerDescriptor -"<<"Forbidden value (" << this->maxItemLevel << ") on element maxItemLevel.";
  }
  output->writeByte(this->maxItemLevel);
  if(this->maxItemPerAccount < 0)
  {
    qDebug()<<"ERREUR - SellerBuyerDescriptor -"<<"Forbidden value (" << this->maxItemPerAccount << ") on element maxItemPerAccount.";
  }
  output->writeVarInt((int)this->maxItemPerAccount);
  output->writeInt((int)this->npcContextualId);
  if(this->unsoldDelay < 0)
  {
    qDebug()<<"ERREUR - SellerBuyerDescriptor -"<<"Forbidden value (" << this->unsoldDelay << ") on element unsoldDelay.";
  }
  output->writeVarShort((int)this->unsoldDelay);
}

void SellerBuyerDescriptor::deserialize(Reader *input)
{
  this->deserializeAs_SellerBuyerDescriptor(input);
}

void SellerBuyerDescriptor::deserializeAs_SellerBuyerDescriptor(Reader *input)
{
  uint _val1 = 0;
  uint _val2 = 0;
  uint _quantitiesLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _quantitiesLen; _i1++)
  {
    _val1 = input->readVarUhInt();
    if(_val1 < 0)
    {
      qDebug()<<"ERREUR - SellerBuyerDescriptor -"<<"Forbidden value (" << _val1 << ") on elements of quantities.";
    }
    this->quantities.append(_val1);
  }
  uint _typesLen = input->readUShort();
  for(uint _i2 = 0; _i2 < _typesLen; _i2++)
  {
    _val2 = input->readVarUhInt();
    if(_val2 < 0)
    {
      qDebug()<<"ERREUR - SellerBuyerDescriptor -"<<"Forbidden value (" << _val2 << ") on elements of types.";
    }
    this->types.append(_val2);
  }
  this->_taxPercentageFunc(input);
  this->_taxModificationPercentageFunc(input);
  this->_maxItemLevelFunc(input);
  this->_maxItemPerAccountFunc(input);
  this->_npcContextualIdFunc(input);
  this->_unsoldDelayFunc(input);
}

void SellerBuyerDescriptor::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_SellerBuyerDescriptor(tree);
}

void SellerBuyerDescriptor::deserializeAsyncAs_SellerBuyerDescriptor(FuncTree tree)
{
  this->_quantitiestree = tree.addChild(std::bind(&SellerBuyerDescriptor::_quantitiestreeFunc, this, std::placeholders::_1));
  this->_typestree = tree.addChild(std::bind(&SellerBuyerDescriptor::_typestreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&SellerBuyerDescriptor::_taxPercentageFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&SellerBuyerDescriptor::_taxModificationPercentageFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&SellerBuyerDescriptor::_maxItemLevelFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&SellerBuyerDescriptor::_maxItemPerAccountFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&SellerBuyerDescriptor::_npcContextualIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&SellerBuyerDescriptor::_unsoldDelayFunc, this, std::placeholders::_1));
}

void SellerBuyerDescriptor::_quantitiestreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_quantitiestree.addChild(std::bind(&SellerBuyerDescriptor::_quantitiesFunc, this, std::placeholders::_1));
  }
}

void SellerBuyerDescriptor::_quantitiesFunc(Reader *input)
{
  uint _val = input->readVarUhInt();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - SellerBuyerDescriptor -"<<"Forbidden value (" << _val << ") on elements of quantities.";
  }
  this->quantities.append(_val);
}

void SellerBuyerDescriptor::_typestreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_typestree.addChild(std::bind(&SellerBuyerDescriptor::_typesFunc, this, std::placeholders::_1));
  }
}

void SellerBuyerDescriptor::_typesFunc(Reader *input)
{
  uint _val = input->readVarUhInt();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - SellerBuyerDescriptor -"<<"Forbidden value (" << _val << ") on elements of types.";
  }
  this->types.append(_val);
}

void SellerBuyerDescriptor::_taxPercentageFunc(Reader *input)
{
  this->taxPercentage = input->readFloat();
}

void SellerBuyerDescriptor::_taxModificationPercentageFunc(Reader *input)
{
  this->taxModificationPercentage = input->readFloat();
}

void SellerBuyerDescriptor::_maxItemLevelFunc(Reader *input)
{
  this->maxItemLevel = input->readUByte();
  if(this->maxItemLevel < 0 || this->maxItemLevel > 255)
  {
    qDebug()<<"ERREUR - SellerBuyerDescriptor -"<<"Forbidden value (" << this->maxItemLevel << ") on element of SellerBuyerDescriptor.maxItemLevel.";
  }
}

void SellerBuyerDescriptor::_maxItemPerAccountFunc(Reader *input)
{
  this->maxItemPerAccount = input->readVarUhInt();
  if(this->maxItemPerAccount < 0)
  {
    qDebug()<<"ERREUR - SellerBuyerDescriptor -"<<"Forbidden value (" << this->maxItemPerAccount << ") on element of SellerBuyerDescriptor.maxItemPerAccount.";
  }
}

void SellerBuyerDescriptor::_npcContextualIdFunc(Reader *input)
{
  this->npcContextualId = input->readInt();
}

void SellerBuyerDescriptor::_unsoldDelayFunc(Reader *input)
{
  this->unsoldDelay = input->readVarUhShort();
  if(this->unsoldDelay < 0)
  {
    qDebug()<<"ERREUR - SellerBuyerDescriptor -"<<"Forbidden value (" << this->unsoldDelay << ") on element of SellerBuyerDescriptor.unsoldDelay.";
  }
}

SellerBuyerDescriptor::SellerBuyerDescriptor()
{
  m_types<<ClassEnum::SELLERBUYERDESCRIPTOR;
}

bool SellerBuyerDescriptor::operator==(const SellerBuyerDescriptor &compared)
{
  if(quantities == compared.quantities)
  if(types == compared.types)
  if(taxPercentage == compared.taxPercentage)
  if(taxModificationPercentage == compared.taxModificationPercentage)
  if(maxItemLevel == compared.maxItemLevel)
  if(maxItemPerAccount == compared.maxItemPerAccount)
  if(npcContextualId == compared.npcContextualId)
  if(unsoldDelay == compared.unsoldDelay)
  if(_quantitiestree == compared._quantitiestree)
  if(_typestree == compared._typestree)
  return true;
  
  return false;
}

