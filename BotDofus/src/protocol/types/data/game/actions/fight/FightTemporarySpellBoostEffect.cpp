#include "FightTemporarySpellBoostEffect.h"

void FightTemporarySpellBoostEffect::serialize(Writer *output)
{
  this->serializeAs_FightTemporarySpellBoostEffect(output);
}

void FightTemporarySpellBoostEffect::serializeAs_FightTemporarySpellBoostEffect(Writer *output)
{
  FightTemporaryBoostEffect::serializeAs_FightTemporaryBoostEffect(output);
  if(this->boostedSpellId < 0)
  {
    qDebug()<<"ERREUR - FightTemporarySpellBoostEffect -"<<"Forbidden value (" << this->boostedSpellId << ") on element boostedSpellId.";
  }
  output->writeVarShort((int)this->boostedSpellId);
}

void FightTemporarySpellBoostEffect::deserialize(Reader *input)
{
  this->deserializeAs_FightTemporarySpellBoostEffect(input);
}

void FightTemporarySpellBoostEffect::deserializeAs_FightTemporarySpellBoostEffect(Reader *input)
{
  FightTemporaryBoostEffect::deserialize(input);
  this->_boostedSpellIdFunc(input);
}

void FightTemporarySpellBoostEffect::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_FightTemporarySpellBoostEffect(tree);
}

void FightTemporarySpellBoostEffect::deserializeAsyncAs_FightTemporarySpellBoostEffect(FuncTree tree)
{
  FightTemporaryBoostEffect::deserializeAsync(tree);
  tree.addChild(std::bind(&FightTemporarySpellBoostEffect::_boostedSpellIdFunc, this, std::placeholders::_1));
}

void FightTemporarySpellBoostEffect::_boostedSpellIdFunc(Reader *input)
{
  this->boostedSpellId = input->readVarUhShort();
  if(this->boostedSpellId < 0)
  {
    qDebug()<<"ERREUR - FightTemporarySpellBoostEffect -"<<"Forbidden value (" << this->boostedSpellId << ") on element of FightTemporarySpellBoostEffect.boostedSpellId.";
  }
}

FightTemporarySpellBoostEffect::FightTemporarySpellBoostEffect()
{
  m_types<<ClassEnum::FIGHTTEMPORARYSPELLBOOSTEFFECT;
}

bool FightTemporarySpellBoostEffect::operator==(const FightTemporarySpellBoostEffect &compared)
{
  if(boostedSpellId == compared.boostedSpellId)
  return true;
  
  return false;
}

