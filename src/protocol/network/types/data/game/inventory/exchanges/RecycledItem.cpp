#include "RecycledItem.h"

void RecycledItem::serialize(Writer *output)
{
  this->serializeAs_RecycledItem(output);
}

void RecycledItem::serializeAs_RecycledItem(Writer *output)
{
  if(this->id < 0)
  {
    qDebug()<<"ERREUR - RecycledItem -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  output->writeVarInt((int)this->id);
  if(this->qty < 0 || this->qty > 4294967295)
  {
    qDebug()<<"ERREUR - RecycledItem -"<<"Forbidden value (" << this->qty << ") on element qty.";
  }
  output->writeUInt((uint)this->qty);
}

void RecycledItem::deserialize(Reader *input)
{
  this->deserializeAs_RecycledItem(input);
}

void RecycledItem::deserializeAs_RecycledItem(Reader *input)
{
  this->_idFunc(input);
  this->_qtyFunc(input);
}

void RecycledItem::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_RecycledItem(tree);
}

void RecycledItem::deserializeAsyncAs_RecycledItem(FuncTree tree)
{
  tree.addChild(std::bind(&RecycledItem::_idFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&RecycledItem::_qtyFunc, this, std::placeholders::_1));
}

void RecycledItem::_idFunc(Reader *input)
{
  this->id = input->readVarUhInt();
  if(this->id < 0)
  {
    qDebug()<<"ERREUR - RecycledItem -"<<"Forbidden value (" << this->id << ") on element of RecycledItem.id.";
  }
}

void RecycledItem::_qtyFunc(Reader *input)
{
  this->qty = input->readUInt();
  if(this->qty < 0 || this->qty > 4294967295)
  {
    qDebug()<<"ERREUR - RecycledItem -"<<"Forbidden value (" << this->qty << ") on element of RecycledItem.qty.";
  }
}

RecycledItem::RecycledItem()
{
  m_types<<ClassEnum::RECYCLEDITEM;
}

bool RecycledItem::operator==(const RecycledItem &compared)
{
  if(id == compared.id)
  if(qty == compared.qty)
  return true;
  
  return false;
}

