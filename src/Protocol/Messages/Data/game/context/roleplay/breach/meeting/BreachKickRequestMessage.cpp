#include "BreachKickRequestMessage.h"

void BreachKickRequestMessage::serialize(Writer *output)
{
  this->serializeAs_BreachKickRequestMessage(output);
}

void BreachKickRequestMessage::serializeAs_BreachKickRequestMessage(Writer *output)
{
  if(this->target < 0 || this->target > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - BreachKickRequestMessage -"<<"Forbidden value (" << this->target << ") on element target.";
  }
  output->writeVarLong((double)this->target);
}

void BreachKickRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_BreachKickRequestMessage(input);
}

void BreachKickRequestMessage::deserializeAs_BreachKickRequestMessage(Reader *input)
{
  this->_targetFunc(input);
}

void BreachKickRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_BreachKickRequestMessage(tree);
}

void BreachKickRequestMessage::deserializeAsyncAs_BreachKickRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&BreachKickRequestMessage::_targetFunc, this, std::placeholders::_1));
}

void BreachKickRequestMessage::_targetFunc(Reader *input)
{
  this->target = input->readVarUhLong();
  if(this->target < 0 || this->target > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - BreachKickRequestMessage -"<<"Forbidden value (" << this->target << ") on element of BreachKickRequestMessage.target.";
  }
}

BreachKickRequestMessage::BreachKickRequestMessage()
{
  m_type = MessageEnum::BREACHKICKREQUESTMESSAGE;
}

