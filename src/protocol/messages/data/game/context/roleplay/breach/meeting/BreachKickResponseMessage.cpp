#include "BreachKickResponseMessage.h"

void BreachKickResponseMessage::serialize(Writer *output)
{
  this->serializeAs_BreachKickResponseMessage(output);
}

void BreachKickResponseMessage::serializeAs_BreachKickResponseMessage(Writer *output)
{
  this->target.serializeAs_CharacterMinimalInformations(output);
  output->writeBool(this->kicked);
}

void BreachKickResponseMessage::deserialize(Reader *input)
{
  this->deserializeAs_BreachKickResponseMessage(input);
}

void BreachKickResponseMessage::deserializeAs_BreachKickResponseMessage(Reader *input)
{
  this->target = CharacterMinimalInformations();
  this->target.deserialize(input);
  this->_kickedFunc(input);
}

void BreachKickResponseMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_BreachKickResponseMessage(tree);
}

void BreachKickResponseMessage::deserializeAsyncAs_BreachKickResponseMessage(FuncTree tree)
{
  this->_targettree = tree.addChild(std::bind(&BreachKickResponseMessage::_targettreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&BreachKickResponseMessage::_kickedFunc, this, std::placeholders::_1));
}

void BreachKickResponseMessage::_targettreeFunc(Reader *input)
{
  this->target = CharacterMinimalInformations();
  this->target.deserializeAsync(this->_targettree);
}

void BreachKickResponseMessage::_kickedFunc(Reader *input)
{
  this->kicked = input->readBool();
}

BreachKickResponseMessage::BreachKickResponseMessage()
{
  m_type = MessageEnum::BREACHKICKRESPONSEMESSAGE;
}

