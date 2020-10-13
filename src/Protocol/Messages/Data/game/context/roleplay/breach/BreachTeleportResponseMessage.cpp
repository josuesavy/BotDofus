#include "BreachTeleportResponseMessage.h"

void BreachTeleportResponseMessage::serialize(Writer *output)
{
  this->serializeAs_BreachTeleportResponseMessage(output);
}

void BreachTeleportResponseMessage::serializeAs_BreachTeleportResponseMessage(Writer *output)
{
  output->writeBool(this->teleported);
}

void BreachTeleportResponseMessage::deserialize(Reader *input)
{
  this->deserializeAs_BreachTeleportResponseMessage(input);
}

void BreachTeleportResponseMessage::deserializeAs_BreachTeleportResponseMessage(Reader *input)
{
  this->_teleportedFunc(input);
}

void BreachTeleportResponseMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_BreachTeleportResponseMessage(tree);
}

void BreachTeleportResponseMessage::deserializeAsyncAs_BreachTeleportResponseMessage(FuncTree tree)
{
  tree.addChild(std::bind(&BreachTeleportResponseMessage::_teleportedFunc, this, std::placeholders::_1));
}

void BreachTeleportResponseMessage::_teleportedFunc(Reader *input)
{
  this->teleported = input->readBool();
}

BreachTeleportResponseMessage::BreachTeleportResponseMessage()
{
  m_type = MessageEnum::BREACHTELEPORTRESPONSEMESSAGE;
}

