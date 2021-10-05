#include "MountDataMessage.h"

void MountDataMessage::serialize(Writer *output)
{
  this->serializeAs_MountDataMessage(output);
}

void MountDataMessage::serializeAs_MountDataMessage(Writer *output)
{
  this->mountData->serializeAs_MountClientData(output);
}

void MountDataMessage::deserialize(Reader *input)
{
  this->deserializeAs_MountDataMessage(input);
}

void MountDataMessage::deserializeAs_MountDataMessage(Reader *input)
{
  this->mountData = QSharedPointer<MountClientData>(new MountClientData() );
  this->mountData->deserialize(input);
}

void MountDataMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_MountDataMessage(tree);
}

void MountDataMessage::deserializeAsyncAs_MountDataMessage(FuncTree tree)
{
  this->_mountDatatree = tree.addChild(std::bind(&MountDataMessage::_mountDatatreeFunc, this, std::placeholders::_1));
}

void MountDataMessage::_mountDatatreeFunc(Reader *input)
{
  this->mountData = QSharedPointer<MountClientData>(new MountClientData() );
  this->mountData->deserializeAsync(this->_mountDatatree);
}

MountDataMessage::MountDataMessage()
{
  m_type = MessageEnum::MOUNTDATAMESSAGE;
}

