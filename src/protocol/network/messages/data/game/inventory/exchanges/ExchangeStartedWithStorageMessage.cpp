#include "ExchangeStartedWithStorageMessage.h"

void ExchangeStartedWithStorageMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeStartedWithStorageMessage(output);
}

void ExchangeStartedWithStorageMessage::serializeAs_ExchangeStartedWithStorageMessage(Writer *output)
{
  ExchangeStartedMessage::serializeAs_ExchangeStartedMessage(output);
  if(this->storageMaxSlot < 0)
  {
    qDebug()<<"ERREUR - ExchangeStartedWithStorageMessage -"<<"Forbidden value (" << this->storageMaxSlot << ") on element storageMaxSlot.";
  }
  output->writeVarInt((int)this->storageMaxSlot);
}

void ExchangeStartedWithStorageMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeStartedWithStorageMessage(input);
}

void ExchangeStartedWithStorageMessage::deserializeAs_ExchangeStartedWithStorageMessage(Reader *input)
{
  ExchangeStartedMessage::deserialize(input);
  this->_storageMaxSlotFunc(input);
}

void ExchangeStartedWithStorageMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeStartedWithStorageMessage(tree);
}

void ExchangeStartedWithStorageMessage::deserializeAsyncAs_ExchangeStartedWithStorageMessage(FuncTree tree)
{
  ExchangeStartedMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&ExchangeStartedWithStorageMessage::_storageMaxSlotFunc, this, std::placeholders::_1));
}

void ExchangeStartedWithStorageMessage::_storageMaxSlotFunc(Reader *input)
{
  this->storageMaxSlot = input->readVarUhInt();
  if(this->storageMaxSlot < 0)
  {
    qDebug()<<"ERREUR - ExchangeStartedWithStorageMessage -"<<"Forbidden value (" << this->storageMaxSlot << ") on element of ExchangeStartedWithStorageMessage.storageMaxSlot.";
  }
}

ExchangeStartedWithStorageMessage::ExchangeStartedWithStorageMessage()
{
  m_type = MessageEnum::EXCHANGESTARTEDWITHSTORAGEMESSAGE;
}

