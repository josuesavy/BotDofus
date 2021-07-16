#include "UpdateSpellModifierMessage.h"

void UpdateSpellModifierMessage::serialize(Writer *output)
{
  this->serializeAs_UpdateSpellModifierMessage(output);
}

void UpdateSpellModifierMessage::serializeAs_UpdateSpellModifierMessage(Writer *output)
{
  if(this->actorId < -9.007199254740992E15 || this->actorId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - UpdateSpellModifierMessage -"<<"Forbidden value (" << this->actorId << ") on element actorId.";
  }
  output->writeDouble(this->actorId);
  this->spellModifier->serializeAs_CharacterSpellModification(output);
}

void UpdateSpellModifierMessage::deserialize(Reader *input)
{
  this->deserializeAs_UpdateSpellModifierMessage(input);
}

void UpdateSpellModifierMessage::deserializeAs_UpdateSpellModifierMessage(Reader *input)
{
  this->_actorIdFunc(input);
  this->spellModifier = QSharedPointer<CharacterSpellModification>(new CharacterSpellModification() );
  this->spellModifier->deserialize(input);
}

void UpdateSpellModifierMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_UpdateSpellModifierMessage(tree);
}

void UpdateSpellModifierMessage::deserializeAsyncAs_UpdateSpellModifierMessage(FuncTree tree)
{
  tree.addChild(std::bind(&UpdateSpellModifierMessage::_actorIdFunc, this, std::placeholders::_1));
  this->_spellModifiertree = tree.addChild(std::bind(&UpdateSpellModifierMessage::_spellModifiertreeFunc, this, std::placeholders::_1));
}

void UpdateSpellModifierMessage::_actorIdFunc(Reader *input)
{
  this->actorId = input->readDouble();
  if(this->actorId < -9.007199254740992E15 || this->actorId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - UpdateSpellModifierMessage -"<<"Forbidden value (" << this->actorId << ") on element of UpdateSpellModifierMessage.actorId.";
  }
}

void UpdateSpellModifierMessage::_spellModifiertreeFunc(Reader *input)
{
  this->spellModifier = QSharedPointer<CharacterSpellModification>(new CharacterSpellModification() );
  this->spellModifier->deserializeAsync(this->_spellModifiertree);
}

UpdateSpellModifierMessage::UpdateSpellModifierMessage()
{
  m_type = MessageEnum::UPDATESPELLMODIFIERMESSAGE;
}

