#include "BreachSavedMessage.h"

void BreachSavedMessage::serialize(Writer *output)
{
  this->serializeAs_BreachSavedMessage(output);
}

void BreachSavedMessage::serializeAs_BreachSavedMessage(Writer *output)
{
  output->writeBool(this->saved);
}

void BreachSavedMessage::deserialize(Reader *input)
{
  this->deserializeAs_BreachSavedMessage(input);
}

void BreachSavedMessage::deserializeAs_BreachSavedMessage(Reader *input)
{
  this->_savedFunc(input);
}

void BreachSavedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_BreachSavedMessage(tree);
}

void BreachSavedMessage::deserializeAsyncAs_BreachSavedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&BreachSavedMessage::_savedFunc, this, std::placeholders::_1));
}

void BreachSavedMessage::_savedFunc(Reader *input)
{
  this->saved = input->readBool();
}

BreachSavedMessage::BreachSavedMessage()
{
  m_type = MessageEnum::BREACHSAVEDMESSAGE;
}

