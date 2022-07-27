#include "AlterationRemovedMessage.h"

void AlterationRemovedMessage::serialize(Writer *output)
{
  this->serializeAs_AlterationRemovedMessage(output);
}

void AlterationRemovedMessage::serializeAs_AlterationRemovedMessage(Writer *output)
{
  this->alteration->serializeAs_AlterationInfo(output);
}

void AlterationRemovedMessage::deserialize(Reader *input)
{
  this->deserializeAs_AlterationRemovedMessage(input);
}

void AlterationRemovedMessage::deserializeAs_AlterationRemovedMessage(Reader *input)
{
  this->alteration = QSharedPointer<AlterationInfo>(new AlterationInfo() );
  this->alteration->deserialize(input);
}

void AlterationRemovedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AlterationRemovedMessage(tree);
}

void AlterationRemovedMessage::deserializeAsyncAs_AlterationRemovedMessage(FuncTree tree)
{
  this->_alterationtree = tree.addChild(std::bind(&AlterationRemovedMessage::_alterationtreeFunc, this, std::placeholders::_1));
}

void AlterationRemovedMessage::_alterationtreeFunc(Reader *input)
{
  this->alteration = QSharedPointer<AlterationInfo>(new AlterationInfo() );
  this->alteration->deserializeAsync(this->_alterationtree);
}

AlterationRemovedMessage::AlterationRemovedMessage()
{
  m_type = MessageEnum::ALTERATIONREMOVEDMESSAGE;
}

