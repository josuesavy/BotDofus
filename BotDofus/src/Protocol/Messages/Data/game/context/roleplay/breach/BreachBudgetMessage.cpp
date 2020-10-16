#include "BreachBudgetMessage.h"

void BreachBudgetMessage::serialize(Writer *output)
{
  this->serializeAs_BreachBudgetMessage(output);
}

void BreachBudgetMessage::serializeAs_BreachBudgetMessage(Writer *output)
{
  if(this->bugdet < 0)
  {
    qDebug()<<"ERREUR - BreachBudgetMessage -"<<"Forbidden value (" << this->bugdet << ") on element bugdet.";
  }
  output->writeVarInt((int)this->bugdet);
}

void BreachBudgetMessage::deserialize(Reader *input)
{
  this->deserializeAs_BreachBudgetMessage(input);
}

void BreachBudgetMessage::deserializeAs_BreachBudgetMessage(Reader *input)
{
  this->_bugdetFunc(input);
}

void BreachBudgetMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_BreachBudgetMessage(tree);
}

void BreachBudgetMessage::deserializeAsyncAs_BreachBudgetMessage(FuncTree tree)
{
  tree.addChild(std::bind(&BreachBudgetMessage::_bugdetFunc, this, std::placeholders::_1));
}

void BreachBudgetMessage::_bugdetFunc(Reader *input)
{
  this->bugdet = input->readVarUhInt();
  if(this->bugdet < 0)
  {
    qDebug()<<"ERREUR - BreachBudgetMessage -"<<"Forbidden value (" << this->bugdet << ") on element of BreachBudgetMessage.bugdet.";
  }
}

BreachBudgetMessage::BreachBudgetMessage()
{
  m_type = MessageEnum::BREACHBUDGETMESSAGE;
}

