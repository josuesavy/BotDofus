#include "ExchangeStartedWithMultiTabStorageMessage.h"

void ExchangeStartedWithMultiTabStorageMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeStartedWithMultiTabStorageMessage(output);
}

void ExchangeStartedWithMultiTabStorageMessage::serializeAs_ExchangeStartedWithMultiTabStorageMessage(Writer *output)
{
  ExchangeStartedMessage::serializeAs_ExchangeStartedMessage(output);
  if(this->storageMaxSlot < 0)
  {
    qDebug()<<"ERREUR - ExchangeStartedWithMultiTabStorageMessage -"<<"Forbidden value (" << this->storageMaxSlot << ") on element storageMaxSlot.";
  }
  output->writeVarInt((int)this->storageMaxSlot);
  if(this->tabNumber < 0)
  {
    qDebug()<<"ERREUR - ExchangeStartedWithMultiTabStorageMessage -"<<"Forbidden value (" << this->tabNumber << ") on element tabNumber.";
  }
  output->writeVarInt((int)this->tabNumber);
}

void ExchangeStartedWithMultiTabStorageMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeStartedWithMultiTabStorageMessage(input);
}

void ExchangeStartedWithMultiTabStorageMessage::deserializeAs_ExchangeStartedWithMultiTabStorageMessage(Reader *input)
{
  ExchangeStartedMessage::deserialize(input);
  this->_storageMaxSlotFunc(input);
  this->_tabNumberFunc(input);
}

void ExchangeStartedWithMultiTabStorageMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeStartedWithMultiTabStorageMessage(tree);
}

void ExchangeStartedWithMultiTabStorageMessage::deserializeAsyncAs_ExchangeStartedWithMultiTabStorageMessage(FuncTree tree)
{
  ExchangeStartedMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&ExchangeStartedWithMultiTabStorageMessage::_storageMaxSlotFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangeStartedWithMultiTabStorageMessage::_tabNumberFunc, this, std::placeholders::_1));
}

void ExchangeStartedWithMultiTabStorageMessage::_storageMaxSlotFunc(Reader *input)
{
  this->storageMaxSlot = input->readVarUhInt();
  if(this->storageMaxSlot < 0)
  {
    qDebug()<<"ERREUR - ExchangeStartedWithMultiTabStorageMessage -"<<"Forbidden value (" << this->storageMaxSlot << ") on element of ExchangeStartedWithMultiTabStorageMessage.storageMaxSlot.";
  }
}

void ExchangeStartedWithMultiTabStorageMessage::_tabNumberFunc(Reader *input)
{
  this->tabNumber = input->readVarUhInt();
  if(this->tabNumber < 0)
  {
    qDebug()<<"ERREUR - ExchangeStartedWithMultiTabStorageMessage -"<<"Forbidden value (" << this->tabNumber << ") on element of ExchangeStartedWithMultiTabStorageMessage.tabNumber.";
  }
}

ExchangeStartedWithMultiTabStorageMessage::ExchangeStartedWithMultiTabStorageMessage()
{
  m_type = MessageEnum::EXCHANGESTARTEDWITHMULTITABSTORAGEMESSAGE;
}

