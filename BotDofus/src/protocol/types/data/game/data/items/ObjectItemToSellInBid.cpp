#include "ObjectItemToSellInBid.h"

void ObjectItemToSellInBid::serialize(Writer *output)
{
  this->serializeAs_ObjectItemToSellInBid(output);
}

void ObjectItemToSellInBid::serializeAs_ObjectItemToSellInBid(Writer *output)
{
  ObjectItemToSell::serializeAs_ObjectItemToSell(output);
  if(this->unsoldDelay < 0)
  {
    qDebug()<<"ERREUR - ObjectItemToSellInBid -"<<"Forbidden value (" << this->unsoldDelay << ") on element unsoldDelay.";
  }
  output->writeInt((int)this->unsoldDelay);
}

void ObjectItemToSellInBid::deserialize(Reader *input)
{
  this->deserializeAs_ObjectItemToSellInBid(input);
}

void ObjectItemToSellInBid::deserializeAs_ObjectItemToSellInBid(Reader *input)
{
  ObjectItemToSell::deserialize(input);
  this->_unsoldDelayFunc(input);
}

void ObjectItemToSellInBid::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ObjectItemToSellInBid(tree);
}

void ObjectItemToSellInBid::deserializeAsyncAs_ObjectItemToSellInBid(FuncTree tree)
{
  ObjectItemToSell::deserializeAsync(tree);
  tree.addChild(std::bind(&ObjectItemToSellInBid::_unsoldDelayFunc, this, std::placeholders::_1));
}

void ObjectItemToSellInBid::_unsoldDelayFunc(Reader *input)
{
  this->unsoldDelay = input->readInt();
  if(this->unsoldDelay < 0)
  {
    qDebug()<<"ERREUR - ObjectItemToSellInBid -"<<"Forbidden value (" << this->unsoldDelay << ") on element of ObjectItemToSellInBid.unsoldDelay.";
  }
}

ObjectItemToSellInBid::ObjectItemToSellInBid()
{
  m_types<<ClassEnum::OBJECTITEMTOSELLINBID;
}

bool ObjectItemToSellInBid::operator==(const ObjectItemToSellInBid &compared)
{
  if(unsoldDelay == compared.unsoldDelay)
  return true;
  
  return false;
}

