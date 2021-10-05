#include "ObjectItemInformationWithQuantity.h"

void ObjectItemInformationWithQuantity::serialize(Writer *output)
{
  this->serializeAs_ObjectItemInformationWithQuantity(output);
}

void ObjectItemInformationWithQuantity::serializeAs_ObjectItemInformationWithQuantity(Writer *output)
{
  ObjectItemMinimalInformation::serializeAs_ObjectItemMinimalInformation(output);
  if(this->quantity < 0)
  {
    qDebug()<<"ERREUR - ObjectItemInformationWithQuantity -"<<"Forbidden value (" << this->quantity << ") on element quantity.";
  }
  output->writeVarInt((int)this->quantity);
}

void ObjectItemInformationWithQuantity::deserialize(Reader *input)
{
  this->deserializeAs_ObjectItemInformationWithQuantity(input);
}

void ObjectItemInformationWithQuantity::deserializeAs_ObjectItemInformationWithQuantity(Reader *input)
{
  ObjectItemMinimalInformation::deserialize(input);
  this->_quantityFunc(input);
}

void ObjectItemInformationWithQuantity::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ObjectItemInformationWithQuantity(tree);
}

void ObjectItemInformationWithQuantity::deserializeAsyncAs_ObjectItemInformationWithQuantity(FuncTree tree)
{
  ObjectItemMinimalInformation::deserializeAsync(tree);
  tree.addChild(std::bind(&ObjectItemInformationWithQuantity::_quantityFunc, this, std::placeholders::_1));
}

void ObjectItemInformationWithQuantity::_quantityFunc(Reader *input)
{
  this->quantity = input->readVarUhInt();
  if(this->quantity < 0)
  {
    qDebug()<<"ERREUR - ObjectItemInformationWithQuantity -"<<"Forbidden value (" << this->quantity << ") on element of ObjectItemInformationWithQuantity.quantity.";
  }
}

ObjectItemInformationWithQuantity::ObjectItemInformationWithQuantity()
{
  m_types<<ClassEnum::OBJECTITEMINFORMATIONWITHQUANTITY;
}

bool ObjectItemInformationWithQuantity::operator==(const ObjectItemInformationWithQuantity &compared)
{
  if(quantity == compared.quantity)
  return true;
  
  return false;
}

