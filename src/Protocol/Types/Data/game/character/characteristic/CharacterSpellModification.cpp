#include "CharacterSpellModification.h"

void CharacterSpellModification::serialize(Writer *output)
{
  this->serializeAs_CharacterSpellModification(output);
}

void CharacterSpellModification::serializeAs_CharacterSpellModification(Writer *output)
{
  output->writeByte(this->modificationType);
  if(this->spellId < 0)
  {
    qDebug()<<"ERREUR - CharacterSpellModification -"<<"Forbidden value (" << this->spellId << ") on element spellId.";
  }
  output->writeVarShort((int)this->spellId);
  this->value.serializeAs_CharacterBaseCharacteristic(output);
}

void CharacterSpellModification::deserialize(Reader *input)
{
  this->deserializeAs_CharacterSpellModification(input);
}

void CharacterSpellModification::deserializeAs_CharacterSpellModification(Reader *input)
{
  this->_modificationTypeFunc(input);
  this->_spellIdFunc(input);
  this->value = CharacterBaseCharacteristic();
  this->value.deserialize(input);
}

void CharacterSpellModification::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_CharacterSpellModification(tree);
}

void CharacterSpellModification::deserializeAsyncAs_CharacterSpellModification(FuncTree tree)
{
  tree.addChild(std::bind(&CharacterSpellModification::_modificationTypeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&CharacterSpellModification::_spellIdFunc, this, std::placeholders::_1));
  this->_valuetree = tree.addChild(std::bind(&CharacterSpellModification::_valuetreeFunc, this, std::placeholders::_1));
}

void CharacterSpellModification::_modificationTypeFunc(Reader *input)
{
  this->modificationType = input->readByte();
  if(this->modificationType < 0)
  {
    qDebug()<<"ERREUR - CharacterSpellModification -"<<"Forbidden value (" << this->modificationType << ") on element of CharacterSpellModification.modificationType.";
  }
}

void CharacterSpellModification::_spellIdFunc(Reader *input)
{
  this->spellId = input->readVarUhShort();
  if(this->spellId < 0)
  {
    qDebug()<<"ERREUR - CharacterSpellModification -"<<"Forbidden value (" << this->spellId << ") on element of CharacterSpellModification.spellId.";
  }
}

void CharacterSpellModification::_valuetreeFunc(Reader *input)
{
  this->value = CharacterBaseCharacteristic();
  this->value.deserializeAsync(this->_valuetree);
}

CharacterSpellModification::CharacterSpellModification()
{
  m_types<<ClassEnum::CHARACTERSPELLMODIFICATION;
}

bool CharacterSpellModification::operator==(const CharacterSpellModification &compared)
{
  if(modificationType == compared.modificationType)
  if(spellId == compared.spellId)
  if(value == compared.value)
  if(_valuetree == compared._valuetree)
  return true;
  
  return false;
}

