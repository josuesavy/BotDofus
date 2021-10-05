#include "StorageInventoryContentMessage.h"

void StorageInventoryContentMessage::serialize(Writer *output)
{
  this->serializeAs_StorageInventoryContentMessage(output);
}

void StorageInventoryContentMessage::serializeAs_StorageInventoryContentMessage(Writer *output)
{
  InventoryContentMessage::serializeAs_InventoryContentMessage(output);
}

void StorageInventoryContentMessage::deserialize(Reader *input)
{
  this->deserializeAs_StorageInventoryContentMessage(input);
}

void StorageInventoryContentMessage::deserializeAs_StorageInventoryContentMessage(Reader *input)
{
  InventoryContentMessage::deserialize(input);
}

void StorageInventoryContentMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_StorageInventoryContentMessage(tree);
}

void StorageInventoryContentMessage::deserializeAsyncAs_StorageInventoryContentMessage(FuncTree tree)
{
  InventoryContentMessage::deserializeAsync(tree);
}

StorageInventoryContentMessage::StorageInventoryContentMessage()
{
  m_type = MessageEnum::STORAGEINVENTORYCONTENTMESSAGE;
}

