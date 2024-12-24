#include "BreachRewardBoughtMessage.h"

void BreachRewardBoughtMessage::serialize(Writer *output)
{
  this->serializeAs_BreachRewardBoughtMessage(output);
}

void BreachRewardBoughtMessage::serializeAs_BreachRewardBoughtMessage(Writer *output)
{
  if(this->id < 0)
  {
    qDebug()<<"ERREUR - BreachRewardBoughtMessage -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  output->writeVarInt((int)this->id);
  output->writeBool(this->bought);
}

void BreachRewardBoughtMessage::deserialize(Reader *input)
{
  this->deserializeAs_BreachRewardBoughtMessage(input);
}

void BreachRewardBoughtMessage::deserializeAs_BreachRewardBoughtMessage(Reader *input)
{
  this->_idFunc(input);
  this->_boughtFunc(input);
}

void BreachRewardBoughtMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_BreachRewardBoughtMessage(tree);
}

void BreachRewardBoughtMessage::deserializeAsyncAs_BreachRewardBoughtMessage(FuncTree tree)
{
  tree.addChild(std::bind(&BreachRewardBoughtMessage::_idFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&BreachRewardBoughtMessage::_boughtFunc, this, std::placeholders::_1));
}

void BreachRewardBoughtMessage::_idFunc(Reader *input)
{
  this->id = input->readVarUhInt();
  if(this->id < 0)
  {
    qDebug()<<"ERREUR - BreachRewardBoughtMessage -"<<"Forbidden value (" << this->id << ") on element of BreachRewardBoughtMessage.id.";
  }
}

void BreachRewardBoughtMessage::_boughtFunc(Reader *input)
{
  this->bought = input->readBool();
}

BreachRewardBoughtMessage::BreachRewardBoughtMessage()
{
  m_type = MessageEnum::BREACHREWARDBOUGHTMESSAGE;
}

