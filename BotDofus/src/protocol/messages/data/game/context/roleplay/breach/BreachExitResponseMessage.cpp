#include "BreachExitResponseMessage.h"

void BreachExitResponseMessage::serialize(Writer *output)
{
  this->serializeAs_BreachExitResponseMessage(output);
}

void BreachExitResponseMessage::serializeAs_BreachExitResponseMessage(Writer *output)
{
  output->writeBool(this->exited);
}

void BreachExitResponseMessage::deserialize(Reader *input)
{
  this->deserializeAs_BreachExitResponseMessage(input);
}

void BreachExitResponseMessage::deserializeAs_BreachExitResponseMessage(Reader *input)
{
  this->_exitedFunc(input);
}

void BreachExitResponseMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_BreachExitResponseMessage(tree);
}

void BreachExitResponseMessage::deserializeAsyncAs_BreachExitResponseMessage(FuncTree tree)
{
  tree.addChild(std::bind(&BreachExitResponseMessage::_exitedFunc, this, std::placeholders::_1));
}

void BreachExitResponseMessage::_exitedFunc(Reader *input)
{
  this->exited = input->readBool();
}

BreachExitResponseMessage::BreachExitResponseMessage()
{
  m_type = MessageEnum::BREACHEXITRESPONSEMESSAGE;
}

