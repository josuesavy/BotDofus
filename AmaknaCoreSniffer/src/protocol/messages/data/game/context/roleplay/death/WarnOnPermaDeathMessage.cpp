#include "WarnOnPermaDeathMessage.h"

void WarnOnPermaDeathMessage::serialize(Writer *output)
{
  this->serializeAs_WarnOnPermaDeathMessage(output);
}

void WarnOnPermaDeathMessage::serializeAs_WarnOnPermaDeathMessage(Writer *output)
{
  output->writeBool(this->enable);
}

void WarnOnPermaDeathMessage::deserialize(Reader *input)
{
  this->deserializeAs_WarnOnPermaDeathMessage(input);
}

void WarnOnPermaDeathMessage::deserializeAs_WarnOnPermaDeathMessage(Reader *input)
{
  this->_enableFunc(input);
}

void WarnOnPermaDeathMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_WarnOnPermaDeathMessage(tree);
}

void WarnOnPermaDeathMessage::deserializeAsyncAs_WarnOnPermaDeathMessage(FuncTree tree)
{
  tree.addChild(std::bind(&WarnOnPermaDeathMessage::_enableFunc, this, std::placeholders::_1));
}

void WarnOnPermaDeathMessage::_enableFunc(Reader *input)
{
  this->enable = input->readBool();
}

WarnOnPermaDeathMessage::WarnOnPermaDeathMessage()
{
  m_type = MessageEnum::WARNONPERMADEATHMESSAGE;
}

