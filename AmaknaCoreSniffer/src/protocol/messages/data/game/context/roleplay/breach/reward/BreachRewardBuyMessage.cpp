#include "BreachRewardBuyMessage.h"

void BreachRewardBuyMessage::serialize(Writer *output)
{
  this->serializeAs_BreachRewardBuyMessage(output);
}

void BreachRewardBuyMessage::serializeAs_BreachRewardBuyMessage(Writer *output)
{
  if(this->id < 0)
  {
    qDebug()<<"ERREUR - BreachRewardBuyMessage -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  output->writeVarInt((int)this->id);
}

void BreachRewardBuyMessage::deserialize(Reader *input)
{
  this->deserializeAs_BreachRewardBuyMessage(input);
}

void BreachRewardBuyMessage::deserializeAs_BreachRewardBuyMessage(Reader *input)
{
  this->_idFunc(input);
}

void BreachRewardBuyMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_BreachRewardBuyMessage(tree);
}

void BreachRewardBuyMessage::deserializeAsyncAs_BreachRewardBuyMessage(FuncTree tree)
{
  tree.addChild(std::bind(&BreachRewardBuyMessage::_idFunc, this, std::placeholders::_1));
}

void BreachRewardBuyMessage::_idFunc(Reader *input)
{
  this->id = input->readVarUhInt();
  if(this->id < 0)
  {
    qDebug()<<"ERREUR - BreachRewardBuyMessage -"<<"Forbidden value (" << this->id << ") on element of BreachRewardBuyMessage.id.";
  }
}

BreachRewardBuyMessage::BreachRewardBuyMessage()
{
  m_type = MessageEnum::BREACHREWARDBUYMESSAGE;
}

