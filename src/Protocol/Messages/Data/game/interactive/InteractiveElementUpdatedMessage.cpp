#include "InteractiveElementUpdatedMessage.h"

void InteractiveElementUpdatedMessage::serialize(Writer *output)
{
  this->serializeAs_InteractiveElementUpdatedMessage(output);
}

void InteractiveElementUpdatedMessage::serializeAs_InteractiveElementUpdatedMessage(Writer *output)
{
  this->interactiveElement->serializeAs_InteractiveElement(output);
}

void InteractiveElementUpdatedMessage::deserialize(Reader *input)
{
  this->deserializeAs_InteractiveElementUpdatedMessage(input);
}

void InteractiveElementUpdatedMessage::deserializeAs_InteractiveElementUpdatedMessage(Reader *input)
{
  this->interactiveElement = QSharedPointer<InteractiveElement>(new InteractiveElement() );
  this->interactiveElement->deserialize(input);
}

void InteractiveElementUpdatedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_InteractiveElementUpdatedMessage(tree);
}

void InteractiveElementUpdatedMessage::deserializeAsyncAs_InteractiveElementUpdatedMessage(FuncTree tree)
{
  this->_interactiveElementtree = tree.addChild(std::bind(&InteractiveElementUpdatedMessage::_interactiveElementtreeFunc, this, std::placeholders::_1));
}

void InteractiveElementUpdatedMessage::_interactiveElementtreeFunc(Reader *input)
{
  this->interactiveElement = QSharedPointer<InteractiveElement>(new InteractiveElement() );
  this->interactiveElement->deserializeAsync(this->_interactiveElementtree);
}

InteractiveElementUpdatedMessage::InteractiveElementUpdatedMessage()
{
  m_type = MessageEnum::INTERACTIVEELEMENTUPDATEDMESSAGE;
}

