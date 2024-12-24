#include "ObjectItemGenericQuantity.h"

void ObjectItemGenericQuantity::serialize(Writer *output)
{
  this->serializeAs_ObjectItemGenericQuantity(output);
}

void ObjectItemGenericQuantity::serializeAs_ObjectItemGenericQuantity(Writer *output)
{
  Item::serializeAs_Item(output);
  if(this->objectGID < 0)
  {
    qDebug()<<"ERREUR - ObjectItemGenericQuantity -"<<"Forbidden value (" << this->objectGID << ") on element objectGID.";
  }
  output->writeVarInt((int)this->objectGID);
  if(this->quantity < 0)
  {
    qDebug()<<"ERREUR - ObjectItemGenericQuantity -"<<"Forbidden value (" << this->quantity << ") on element quantity.";
  }
  output->writeVarInt((int)this->quantity);
}

void ObjectItemGenericQuantity::deserialize(Reader *input)
{
  this->deserializeAs_ObjectItemGenericQuantity(input);
}

void ObjectItemGenericQuantity::deserializeAs_ObjectItemGenericQuantity(Reader *input)
{
  Item::deserialize(input);
  this->_objectGIDFunc(input);
  this->_quantityFunc(input);
}

void ObjectItemGenericQuantity::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ObjectItemGenericQuantity(tree);
}

void ObjectItemGenericQuantity::deserializeAsyncAs_ObjectItemGenericQuantity(FuncTree tree)
{
  Item::deserializeAsync(tree);
  tree.addChild(std::bind(&ObjectItemGenericQuantity::_objectGIDFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ObjectItemGenericQuantity::_quantityFunc, this, std::placeholders::_1));
}

void ObjectItemGenericQuantity::_objectGIDFunc(Reader *input)
{
  this->objectGID = input->readVarUhInt();
  if(this->objectGID < 0)
  {
    qDebug()<<"ERREUR - ObjectItemGenericQuantity -"<<"Forbidden value (" << this->objectGID << ") on element of ObjectItemGenericQuantity.objectGID.";
  }
}

void ObjectItemGenericQuantity::_quantityFunc(Reader *input)
{
  this->quantity = input->readVarUhInt();
  if(this->quantity < 0)
  {
    qDebug()<<"ERREUR - ObjectItemGenericQuantity -"<<"Forbidden value (" << this->quantity << ") on element of ObjectItemGenericQuantity.quantity.";
  }
}

ObjectItemGenericQuantity::ObjectItemGenericQuantity()
{
  m_types<<ClassEnum::OBJECTITEMGENERICQUANTITY;
}

bool ObjectItemGenericQuantity::operator==(const ObjectItemGenericQuantity &compared)
{
  if(objectGID == compared.objectGID)
  if(quantity == compared.quantity)
  return true;
  
  return false;
}

