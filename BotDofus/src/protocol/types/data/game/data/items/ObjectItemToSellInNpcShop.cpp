#include "ObjectItemToSellInNpcShop.h"

void ObjectItemToSellInNpcShop::serialize(Writer *output)
{
  this->serializeAs_ObjectItemToSellInNpcShop(output);
}

void ObjectItemToSellInNpcShop::serializeAs_ObjectItemToSellInNpcShop(Writer *output)
{
  ObjectItemMinimalInformation::serializeAs_ObjectItemMinimalInformation(output);
  if(this->objectPrice < 0 || this->objectPrice > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ObjectItemToSellInNpcShop -"<<"Forbidden value (" << this->objectPrice << ") on element objectPrice.";
  }
  output->writeVarLong((double)this->objectPrice);
  output->writeUTF(this->buyCriterion);
}

void ObjectItemToSellInNpcShop::deserialize(Reader *input)
{
  this->deserializeAs_ObjectItemToSellInNpcShop(input);
}

void ObjectItemToSellInNpcShop::deserializeAs_ObjectItemToSellInNpcShop(Reader *input)
{
  ObjectItemMinimalInformation::deserialize(input);
  this->_objectPriceFunc(input);
  this->_buyCriterionFunc(input);
}

void ObjectItemToSellInNpcShop::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ObjectItemToSellInNpcShop(tree);
}

void ObjectItemToSellInNpcShop::deserializeAsyncAs_ObjectItemToSellInNpcShop(FuncTree tree)
{
  ObjectItemMinimalInformation::deserializeAsync(tree);
  tree.addChild(std::bind(&ObjectItemToSellInNpcShop::_objectPriceFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ObjectItemToSellInNpcShop::_buyCriterionFunc, this, std::placeholders::_1));
}

void ObjectItemToSellInNpcShop::_objectPriceFunc(Reader *input)
{
  this->objectPrice = input->readVarUhLong();
  if(this->objectPrice < 0 || this->objectPrice > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ObjectItemToSellInNpcShop -"<<"Forbidden value (" << this->objectPrice << ") on element of ObjectItemToSellInNpcShop.objectPrice.";
  }
}

void ObjectItemToSellInNpcShop::_buyCriterionFunc(Reader *input)
{
  this->buyCriterion = input->readUTF();
}

ObjectItemToSellInNpcShop::ObjectItemToSellInNpcShop()
{
  m_types<<ClassEnum::OBJECTITEMTOSELLINNPCSHOP;
}

bool ObjectItemToSellInNpcShop::operator==(const ObjectItemToSellInNpcShop &compared)
{
  if(objectPrice == compared.objectPrice)
  if(buyCriterion == compared.buyCriterion)
  return true;
  
  return false;
}

