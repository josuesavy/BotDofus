#include "BreachGameFightEndMessage.h"

void BreachGameFightEndMessage::serialize(Writer *output)
{
  this->serializeAs_BreachGameFightEndMessage(output);
}

void BreachGameFightEndMessage::serializeAs_BreachGameFightEndMessage(Writer *output)
{
  GameFightEndMessage::serializeAs_GameFightEndMessage(output);
  output->writeInt((int)this->budget);
}

void BreachGameFightEndMessage::deserialize(Reader *input)
{
  this->deserializeAs_BreachGameFightEndMessage(input);
}

void BreachGameFightEndMessage::deserializeAs_BreachGameFightEndMessage(Reader *input)
{
  GameFightEndMessage::deserialize(input);
  this->_budgetFunc(input);
}

void BreachGameFightEndMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_BreachGameFightEndMessage(tree);
}

void BreachGameFightEndMessage::deserializeAsyncAs_BreachGameFightEndMessage(FuncTree tree)
{
  GameFightEndMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&BreachGameFightEndMessage::_budgetFunc, this, std::placeholders::_1));
}

void BreachGameFightEndMessage::_budgetFunc(Reader *input)
{
  this->budget = input->readInt();
}

BreachGameFightEndMessage::BreachGameFightEndMessage()
{
  m_type = MessageEnum::BREACHGAMEFIGHTENDMESSAGE;
}

