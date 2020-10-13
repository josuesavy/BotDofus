#include "BreachBonusMessage.h"

void BreachBonusMessage::serialize(Writer *output)
{
  this->serializeAs_BreachBonusMessage(output);
}

void BreachBonusMessage::serializeAs_BreachBonusMessage(Writer *output)
{
  this->bonus->serializeAs_ObjectEffectInteger(output);
}

void BreachBonusMessage::deserialize(Reader *input)
{
  this->deserializeAs_BreachBonusMessage(input);
}

void BreachBonusMessage::deserializeAs_BreachBonusMessage(Reader *input)
{
  this->bonus = QSharedPointer<ObjectEffectInteger>(new ObjectEffectInteger() );
  this->bonus->deserialize(input);
}

void BreachBonusMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_BreachBonusMessage(tree);
}

void BreachBonusMessage::deserializeAsyncAs_BreachBonusMessage(FuncTree tree)
{
  this->_bonustree = tree.addChild(std::bind(&BreachBonusMessage::_bonustreeFunc, this, std::placeholders::_1));
}

void BreachBonusMessage::_bonustreeFunc(Reader *input)
{
  this->bonus = QSharedPointer<ObjectEffectInteger>(new ObjectEffectInteger() );
  this->bonus->deserializeAsync(this->_bonustree);
}

BreachBonusMessage::BreachBonusMessage()
{
  m_type = MessageEnum::BREACHBONUSMESSAGE;
}

