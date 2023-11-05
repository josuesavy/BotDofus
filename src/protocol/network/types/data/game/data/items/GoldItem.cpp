#include "GoldItem.h"

void GoldItem::serialize(Writer *output)
{
  this->serializeAs_GoldItem(output);
}

void GoldItem::serializeAs_GoldItem(Writer *output)
{
  Item::serializeAs_Item(output);
  if(this->sum < 0 || this->sum > 9007199254740992)
  {
    qDebug()<<"ERREUR - GoldItem -"<<"Forbidden value (" << this->sum << ") on element sum.";
  }
  output->writeVarLong((double)this->sum);
}

void GoldItem::deserialize(Reader *input)
{
  this->deserializeAs_GoldItem(input);
}

void GoldItem::deserializeAs_GoldItem(Reader *input)
{
  Item::deserialize(input);
  this->_sumFunc(input);
}

void GoldItem::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GoldItem(tree);
}

void GoldItem::deserializeAsyncAs_GoldItem(FuncTree tree)
{
  Item::deserializeAsync(tree);
  tree.addChild(std::bind(&GoldItem::_sumFunc, this, std::placeholders::_1));
}

void GoldItem::_sumFunc(Reader *input)
{
  this->sum = input->readVarUhLong();
  if(this->sum < 0 || this->sum > 9007199254740992)
  {
    qDebug()<<"ERREUR - GoldItem -"<<"Forbidden value (" << this->sum << ") on element of GoldItem.sum.";
  }
}

GoldItem::GoldItem()
{
  m_types<<ClassEnum::GOLDITEM;
}

bool GoldItem::operator==(const GoldItem &compared)
{
  if(sum == compared.sum)
  return true;
  
  return false;
}

