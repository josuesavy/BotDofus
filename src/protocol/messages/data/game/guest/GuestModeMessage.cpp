#include "GuestModeMessage.h"

void GuestModeMessage::serialize(Writer *output)
{
  this->serializeAs_GuestModeMessage(output);
}

void GuestModeMessage::serializeAs_GuestModeMessage(Writer *output)
{
  output->writeBool(this->active);
}

void GuestModeMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuestModeMessage(input);
}

void GuestModeMessage::deserializeAs_GuestModeMessage(Reader *input)
{
  this->_activeFunc(input);
}

void GuestModeMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuestModeMessage(tree);
}

void GuestModeMessage::deserializeAsyncAs_GuestModeMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GuestModeMessage::_activeFunc, this, std::placeholders::_1));
}

void GuestModeMessage::_activeFunc(Reader *input)
{
  this->active = input->readBool();
}

GuestModeMessage::GuestModeMessage()
{
  m_type = MessageEnum::GUESTMODEMESSAGE;
}

