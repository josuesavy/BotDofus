#include "AddListenerOnSynchronizedStorageMessage.h"

void AddListenerOnSynchronizedStorageMessage::serialize(Writer *output)
{
  this->serializeAs_AddListenerOnSynchronizedStorageMessage(output);
}

void AddListenerOnSynchronizedStorageMessage::serializeAs_AddListenerOnSynchronizedStorageMessage(Writer *output)
{
  output->writeUTF(this->player);
}

void AddListenerOnSynchronizedStorageMessage::deserialize(Reader *input)
{
  this->deserializeAs_AddListenerOnSynchronizedStorageMessage(input);
}

void AddListenerOnSynchronizedStorageMessage::deserializeAs_AddListenerOnSynchronizedStorageMessage(Reader *input)
{
  this->_playerFunc(input);
}

void AddListenerOnSynchronizedStorageMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AddListenerOnSynchronizedStorageMessage(tree);
}

void AddListenerOnSynchronizedStorageMessage::deserializeAsyncAs_AddListenerOnSynchronizedStorageMessage(FuncTree tree)
{
  tree.addChild(std::bind(&AddListenerOnSynchronizedStorageMessage::_playerFunc, this, std::placeholders::_1));
}

void AddListenerOnSynchronizedStorageMessage::_playerFunc(Reader *input)
{
  this->player = input->readUTF();
}

AddListenerOnSynchronizedStorageMessage::AddListenerOnSynchronizedStorageMessage()
{
  m_type = MessageEnum::ADDLISTENERONSYNCHRONIZEDSTORAGEMESSAGE;
}

