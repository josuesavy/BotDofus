#include "MountReleasedMessage.h"

void MountReleasedMessage::serialize(Writer *output)
{
  this->serializeAs_MountReleasedMessage(output);
}

void MountReleasedMessage::serializeAs_MountReleasedMessage(Writer *output)
{
  output->writeVarInt((int)this->mountId);
}

void MountReleasedMessage::deserialize(Reader *input)
{
  this->deserializeAs_MountReleasedMessage(input);
}

void MountReleasedMessage::deserializeAs_MountReleasedMessage(Reader *input)
{
  this->_mountIdFunc(input);
}

void MountReleasedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_MountReleasedMessage(tree);
}

void MountReleasedMessage::deserializeAsyncAs_MountReleasedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&MountReleasedMessage::_mountIdFunc, this, std::placeholders::_1));
}

void MountReleasedMessage::_mountIdFunc(Reader *input)
{
  this->mountId = input->readVarInt();
}

MountReleasedMessage::MountReleasedMessage()
{
  m_type = MessageEnum::MOUNTRELEASEDMESSAGE;
}

