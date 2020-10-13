#include "ForgettableSpellItem.h"

void ForgettableSpellItem::serialize(Writer *output)
{
  this->serializeAs_ForgettableSpellItem(output);
}

void ForgettableSpellItem::serializeAs_ForgettableSpellItem(Writer *output)
{
  SpellItem::serializeAs_SpellItem(output);
  output->writeBool(this->available);
}

void ForgettableSpellItem::deserialize(Reader *input)
{
  this->deserializeAs_ForgettableSpellItem(input);
}

void ForgettableSpellItem::deserializeAs_ForgettableSpellItem(Reader *input)
{
  SpellItem::deserialize(input);
  this->_availableFunc(input);
}

void ForgettableSpellItem::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ForgettableSpellItem(tree);
}

void ForgettableSpellItem::deserializeAsyncAs_ForgettableSpellItem(FuncTree tree)
{
  SpellItem::deserializeAsync(tree);
  tree.addChild(std::bind(&ForgettableSpellItem::_availableFunc, this, std::placeholders::_1));
}

void ForgettableSpellItem::_availableFunc(Reader *input)
{
  this->available = input->readBool();
}

ForgettableSpellItem::ForgettableSpellItem()
{
  m_types<<ClassEnum::FORGETTABLESPELLITEM;
}

bool ForgettableSpellItem::operator==(const ForgettableSpellItem &compared)
{
  if(available == compared.available)
  return true;
  
  return false;
}

