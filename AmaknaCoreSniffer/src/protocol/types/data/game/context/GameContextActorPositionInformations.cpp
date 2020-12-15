#include "GameContextActorPositionInformations.h"

void GameContextActorPositionInformations::serialize(Writer *output)
{
  this->serializeAs_GameContextActorPositionInformations(output);
}

void GameContextActorPositionInformations::serializeAs_GameContextActorPositionInformations(Writer *output)
{
  if(this->contextualId < -9.007199254740992E15 || this->contextualId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameContextActorPositionInformations -"<<"Forbidden value (" << this->contextualId << ") on element contextualId.";
  }
  output->writeDouble(this->contextualId);
  output->writeShort((short)this->disposition->getTypes().last());
  this->disposition->serialize(output);
}

void GameContextActorPositionInformations::deserialize(Reader *input)
{
  this->deserializeAs_GameContextActorPositionInformations(input);
}

void GameContextActorPositionInformations::deserializeAs_GameContextActorPositionInformations(Reader *input)
{
  this->_contextualIdFunc(input);
  uint _id2 = input->readUShort();
  this->disposition = qSharedPointerCast<EntityDispositionInformations>(ClassManagerSingleton::get()->getClass(_id2));
  this->disposition->deserialize(input);
}

void GameContextActorPositionInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameContextActorPositionInformations(tree);
}

void GameContextActorPositionInformations::deserializeAsyncAs_GameContextActorPositionInformations(FuncTree tree)
{
  tree.addChild(std::bind(&GameContextActorPositionInformations::_contextualIdFunc, this, std::placeholders::_1));
  this->_dispositiontree = tree.addChild(std::bind(&GameContextActorPositionInformations::_dispositiontreeFunc, this, std::placeholders::_1));
}

void GameContextActorPositionInformations::_contextualIdFunc(Reader *input)
{
  this->contextualId = input->readDouble();
  if(this->contextualId < -9.007199254740992E15 || this->contextualId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameContextActorPositionInformations -"<<"Forbidden value (" << this->contextualId << ") on element of GameContextActorPositionInformations.contextualId.";
  }
}

void GameContextActorPositionInformations::_dispositiontreeFunc(Reader *input)
{
  uint _id = input->readUShort();
  this->disposition = qSharedPointerCast<EntityDispositionInformations>(ClassManagerSingleton::get()->getClass(_id));
  this->disposition->deserializeAsync(this->_dispositiontree);
}

GameContextActorPositionInformations::GameContextActorPositionInformations()
{
  m_types<<ClassEnum::GAMECONTEXTACTORPOSITIONINFORMATIONS;
}

bool GameContextActorPositionInformations::operator==(const GameContextActorPositionInformations &compared)
{
  if(contextualId == compared.contextualId)
  if(disposition == compared.disposition)
  if(_dispositiontree == compared._dispositiontree)
  return true;
  
  return false;
}

