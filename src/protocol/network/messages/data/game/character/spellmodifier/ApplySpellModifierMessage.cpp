#include "ApplySpellModifierMessage.h"

void ApplySpellModifierMessage::serialize(Writer *output)
{
  this->serializeAs_ApplySpellModifierMessage(output);
}

void ApplySpellModifierMessage::serializeAs_ApplySpellModifierMessage(Writer *output)
{
  if(this->actorId < -9007199254740992 || this->actorId > 9007199254740992)
  {
    qDebug()<<"ERREUR - ApplySpellModifierMessage -"<<"Forbidden value (" << this->actorId << ") on element actorId.";
  }
  output->writeDouble(this->actorId);
  this->modifier.serializeAs_SpellModifierMessage(output);
}

void ApplySpellModifierMessage::deserialize(Reader *input)
{
  this->deserializeAs_ApplySpellModifierMessage(input);
}

void ApplySpellModifierMessage::deserializeAs_ApplySpellModifierMessage(Reader *input)
{
  this->_actorIdFunc(input);
  this->modifier = SpellModifierMessage();
  this->modifier.deserialize(input);
}

void ApplySpellModifierMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ApplySpellModifierMessage(tree);
}

void ApplySpellModifierMessage::deserializeAsyncAs_ApplySpellModifierMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ApplySpellModifierMessage::_actorIdFunc, this, std::placeholders::_1));
  this->_modifiertree = tree.addChild(std::bind(&ApplySpellModifierMessage::_modifiertreeFunc, this, std::placeholders::_1));
}

void ApplySpellModifierMessage::_actorIdFunc(Reader *input)
{
  this->actorId = input->readDouble();
  if(this->actorId < -9007199254740992 || this->actorId > 9007199254740992)
  {
    qDebug()<<"ERREUR - ApplySpellModifierMessage -"<<"Forbidden value (" << this->actorId << ") on element of ApplySpellModifierMessage.actorId.";
  }
}

void ApplySpellModifierMessage::_modifiertreeFunc(Reader *input)
{
  this->modifier = SpellModifierMessage();
  this->modifier.deserializeAsync(this->_modifiertree);
}

ApplySpellModifierMessage::ApplySpellModifierMessage()
{
  m_type = MessageEnum::APPLYSPELLMODIFIERMESSAGE;
}

