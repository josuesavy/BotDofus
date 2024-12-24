#include "MountRenameRequestMessage.h"

void MountRenameRequestMessage::serialize(Writer *output)
{
  this->serializeAs_MountRenameRequestMessage(output);
}

void MountRenameRequestMessage::serializeAs_MountRenameRequestMessage(Writer *output)
{
  output->writeUTF(this->name);
  output->writeVarInt((int)this->mountId);
}

void MountRenameRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_MountRenameRequestMessage(input);
}

void MountRenameRequestMessage::deserializeAs_MountRenameRequestMessage(Reader *input)
{
  this->_nameFunc(input);
  this->_mountIdFunc(input);
}

void MountRenameRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_MountRenameRequestMessage(tree);
}

void MountRenameRequestMessage::deserializeAsyncAs_MountRenameRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&MountRenameRequestMessage::_nameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&MountRenameRequestMessage::_mountIdFunc, this, std::placeholders::_1));
}

void MountRenameRequestMessage::_nameFunc(Reader *input)
{
  this->name = input->readUTF();
}

void MountRenameRequestMessage::_mountIdFunc(Reader *input)
{
  this->mountId = input->readVarInt();
}

MountRenameRequestMessage::MountRenameRequestMessage()
{
  m_type = MessageEnum::MOUNTRENAMEREQUESTMESSAGE;
}

