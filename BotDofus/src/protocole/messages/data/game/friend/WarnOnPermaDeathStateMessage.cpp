#include "WarnOnPermaDeathStateMessage.h"

void WarnOnPermaDeathStateMessage::serialize(Writer *output)
{
  this->serializeAs_WarnOnPermaDeathStateMessage(output);
}

void WarnOnPermaDeathStateMessage::serializeAs_WarnOnPermaDeathStateMessage(Writer *output)
{
  output->writeBool(this->enable);
}

void WarnOnPermaDeathStateMessage::deserialize(Reader *input)
{
  this->deserializeAs_WarnOnPermaDeathStateMessage(input);
}

void WarnOnPermaDeathStateMessage::deserializeAs_WarnOnPermaDeathStateMessage(Reader *input)
{
  this->_enableFunc(input);
}

void WarnOnPermaDeathStateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_WarnOnPermaDeathStateMessage(tree);
}

void WarnOnPermaDeathStateMessage::deserializeAsyncAs_WarnOnPermaDeathStateMessage(FuncTree tree)
{
  tree.addChild(std::bind(&WarnOnPermaDeathStateMessage::_enableFunc, this, std::placeholders::_1));
}

void WarnOnPermaDeathStateMessage::_enableFunc(Reader *input)
{
  this->enable = input->readBool();
}

WarnOnPermaDeathStateMessage::WarnOnPermaDeathStateMessage()
{
  m_type = MessageEnum::WARNONPERMADEATHSTATEMESSAGE;
}

