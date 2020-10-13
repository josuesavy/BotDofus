#include "BreachEnterMessage.h"

void BreachEnterMessage::serialize(Writer *output)
{
  this->serializeAs_BreachEnterMessage(output);
}

void BreachEnterMessage::serializeAs_BreachEnterMessage(Writer *output)
{
  if(this->owner < 0 || this->owner > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - BreachEnterMessage -"<<"Forbidden value (" << this->owner << ") on element owner.";
  }
  output->writeVarLong((double)this->owner);
}

void BreachEnterMessage::deserialize(Reader *input)
{
  this->deserializeAs_BreachEnterMessage(input);
}

void BreachEnterMessage::deserializeAs_BreachEnterMessage(Reader *input)
{
  this->_ownerFunc(input);
}

void BreachEnterMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_BreachEnterMessage(tree);
}

void BreachEnterMessage::deserializeAsyncAs_BreachEnterMessage(FuncTree tree)
{
  tree.addChild(std::bind(&BreachEnterMessage::_ownerFunc, this, std::placeholders::_1));
}

void BreachEnterMessage::_ownerFunc(Reader *input)
{
  this->owner = input->readVarUhLong();
  if(this->owner < 0 || this->owner > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - BreachEnterMessage -"<<"Forbidden value (" << this->owner << ") on element of BreachEnterMessage.owner.";
  }
}

BreachEnterMessage::BreachEnterMessage()
{
  m_type = MessageEnum::BREACHENTERMESSAGE;
}

