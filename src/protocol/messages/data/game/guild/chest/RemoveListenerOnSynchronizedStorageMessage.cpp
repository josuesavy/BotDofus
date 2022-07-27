#include "RemoveListenerOnSynchronizedStorageMessage.h"

void RemoveListenerOnSynchronizedStorageMessage::serialize(Writer *output)
{
  this->serializeAs_RemoveListenerOnSynchronizedStorageMessage(output);
}

void RemoveListenerOnSynchronizedStorageMessage::serializeAs_RemoveListenerOnSynchronizedStorageMessage(Writer *output)
{
  output->writeUTF(this->player);
}

void RemoveListenerOnSynchronizedStorageMessage::deserialize(Reader *input)
{
  this->deserializeAs_RemoveListenerOnSynchronizedStorageMessage(input);
}

void RemoveListenerOnSynchronizedStorageMessage::deserializeAs_RemoveListenerOnSynchronizedStorageMessage(Reader *input)
{
  this->_playerFunc(input);
}

void RemoveListenerOnSynchronizedStorageMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_RemoveListenerOnSynchronizedStorageMessage(tree);
}

void RemoveListenerOnSynchronizedStorageMessage::deserializeAsyncAs_RemoveListenerOnSynchronizedStorageMessage(FuncTree tree)
{
  tree.addChild(std::bind(&RemoveListenerOnSynchronizedStorageMessage::_playerFunc, this, std::placeholders::_1));
}

void RemoveListenerOnSynchronizedStorageMessage::_playerFunc(Reader *input)
{
  this->player = input->readUTF();
}

RemoveListenerOnSynchronizedStorageMessage::RemoveListenerOnSynchronizedStorageMessage()
{
  m_type = MessageEnum::REMOVELISTENERONSYNCHRONIZEDSTORAGEMESSAGE;
}

