#include "LockableUseCodeMessage.h"

void LockableUseCodeMessage::serialize(Writer *output)
{
  this->serializeAs_LockableUseCodeMessage(output);
}

void LockableUseCodeMessage::serializeAs_LockableUseCodeMessage(Writer *output)
{
  output->writeUTF(this->code);
}

void LockableUseCodeMessage::deserialize(Reader *input)
{
  this->deserializeAs_LockableUseCodeMessage(input);
}

void LockableUseCodeMessage::deserializeAs_LockableUseCodeMessage(Reader *input)
{
  this->_codeFunc(input);
}

void LockableUseCodeMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_LockableUseCodeMessage(tree);
}

void LockableUseCodeMessage::deserializeAsyncAs_LockableUseCodeMessage(FuncTree tree)
{
  tree.addChild(std::bind(&LockableUseCodeMessage::_codeFunc, this, std::placeholders::_1));
}

void LockableUseCodeMessage::_codeFunc(Reader *input)
{
  this->code = input->readUTF();
}

LockableUseCodeMessage::LockableUseCodeMessage()
{
  m_type = MessageEnum::LOCKABLEUSECODEMESSAGE;
}

