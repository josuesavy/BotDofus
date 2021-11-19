#include "ObjectItemQuantity.h"

void ObjectItemQuantity::serialize(Writer *output)
{
  this->serializeAs_ObjectItemQuantity(output);
}

void ObjectItemQuantity::serializeAs_ObjectItemQuantity(Writer *output)
{
  Item::serializeAs_Item(output);
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - ObjectItemQuantity -"<<"Forbidden value (" << this->objectUID << ") on element objectUID.";
  }
  output->writeVarInt((int)this->objectUID);
  if(this->quantity < 0)
  {
    qDebug()<<"ERREUR - ObjectItemQuantity -"<<"Forbidden value (" << this->quantity << ") on element quantity.";
  }
  output->writeVarInt((int)this->quantity);
}

void ObjectItemQuantity::deserialize(Reader *input)
{
  this->deserializeAs_ObjectItemQuantity(input);
}

void ObjectItemQuantity::deserializeAs_ObjectItemQuantity(Reader *input)
{
  Item::deserialize(input);
  this->_objectUIDFunc(input);
  this->_quantityFunc(input);
}

void ObjectItemQuantity::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ObjectItemQuantity(tree);
}

void ObjectItemQuantity::deserializeAsyncAs_ObjectItemQuantity(FuncTree tree)
{
  Item::deserializeAsync(tree);
  tree.addChild(std::bind(&ObjectItemQuantity::_objectUIDFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ObjectItemQuantity::_quantityFunc, this, std::placeholders::_1));
}

void ObjectItemQuantity::_objectUIDFunc(Reader *input)
{
  this->objectUID = input->readVarUhInt();
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - ObjectItemQuantity -"<<"Forbidden value (" << this->objectUID << ") on element of ObjectItemQuantity.objectUID.";
  }
}

void ObjectItemQuantity::_quantityFunc(Reader *input)
{
  this->quantity = input->readVarUhInt();
  if(this->quantity < 0)
  {
    qDebug()<<"ERREUR - ObjectItemQuantity -"<<"Forbidden value (" << this->quantity << ") on element of ObjectItemQuantity.quantity.";
  }
}

ObjectItemQuantity::ObjectItemQuantity()
{
  m_types<<ClassEnum::OBJECTITEMQUANTITY;
}

bool ObjectItemQuantity::operator==(const ObjectItemQuantity &compared)
{
  if(objectUID == compared.objectUID)
  if(quantity == compared.quantity)
  return true;
  
  return false;
}

