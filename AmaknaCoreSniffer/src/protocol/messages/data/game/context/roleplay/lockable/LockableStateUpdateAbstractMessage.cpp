#include "LockableStateUpdateAbstractMessage.h"

void LockableStateUpdateAbstractMessage::serialize(Writer *output)
{
  this->serializeAs_LockableStateUpdateAbstractMessage(output);
}

void LockableStateUpdateAbstractMessage::serializeAs_LockableStateUpdateAbstractMessage(Writer *output)
{
  output->writeBool(this->locked);
}

void LockableStateUpdateAbstractMessage::deserialize(Reader *input)
{
  this->deserializeAs_LockableStateUpdateAbstractMessage(input);
}

void LockableStateUpdateAbstractMessage::deserializeAs_LockableStateUpdateAbstractMessage(Reader *input)
{
  this->_lockedFunc(input);
}

void LockableStateUpdateAbstractMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_LockableStateUpdateAbstractMessage(tree);
}

void LockableStateUpdateAbstractMessage::deserializeAsyncAs_LockableStateUpdateAbstractMessage(FuncTree tree)
{
  tree.addChild(std::bind(&LockableStateUpdateAbstractMessage::_lockedFunc, this, std::placeholders::_1));
}

void LockableStateUpdateAbstractMessage::_lockedFunc(Reader *input)
{
  this->locked = input->readBool();
}

LockableStateUpdateAbstractMessage::LockableStateUpdateAbstractMessage()
{
  m_type = MessageEnum::LOCKABLESTATEUPDATEABSTRACTMESSAGE;
}

