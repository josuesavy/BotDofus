#include "WatchInventoryContentMessage.h"

void WatchInventoryContentMessage::serialize(Writer *output)
{
  this->serializeAs_WatchInventoryContentMessage(output);
}

void WatchInventoryContentMessage::serializeAs_WatchInventoryContentMessage(Writer *output)
{
  InventoryContentMessage::serializeAs_InventoryContentMessage(output);
}

void WatchInventoryContentMessage::deserialize(Reader *input)
{
  this->deserializeAs_WatchInventoryContentMessage(input);
}

void WatchInventoryContentMessage::deserializeAs_WatchInventoryContentMessage(Reader *input)
{
  InventoryContentMessage::deserialize(input);
}

void WatchInventoryContentMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_WatchInventoryContentMessage(tree);
}

void WatchInventoryContentMessage::deserializeAsyncAs_WatchInventoryContentMessage(FuncTree tree)
{
  InventoryContentMessage::deserializeAsync(tree);
}

WatchInventoryContentMessage::WatchInventoryContentMessage()
{
  m_type = MessageEnum::WATCHINVENTORYCONTENTMESSAGE;
}

