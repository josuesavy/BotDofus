#include "FightDispellableEffectExtendedInformations.h"

void FightDispellableEffectExtendedInformations::serialize(Writer *output)
{
  this->serializeAs_FightDispellableEffectExtendedInformations(output);
}

void FightDispellableEffectExtendedInformations::serializeAs_FightDispellableEffectExtendedInformations(Writer *output)
{
  if(this->actionId < 0)
  {
    qDebug()<<"ERREUR - FightDispellableEffectExtendedInformations -"<<"Forbidden value (" << this->actionId << ") on element actionId.";
  }
  output->writeVarShort((int)this->actionId);
  if(this->sourceId < -9007199254740992 || this->sourceId > 9007199254740992)
  {
    qDebug()<<"ERREUR - FightDispellableEffectExtendedInformations -"<<"Forbidden value (" << this->sourceId << ") on element sourceId.";
  }
  output->writeDouble(this->sourceId);
  output->writeShort((short)this->effect->getTypes().last());
  this->effect->serialize(output);
}

void FightDispellableEffectExtendedInformations::deserialize(Reader *input)
{
  this->deserializeAs_FightDispellableEffectExtendedInformations(input);
}

void FightDispellableEffectExtendedInformations::deserializeAs_FightDispellableEffectExtendedInformations(Reader *input)
{
  this->_actionIdFunc(input);
  this->_sourceIdFunc(input);
  uint _id3 = uint(input->readUShort());
  this->effect = qSharedPointerCast<AbstractFightDispellableEffect>(ClassManagerSingleton::get()->getClass(_id3));
  this->effect->deserialize(input);
}

void FightDispellableEffectExtendedInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_FightDispellableEffectExtendedInformations(tree);
}

void FightDispellableEffectExtendedInformations::deserializeAsyncAs_FightDispellableEffectExtendedInformations(FuncTree tree)
{
  tree.addChild(std::bind(&FightDispellableEffectExtendedInformations::_actionIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&FightDispellableEffectExtendedInformations::_sourceIdFunc, this, std::placeholders::_1));
  this->_effecttree = tree.addChild(std::bind(&FightDispellableEffectExtendedInformations::_effecttreeFunc, this, std::placeholders::_1));
}

void FightDispellableEffectExtendedInformations::_actionIdFunc(Reader *input)
{
  this->actionId = input->readVarUhShort();
  if(this->actionId < 0)
  {
    qDebug()<<"ERREUR - FightDispellableEffectExtendedInformations -"<<"Forbidden value (" << this->actionId << ") on element of FightDispellableEffectExtendedInformations.actionId.";
  }
}

void FightDispellableEffectExtendedInformations::_sourceIdFunc(Reader *input)
{
  this->sourceId = input->readDouble();
  if(this->sourceId < -9007199254740992 || this->sourceId > 9007199254740992)
  {
    qDebug()<<"ERREUR - FightDispellableEffectExtendedInformations -"<<"Forbidden value (" << this->sourceId << ") on element of FightDispellableEffectExtendedInformations.sourceId.";
  }
}

void FightDispellableEffectExtendedInformations::_effecttreeFunc(Reader *input)
{
  uint _id = uint(input->readUShort());
  this->effect = qSharedPointerCast<AbstractFightDispellableEffect>(ClassManagerSingleton::get()->getClass(_id));
  this->effect->deserializeAsync(this->_effecttree);
}

FightDispellableEffectExtendedInformations::FightDispellableEffectExtendedInformations()
{
  m_types<<ClassEnum::FIGHTDISPELLABLEEFFECTEXTENDEDINFORMATIONS;
}

bool FightDispellableEffectExtendedInformations::operator==(const FightDispellableEffectExtendedInformations &compared)
{
  if(actionId == compared.actionId)
  if(sourceId == compared.sourceId)
  if(effect == compared.effect)
  if(_effecttree == compared._effecttree)
  return true;
  
  return false;
}

