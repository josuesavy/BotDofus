#include "LockableChangeCodeMessage.h"

void LockableChangeCodeMessage::serialize(Writer *output)
{
  this->serializeAs_LockableChangeCodeMessage(output);
}

void LockableChangeCodeMessage::serializeAs_LockableChangeCodeMessage(Writer *output)
{
  output->writeUTF(this->code);
}

void LockableChangeCodeMessage::deserialize(Reader *input)
{
  this->deserializeAs_LockableChangeCodeMessage(input);
}

void LockableChangeCodeMessage::deserializeAs_LockableChangeCodeMessage(Reader *input)
{
  this->_codeFunc(input);
}

void LockableChangeCodeMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_LockableChangeCodeMessage(tree);
}

void LockableChangeCodeMessage::deserializeAsyncAs_LockableChangeCodeMessage(FuncTree tree)
{
  tree.addChild(std::bind(&LockableChangeCodeMessage::_codeFunc, this, std::placeholders::_1));
}

void LockableChangeCodeMessage::_codeFunc(Reader *input)
{
  this->code = input->readUTF();
}

LockableChangeCodeMessage::LockableChangeCodeMessage()
{
  m_type = MessageEnum::LOCKABLECHANGECODEMESSAGE;
}

