#include "AccessoryPreviewMessage.h"

void AccessoryPreviewMessage::serialize(Writer *output)
{
  this->serializeAs_AccessoryPreviewMessage(output);
}

void AccessoryPreviewMessage::serializeAs_AccessoryPreviewMessage(Writer *output)
{
  this->look->serializeAs_EntityLook(output);
}

void AccessoryPreviewMessage::deserialize(Reader *input)
{
  this->deserializeAs_AccessoryPreviewMessage(input);
}

void AccessoryPreviewMessage::deserializeAs_AccessoryPreviewMessage(Reader *input)
{
  this->look = QSharedPointer<EntityLook>(new EntityLook() );
  this->look->deserialize(input);
}

void AccessoryPreviewMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AccessoryPreviewMessage(tree);
}

void AccessoryPreviewMessage::deserializeAsyncAs_AccessoryPreviewMessage(FuncTree tree)
{
  this->_looktree = tree.addChild(std::bind(&AccessoryPreviewMessage::_looktreeFunc, this, std::placeholders::_1));
}

void AccessoryPreviewMessage::_looktreeFunc(Reader *input)
{
  this->look = QSharedPointer<EntityLook>(new EntityLook() );
  this->look->deserializeAsync(this->_looktree);
}

AccessoryPreviewMessage::AccessoryPreviewMessage()
{
  m_type = MessageEnum::ACCESSORYPREVIEWMESSAGE;
}

