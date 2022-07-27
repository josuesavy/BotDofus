#include "SpellItem.h"

void SpellItem::serialize(Writer *output)
{
  this->serializeAs_SpellItem(output);
}

void SpellItem::serializeAs_SpellItem(Writer *output)
{
  Item::serializeAs_Item(output);
  output->writeInt((int)this->spellId);
  if(this->spellLevel < 1 || this->spellLevel > 32767)
  {
    qDebug()<<"ERREUR - SpellItem -"<<"Forbidden value (" << this->spellLevel << ") on element spellLevel.";
  }
  output->writeShort((short)this->spellLevel);
}

void SpellItem::deserialize(Reader *input)
{
  this->deserializeAs_SpellItem(input);
}

void SpellItem::deserializeAs_SpellItem(Reader *input)
{
  Item::deserialize(input);
  this->_spellIdFunc(input);
  this->_spellLevelFunc(input);
}

void SpellItem::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_SpellItem(tree);
}

void SpellItem::deserializeAsyncAs_SpellItem(FuncTree tree)
{
  Item::deserializeAsync(tree);
  tree.addChild(std::bind(&SpellItem::_spellIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&SpellItem::_spellLevelFunc, this, std::placeholders::_1));
}

void SpellItem::_spellIdFunc(Reader *input)
{
  this->spellId = input->readInt();
}

void SpellItem::_spellLevelFunc(Reader *input)
{
  this->spellLevel = input->readShort();
  if(this->spellLevel < 1 || this->spellLevel > 32767)
  {
    qDebug()<<"ERREUR - SpellItem -"<<"Forbidden value (" << this->spellLevel << ") on element of SpellItem.spellLevel.";
  }
}

SpellItem::SpellItem()
{
  m_types<<ClassEnum::SPELLITEM;
}

bool SpellItem::operator==(const SpellItem &compared)
{
  if(spellId == compared.spellId)
  if(spellLevel == compared.spellLevel)
  return true;
  
  return false;
}

