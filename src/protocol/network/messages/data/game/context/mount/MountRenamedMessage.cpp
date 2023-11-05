#include "MountRenamedMessage.h"

void MountRenamedMessage::serialize(Writer *output)
{
  this->serializeAs_MountRenamedMessage(output);
}

void MountRenamedMessage::serializeAs_MountRenamedMessage(Writer *output)
{
  output->writeVarInt((int)this->mountId);
  output->writeUTF(this->name);
}

void MountRenamedMessage::deserialize(Reader *input)
{
  this->deserializeAs_MountRenamedMessage(input);
}

void MountRenamedMessage::deserializeAs_MountRenamedMessage(Reader *input)
{
  this->_mountIdFunc(input);
  this->_nameFunc(input);
}

void MountRenamedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_MountRenamedMessage(tree);
}

void MountRenamedMessage::deserializeAsyncAs_MountRenamedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&MountRenamedMessage::_mountIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&MountRenamedMessage::_nameFunc, this, std::placeholders::_1));
}

void MountRenamedMessage::_mountIdFunc(Reader *input)
{
  this->mountId = input->readVarInt();
}

void MountRenamedMessage::_nameFunc(Reader *input)
{
  this->name = input->readUTF();
}

MountRenamedMessage::MountRenamedMessage()
{
  m_type = MessageEnum::MOUNTRENAMEDMESSAGE;
}

