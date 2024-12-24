#include "ObjectItemQuantityPriceDateEffects.h"

void ObjectItemQuantityPriceDateEffects::serialize(Writer *output)
{
  this->serializeAs_ObjectItemQuantityPriceDateEffects(output);
}

void ObjectItemQuantityPriceDateEffects::serializeAs_ObjectItemQuantityPriceDateEffects(Writer *output)
{
  ObjectItemGenericQuantity::serializeAs_ObjectItemGenericQuantity(output);
  if(this->price < 0 || this->price > 9007199254740992)
  {
    qDebug()<<"ERREUR - ObjectItemQuantityPriceDateEffects -"<<"Forbidden value (" << this->price << ") on element price.";
  }
  output->writeVarLong((double)this->price);
  this->effects->serializeAs_ObjectEffects(output);
  if(this->date < 0)
  {
    qDebug()<<"ERREUR - ObjectItemQuantityPriceDateEffects -"<<"Forbidden value (" << this->date << ") on element date.";
  }
  output->writeInt((int)this->date);
}

void ObjectItemQuantityPriceDateEffects::deserialize(Reader *input)
{
  this->deserializeAs_ObjectItemQuantityPriceDateEffects(input);
}

void ObjectItemQuantityPriceDateEffects::deserializeAs_ObjectItemQuantityPriceDateEffects(Reader *input)
{
  ObjectItemGenericQuantity::deserialize(input);
  this->_priceFunc(input);
  this->effects = QSharedPointer<ObjectEffects>(new ObjectEffects() );
  this->effects->deserialize(input);
  this->_dateFunc(input);
}

void ObjectItemQuantityPriceDateEffects::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ObjectItemQuantityPriceDateEffects(tree);
}

void ObjectItemQuantityPriceDateEffects::deserializeAsyncAs_ObjectItemQuantityPriceDateEffects(FuncTree tree)
{
  ObjectItemGenericQuantity::deserializeAsync(tree);
  tree.addChild(std::bind(&ObjectItemQuantityPriceDateEffects::_priceFunc, this, std::placeholders::_1));
  this->_effectstree = tree.addChild(std::bind(&ObjectItemQuantityPriceDateEffects::_effectstreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ObjectItemQuantityPriceDateEffects::_dateFunc, this, std::placeholders::_1));
}

void ObjectItemQuantityPriceDateEffects::_priceFunc(Reader *input)
{
  this->price = input->readVarUhLong();
  if(this->price < 0 || this->price > 9007199254740992)
  {
    qDebug()<<"ERREUR - ObjectItemQuantityPriceDateEffects -"<<"Forbidden value (" << this->price << ") on element of ObjectItemQuantityPriceDateEffects.price.";
  }
}

void ObjectItemQuantityPriceDateEffects::_effectstreeFunc(Reader *input)
{
  this->effects = QSharedPointer<ObjectEffects>(new ObjectEffects() );
  this->effects->deserializeAsync(this->_effectstree);
}

void ObjectItemQuantityPriceDateEffects::_dateFunc(Reader *input)
{
  this->date = input->readInt();
  if(this->date < 0)
  {
    qDebug()<<"ERREUR - ObjectItemQuantityPriceDateEffects -"<<"Forbidden value (" << this->date << ") on element of ObjectItemQuantityPriceDateEffects.date.";
  }
}

ObjectItemQuantityPriceDateEffects::ObjectItemQuantityPriceDateEffects()
{
  m_types<<ClassEnum::OBJECTITEMQUANTITYPRICEDATEEFFECTS;
}

bool ObjectItemQuantityPriceDateEffects::operator==(const ObjectItemQuantityPriceDateEffects &compared)
{
  if(price == compared.price)
  if(effects == compared.effects)
  if(date == compared.date)
  if(_effectstree == compared._effectstree)
  return true;
  
  return false;
}

