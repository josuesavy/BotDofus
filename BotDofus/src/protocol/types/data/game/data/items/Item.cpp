#include "Item.h"

void Item::serialize(Writer *output)
{
}

void Item::serializeAs_Item(Writer *output)
{
}

void Item::deserialize(Reader *input)
{
}

void Item::deserializeAs_Item(Reader *input)
{
}

void Item::deserializeAsync(FuncTree tree)
{
}

void Item::deserializeAsyncAs_Item(FuncTree tree)
{
}

Item::Item()
{
  m_types<<ClassEnum::ITEM;
}

bool Item::operator==(const Item &compared)
{
  return true;
}

