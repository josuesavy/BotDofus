#include "MountSterilizedMessage.h"

void MountSterilizedMessage::serialize(Writer *output)
{
  this->serializeAs_MountSterilizedMessage(output);
}

void MountSterilizedMessage::serializeAs_MountSterilizedMessage(Writer *output)
{
  output->writeVarInt((int)this->mountId);
}

void MountSterilizedMessage::deserialize(Reader *input)
{
  this->deserializeAs_MountSterilizedMessage(input);
}

void MountSterilizedMessage::deserializeAs_MountSterilizedMessage(Reader *input)
{
  this->_mountIdFunc(input);
}

void MountSterilizedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_MountSterilizedMessage(tree);
}

void MountSterilizedMessage::deserializeAsyncAs_MountSterilizedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&MountSterilizedMessage::_mountIdFunc, this, std::placeholders::_1));
}

void MountSterilizedMessage::_mountIdFunc(Reader *input)
{
  this->mountId = input->readVarInt();
}

MountSterilizedMessage::MountSterilizedMessage()
{
  m_type = MessageEnum::MOUNTSTERILIZEDMESSAGE;
}

