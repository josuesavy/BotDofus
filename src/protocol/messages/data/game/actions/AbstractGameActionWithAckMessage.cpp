#include "AbstractGameActionWithAckMessage.h"

void AbstractGameActionWithAckMessage::serialize(Writer *output)
{
  this->serializeAs_AbstractGameActionWithAckMessage(output);
}

void AbstractGameActionWithAckMessage::serializeAs_AbstractGameActionWithAckMessage(Writer *output)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(output);
  output->writeShort((short)this->waitAckId);
}

void AbstractGameActionWithAckMessage::deserialize(Reader *input)
{
  this->deserializeAs_AbstractGameActionWithAckMessage(input);
}

void AbstractGameActionWithAckMessage::deserializeAs_AbstractGameActionWithAckMessage(Reader *input)
{
  AbstractGameActionMessage::deserialize(input);
  this->_waitAckIdFunc(input);
}

void AbstractGameActionWithAckMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AbstractGameActionWithAckMessage(tree);
}

void AbstractGameActionWithAckMessage::deserializeAsyncAs_AbstractGameActionWithAckMessage(FuncTree tree)
{
  AbstractGameActionMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&AbstractGameActionWithAckMessage::_waitAckIdFunc, this, std::placeholders::_1));
}

void AbstractGameActionWithAckMessage::_waitAckIdFunc(Reader *input)
{
  this->waitAckId = input->readShort();
}

AbstractGameActionWithAckMessage::AbstractGameActionWithAckMessage()
{
  m_type = MessageEnum::ABSTRACTGAMEACTIONWITHACKMESSAGE;
}

