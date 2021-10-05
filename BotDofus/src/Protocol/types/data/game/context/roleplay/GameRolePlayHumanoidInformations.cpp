#include "GameRolePlayHumanoidInformations.h"

void GameRolePlayHumanoidInformations::serialize(Writer *output)
{
  this->serializeAs_GameRolePlayHumanoidInformations(output);
}

void GameRolePlayHumanoidInformations::serializeAs_GameRolePlayHumanoidInformations(Writer *output)
{
  GameRolePlayNamedActorInformations::serializeAs_GameRolePlayNamedActorInformations(output);
  output->writeShort((short)this->humanoidInfo->getTypes().last());
  this->humanoidInfo->serialize(output);
  if(this->accountId < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayHumanoidInformations -"<<"Forbidden value (" << this->accountId << ") on element accountId.";
  }
  output->writeInt((int)this->accountId);
}

void GameRolePlayHumanoidInformations::deserialize(Reader *input)
{
  this->deserializeAs_GameRolePlayHumanoidInformations(input);
}

void GameRolePlayHumanoidInformations::deserializeAs_GameRolePlayHumanoidInformations(Reader *input)
{
  GameRolePlayNamedActorInformations::deserialize(input);
  uint _id1 = input->readUShort();
  this->humanoidInfo = qSharedPointerCast<HumanInformations>(ClassManagerSingleton::get()->getClass(_id1));
  this->humanoidInfo->deserialize(input);
  this->_accountIdFunc(input);
}

void GameRolePlayHumanoidInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameRolePlayHumanoidInformations(tree);
}

void GameRolePlayHumanoidInformations::deserializeAsyncAs_GameRolePlayHumanoidInformations(FuncTree tree)
{
  GameRolePlayNamedActorInformations::deserializeAsync(tree);
  this->_humanoidInfotree = tree.addChild(std::bind(&GameRolePlayHumanoidInformations::_humanoidInfotreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameRolePlayHumanoidInformations::_accountIdFunc, this, std::placeholders::_1));
}

void GameRolePlayHumanoidInformations::_humanoidInfotreeFunc(Reader *input)
{
  uint _id = input->readUShort();
  this->humanoidInfo = qSharedPointerCast<HumanInformations>(ClassManagerSingleton::get()->getClass(_id));
  this->humanoidInfo->deserializeAsync(this->_humanoidInfotree);
}

void GameRolePlayHumanoidInformations::_accountIdFunc(Reader *input)
{
  this->accountId = input->readInt();
  if(this->accountId < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayHumanoidInformations -"<<"Forbidden value (" << this->accountId << ") on element of GameRolePlayHumanoidInformations.accountId.";
  }
}

GameRolePlayHumanoidInformations::GameRolePlayHumanoidInformations()
{
  m_types<<ClassEnum::GAMEROLEPLAYHUMANOIDINFORMATIONS;
}

bool GameRolePlayHumanoidInformations::operator==(const GameRolePlayHumanoidInformations &compared)
{
  if(humanoidInfo == compared.humanoidInfo)
  if(accountId == compared.accountId)
  if(_humanoidInfotree == compared._humanoidInfotree)
  return true;
  
  return false;
}

