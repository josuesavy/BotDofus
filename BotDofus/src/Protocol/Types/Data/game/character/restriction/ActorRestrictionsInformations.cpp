#include "ActorRestrictionsInformations.h"

void ActorRestrictionsInformations::serialize(Writer *output)
{
  this->serializeAs_ActorRestrictionsInformations(output);
}

void ActorRestrictionsInformations::serializeAs_ActorRestrictionsInformations(Writer *output)
{
  uint _box0 = 0;
  _box0 = BooleanByteWrapper::setFlag(_box0, 0, this->cantBeAggressed);
  _box0 = BooleanByteWrapper::setFlag(_box0, 1, this->cantBeChallenged);
  _box0 = BooleanByteWrapper::setFlag(_box0, 2, this->cantTrade);
  _box0 = BooleanByteWrapper::setFlag(_box0, 3, this->cantBeAttackedByMutant);
  _box0 = BooleanByteWrapper::setFlag(_box0, 4, this->cantRun);
  _box0 = BooleanByteWrapper::setFlag(_box0, 5, this->forceSlowWalk);
  _box0 = BooleanByteWrapper::setFlag(_box0, 6, this->cantMinimize);
  _box0 = BooleanByteWrapper::setFlag(_box0, 7, this->cantMove);
  output->writeByte(_box0);
  uint _box1 = 0;
  _box1 = BooleanByteWrapper::setFlag(_box1, 0, this->cantAggress);
  _box1 = BooleanByteWrapper::setFlag(_box1, 1, this->cantChallenge);
  _box1 = BooleanByteWrapper::setFlag(_box1, 2, this->cantExchange);
  _box1 = BooleanByteWrapper::setFlag(_box1, 3, this->cantAttack);
  _box1 = BooleanByteWrapper::setFlag(_box1, 4, this->cantChat);
  _box1 = BooleanByteWrapper::setFlag(_box1, 5, this->cantBeMerchant);
  _box1 = BooleanByteWrapper::setFlag(_box1, 6, this->cantUseObject);
  _box1 = BooleanByteWrapper::setFlag(_box1, 7, this->cantUseTaxCollector);
  output->writeByte(_box1);
  uint _box2 = 0;
  _box2 = BooleanByteWrapper::setFlag(_box2, 0, this->cantUseInteractive);
  _box2 = BooleanByteWrapper::setFlag(_box2, 1, this->cantSpeakToNPC);
  _box2 = BooleanByteWrapper::setFlag(_box2, 2, this->cantChangeZone);
  _box2 = BooleanByteWrapper::setFlag(_box2, 3, this->cantAttackMonster);
  output->writeByte(_box2);
}

void ActorRestrictionsInformations::deserialize(Reader *input)
{
  this->deserializeAs_ActorRestrictionsInformations(input);
}

void ActorRestrictionsInformations::deserializeAs_ActorRestrictionsInformations(Reader *input)
{
  this->deserializeByteBoxes(input);
}

void ActorRestrictionsInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ActorRestrictionsInformations(tree);
}

void ActorRestrictionsInformations::deserializeAsyncAs_ActorRestrictionsInformations(FuncTree tree)
{
  tree.addChild(std::bind(&ActorRestrictionsInformations::deserializeByteBoxes, this, std::placeholders::_1));
}

void ActorRestrictionsInformations::deserializeByteBoxes(Reader *input)
{
  uint _box0 = input->readByte();
  this->cantBeAggressed = BooleanByteWrapper::getFlag(_box0, 0);
  this->cantBeChallenged = BooleanByteWrapper::getFlag(_box0, 1);
  this->cantTrade = BooleanByteWrapper::getFlag(_box0, 2);
  this->cantBeAttackedByMutant = BooleanByteWrapper::getFlag(_box0, 3);
  this->cantRun = BooleanByteWrapper::getFlag(_box0, 4);
  this->forceSlowWalk = BooleanByteWrapper::getFlag(_box0, 5);
  this->cantMinimize = BooleanByteWrapper::getFlag(_box0, 6);
  this->cantMove = BooleanByteWrapper::getFlag(_box0, 7);
  uint _box1 = input->readByte();
  this->cantAggress = BooleanByteWrapper::getFlag(_box1, 0);
  this->cantChallenge = BooleanByteWrapper::getFlag(_box1, 1);
  this->cantExchange = BooleanByteWrapper::getFlag(_box1, 2);
  this->cantAttack = BooleanByteWrapper::getFlag(_box1, 3);
  this->cantChat = BooleanByteWrapper::getFlag(_box1, 4);
  this->cantBeMerchant = BooleanByteWrapper::getFlag(_box1, 5);
  this->cantUseObject = BooleanByteWrapper::getFlag(_box1, 6);
  this->cantUseTaxCollector = BooleanByteWrapper::getFlag(_box1, 7);
  uint _box2 = input->readByte();
  this->cantUseInteractive = BooleanByteWrapper::getFlag(_box2, 0);
  this->cantSpeakToNPC = BooleanByteWrapper::getFlag(_box2, 1);
  this->cantChangeZone = BooleanByteWrapper::getFlag(_box2, 2);
  this->cantAttackMonster = BooleanByteWrapper::getFlag(_box2, 3);
}

ActorRestrictionsInformations::ActorRestrictionsInformations()
{
  m_types<<ClassEnum::ACTORRESTRICTIONSINFORMATIONS;
}

bool ActorRestrictionsInformations::operator==(const ActorRestrictionsInformations &compared)
{
  if(cantBeAggressed == compared.cantBeAggressed)
  if(cantBeChallenged == compared.cantBeChallenged)
  if(cantTrade == compared.cantTrade)
  if(cantBeAttackedByMutant == compared.cantBeAttackedByMutant)
  if(cantRun == compared.cantRun)
  if(forceSlowWalk == compared.forceSlowWalk)
  if(cantMinimize == compared.cantMinimize)
  if(cantMove == compared.cantMove)
  if(cantAggress == compared.cantAggress)
  if(cantChallenge == compared.cantChallenge)
  if(cantExchange == compared.cantExchange)
  if(cantAttack == compared.cantAttack)
  if(cantChat == compared.cantChat)
  if(cantBeMerchant == compared.cantBeMerchant)
  if(cantUseObject == compared.cantUseObject)
  if(cantUseTaxCollector == compared.cantUseTaxCollector)
  if(cantUseInteractive == compared.cantUseInteractive)
  if(cantSpeakToNPC == compared.cantSpeakToNPC)
  if(cantChangeZone == compared.cantChangeZone)
  if(cantAttackMonster == compared.cantAttackMonster)
  return true;
  
  return false;
}

