#include "IgnoredDeleteResultMessage.h"

void IgnoredDeleteResultMessage::serialize(Writer *output)
{
  this->serializeAs_IgnoredDeleteResultMessage(output);
}

void IgnoredDeleteResultMessage::serializeAs_IgnoredDeleteResultMessage(Writer *output)
{
  uint _box0 = 0;
  _box0 = BooleanByteWrapper::setFlag(_box0, 0, this->success);
  _box0 = BooleanByteWrapper::setFlag(_box0, 1, this->session);
  output->writeByte(_box0);
  output->writeUTF(this->name);
}

void IgnoredDeleteResultMessage::deserialize(Reader *input)
{
  this->deserializeAs_IgnoredDeleteResultMessage(input);
}

void IgnoredDeleteResultMessage::deserializeAs_IgnoredDeleteResultMessage(Reader *input)
{
  this->deserializeByteBoxes(input);
  this->_nameFunc(input);
}

void IgnoredDeleteResultMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_IgnoredDeleteResultMessage(tree);
}

void IgnoredDeleteResultMessage::deserializeAsyncAs_IgnoredDeleteResultMessage(FuncTree tree)
{
  tree.addChild(std::bind(&IgnoredDeleteResultMessage::deserializeByteBoxes, this, std::placeholders::_1));
  tree.addChild(std::bind(&IgnoredDeleteResultMessage::_nameFunc, this, std::placeholders::_1));
}

void IgnoredDeleteResultMessage::deserializeByteBoxes(Reader *input)
{
  uint _box0 = input->readByte();
  this->success = BooleanByteWrapper::getFlag(_box0, 0);
  this->session = BooleanByteWrapper::getFlag(_box0, 1);
}

void IgnoredDeleteResultMessage::_nameFunc(Reader *input)
{
  this->name = input->readUTF();
}

IgnoredDeleteResultMessage::IgnoredDeleteResultMessage()
{
  m_type = MessageEnum::IGNOREDDELETERESULTMESSAGE;
}

