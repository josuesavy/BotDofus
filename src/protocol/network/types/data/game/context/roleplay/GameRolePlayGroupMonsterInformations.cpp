#include "GameRolePlayGroupMonsterInformations.h"

void GameRolePlayGroupMonsterInformations::serialize(Writer *output)
{
  this->serializeAs_GameRolePlayGroupMonsterInformations(output);
}

void GameRolePlayGroupMonsterInformations::serializeAs_GameRolePlayGroupMonsterInformations(Writer *output)
{
  GameRolePlayActorInformations::serializeAs_GameRolePlayActorInformations(output);
  output->writeShort((short)this->staticInfos->getTypes().last());
  this->staticInfos->serialize(output);
  if(this->lootShare < -1 || this->lootShare > 8)
  {
    qDebug()<<"ERREUR - GameRolePlayGroupMonsterInformations -"<<"Forbidden value (" << this->lootShare << ") on element lootShare.";
  }
  output->writeByte(this->lootShare);
  output->writeByte(this->alignmentSide);
  output->writeBool(this->hasHardcoreDrop);
}

void GameRolePlayGroupMonsterInformations::deserialize(Reader *input)
{
  this->deserializeAs_GameRolePlayGroupMonsterInformations(input);
}

void GameRolePlayGroupMonsterInformations::deserializeAs_GameRolePlayGroupMonsterInformations(Reader *input)
{
  GameRolePlayActorInformations::deserialize(input);
  uint _id1 = uint(input->readUShort());
  this->staticInfos = qSharedPointerCast<GroupMonsterStaticInformations>(ClassManagerSingleton::get()->getClass(_id1));
  this->staticInfos->deserialize(input);
  this->_lootShareFunc(input);
  this->_alignmentSideFunc(input);
  this->_hasHardcoreDropFunc(input);
}

void GameRolePlayGroupMonsterInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameRolePlayGroupMonsterInformations(tree);
}

void GameRolePlayGroupMonsterInformations::deserializeAsyncAs_GameRolePlayGroupMonsterInformations(FuncTree tree)
{
  GameRolePlayActorInformations::deserializeAsync(tree);
  this->_staticInfostree = tree.addChild(std::bind(&GameRolePlayGroupMonsterInformations::_staticInfostreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameRolePlayGroupMonsterInformations::_lootShareFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameRolePlayGroupMonsterInformations::_alignmentSideFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameRolePlayGroupMonsterInformations::_hasHardcoreDropFunc, this, std::placeholders::_1));
}

void GameRolePlayGroupMonsterInformations::_staticInfostreeFunc(Reader *input)
{
  uint _id = uint(input->readUShort());
  this->staticInfos = qSharedPointerCast<GroupMonsterStaticInformations>(ClassManagerSingleton::get()->getClass(_id));
  this->staticInfos->deserializeAsync(this->_staticInfostree);
}

void GameRolePlayGroupMonsterInformations::_lootShareFunc(Reader *input)
{
  this->lootShare = input->readByte();
  if(this->lootShare < -1 || this->lootShare > 8)
  {
    qDebug()<<"ERREUR - GameRolePlayGroupMonsterInformations -"<<"Forbidden value (" << this->lootShare << ") on element of GameRolePlayGroupMonsterInformations.lootShare.";
  }
}

void GameRolePlayGroupMonsterInformations::_alignmentSideFunc(Reader *input)
{
  this->alignmentSide = input->readByte();
}

void GameRolePlayGroupMonsterInformations::_hasHardcoreDropFunc(Reader *input)
{
  this->hasHardcoreDrop = input->readBool();
}

GameRolePlayGroupMonsterInformations::GameRolePlayGroupMonsterInformations()
{
  m_types<<ClassEnum::GAMEROLEPLAYGROUPMONSTERINFORMATIONS;
}

bool GameRolePlayGroupMonsterInformations::operator==(const GameRolePlayGroupMonsterInformations &compared)
{
  if(staticInfos == compared.staticInfos)
  if(lootShare == compared.lootShare)
  if(alignmentSide == compared.alignmentSide)
  if(hasHardcoreDrop == compared.hasHardcoreDrop)
  if(_staticInfostree == compared._staticInfostree)
  return true;
  
  return false;
}

