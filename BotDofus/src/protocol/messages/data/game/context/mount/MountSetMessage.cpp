#include "MountSetMessage.h"

void MountSetMessage::serialize(Writer *output)
{
  this->serializeAs_MountSetMessage(output);
}

void MountSetMessage::serializeAs_MountSetMessage(Writer *output)
{
  this->mountData->serializeAs_MountClientData(output);
}

void MountSetMessage::deserialize(Reader *input)
{
  this->deserializeAs_MountSetMessage(input);
}

void MountSetMessage::deserializeAs_MountSetMessage(Reader *input)
{
  this->mountData = QSharedPointer<MountClientData>(new MountClientData() );
  this->mountData->deserialize(input);
}

void MountSetMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_MountSetMessage(tree);
}

void MountSetMessage::deserializeAsyncAs_MountSetMessage(FuncTree tree)
{
  this->_mountDatatree = tree.addChild(std::bind(&MountSetMessage::_mountDatatreeFunc, this, std::placeholders::_1));
}

void MountSetMessage::_mountDatatreeFunc(Reader *input)
{
  this->mountData = QSharedPointer<MountClientData>(new MountClientData() );
  this->mountData->deserializeAsync(this->_mountDatatree);
}

MountSetMessage::MountSetMessage()
{
  m_type = MessageEnum::MOUNTSETMESSAGE;
}

