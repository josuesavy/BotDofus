#include "StatedElementUpdatedMessage.h"

void StatedElementUpdatedMessage::serialize(Writer *output)
{
  this->serializeAs_StatedElementUpdatedMessage(output);
}

void StatedElementUpdatedMessage::serializeAs_StatedElementUpdatedMessage(Writer *output)
{
  this->statedElement.serializeAs_StatedElement(output);
}

void StatedElementUpdatedMessage::deserialize(Reader *input)
{
  this->deserializeAs_StatedElementUpdatedMessage(input);
}

void StatedElementUpdatedMessage::deserializeAs_StatedElementUpdatedMessage(Reader *input)
{
  this->statedElement = StatedElement();
  this->statedElement.deserialize(input);
}

void StatedElementUpdatedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_StatedElementUpdatedMessage(tree);
}

void StatedElementUpdatedMessage::deserializeAsyncAs_StatedElementUpdatedMessage(FuncTree tree)
{
  this->_statedElementtree = tree.addChild(std::bind(&StatedElementUpdatedMessage::_statedElementtreeFunc, this, std::placeholders::_1));
}

void StatedElementUpdatedMessage::_statedElementtreeFunc(Reader *input)
{
  this->statedElement = StatedElement();
  this->statedElement.deserializeAsync(this->_statedElementtree);
}

StatedElementUpdatedMessage::StatedElementUpdatedMessage()
{
  m_type = MessageEnum::STATEDELEMENTUPDATEDMESSAGE;
}

