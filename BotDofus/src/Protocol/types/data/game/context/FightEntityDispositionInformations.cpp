#include "FightEntityDispositionInformations.h"

void FightEntityDispositionInformations::serialize(Writer *output)
{
  this->serializeAs_FightEntityDispositionInformations(output);
}

void FightEntityDispositionInformations::serializeAs_FightEntityDispositionInformations(Writer *output)
{
  EntityDispositionInformations::serializeAs_EntityDispositionInformations(output);
  if(this->carryingCharacterId < -9.007199254740992E15 || this->carryingCharacterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - FightEntityDispositionInformations -"<<"Forbidden value (" << this->carryingCharacterId << ") on element carryingCharacterId.";
  }
  output->writeDouble(this->carryingCharacterId);
}

void FightEntityDispositionInformations::deserialize(Reader *input)
{
  this->deserializeAs_FightEntityDispositionInformations(input);
}

void FightEntityDispositionInformations::deserializeAs_FightEntityDispositionInformations(Reader *input)
{
  EntityDispositionInformations::deserialize(input);
  this->_carryingCharacterIdFunc(input);
}

void FightEntityDispositionInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_FightEntityDispositionInformations(tree);
}

void FightEntityDispositionInformations::deserializeAsyncAs_FightEntityDispositionInformations(FuncTree tree)
{
  EntityDispositionInformations::deserializeAsync(tree);
  tree.addChild(std::bind(&FightEntityDispositionInformations::_carryingCharacterIdFunc, this, std::placeholders::_1));
}

void FightEntityDispositionInformations::_carryingCharacterIdFunc(Reader *input)
{
  this->carryingCharacterId = input->readDouble();
  if(this->carryingCharacterId < -9.007199254740992E15 || this->carryingCharacterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - FightEntityDispositionInformations -"<<"Forbidden value (" << this->carryingCharacterId << ") on element of FightEntityDispositionInformations.carryingCharacterId.";
  }
}

FightEntityDispositionInformations::FightEntityDispositionInformations()
{
  m_types<<ClassEnum::FIGHTENTITYDISPOSITIONINFORMATIONS;
}

bool FightEntityDispositionInformations::operator==(const FightEntityDispositionInformations &compared)
{
  if(carryingCharacterId == compared.carryingCharacterId)
  return true;
  
  return false;
}

