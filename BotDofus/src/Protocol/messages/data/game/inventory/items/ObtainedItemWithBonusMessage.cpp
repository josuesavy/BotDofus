#include "ObtainedItemWithBonusMessage.h"

void ObtainedItemWithBonusMessage::serialize(Writer *output)
{
  this->serializeAs_ObtainedItemWithBonusMessage(output);
}

void ObtainedItemWithBonusMessage::serializeAs_ObtainedItemWithBonusMessage(Writer *output)
{
  ObtainedItemMessage::serializeAs_ObtainedItemMessage(output);
  if(this->bonusQuantity < 0)
  {
    qDebug()<<"ERREUR - ObtainedItemWithBonusMessage -"<<"Forbidden value (" << this->bonusQuantity << ") on element bonusQuantity.";
  }
  output->writeVarInt((int)this->bonusQuantity);
}

void ObtainedItemWithBonusMessage::deserialize(Reader *input)
{
  this->deserializeAs_ObtainedItemWithBonusMessage(input);
}

void ObtainedItemWithBonusMessage::deserializeAs_ObtainedItemWithBonusMessage(Reader *input)
{
  ObtainedItemMessage::deserialize(input);
  this->_bonusQuantityFunc(input);
}

void ObtainedItemWithBonusMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ObtainedItemWithBonusMessage(tree);
}

void ObtainedItemWithBonusMessage::deserializeAsyncAs_ObtainedItemWithBonusMessage(FuncTree tree)
{
  ObtainedItemMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&ObtainedItemWithBonusMessage::_bonusQuantityFunc, this, std::placeholders::_1));
}

void ObtainedItemWithBonusMessage::_bonusQuantityFunc(Reader *input)
{
  this->bonusQuantity = input->readVarUhInt();
  if(this->bonusQuantity < 0)
  {
    qDebug()<<"ERREUR - ObtainedItemWithBonusMessage -"<<"Forbidden value (" << this->bonusQuantity << ") on element of ObtainedItemWithBonusMessage.bonusQuantity.";
  }
}

ObtainedItemWithBonusMessage::ObtainedItemWithBonusMessage()
{
  m_type = MessageEnum::OBTAINEDITEMWITHBONUSMESSAGE;
}

