#include "GameRolePlayGroupMonsterInformations.h"

void GameRolePlayGroupMonsterInformations::serialize(Writer *output)
{
  this->serializeAs_GameRolePlayGroupMonsterInformations(output);
}

void GameRolePlayGroupMonsterInformations::serializeAs_GameRolePlayGroupMonsterInformations(Writer *output)
{
  GameRolePlayActorInformations::serializeAs_GameRolePlayActorInformations(output);
  uint _box0 = 0;
  _box0 = BooleanByteWrapper::setFlag(_box0, 0, this->keyRingBonus);
  _box0 = BooleanByteWrapper::setFlag(_box0, 1, this->hasHardcoreDrop);
  _box0 = BooleanByteWrapper::setFlag(_box0, 2, this->hasAVARewardToken);
  output->writeByte(_box0);
  output->writeShort((short)this->staticInfos->getTypes().last());
  this->staticInfos->serialize(output);
  if(this->lootShare < -1 || this->lootShare > 8)
  {
    qDebug()<<"ERREUR - GameRolePlayGroupMonsterInformations -"<<"Forbidden value (" << this->lootShare << ") on element lootShare.";
  }
  output->writeByte(this->lootShare);
  output->writeByte(this->alignmentSide);
}

void GameRolePlayGroupMonsterInformations::deserialize(Reader *input)
{
  this->deserializeAs_GameRolePlayGroupMonsterInformations(input);
}

void GameRolePlayGroupMonsterInformations::deserializeAs_GameRolePlayGroupMonsterInformations(Reader *input)
{
  GameRolePlayActorInformations::deserialize(input);
  this->deserializeByteBoxes(input);
  uint _id1 = input->readUShort();
  this->staticInfos = qSharedPointerCast<GroupMonsterStaticInformations>(ClassManagerSingleton::get()->getClass(_id1));
  this->staticInfos->deserialize(input);
  this->_lootShareFunc(input);
  this->_alignmentSideFunc(input);
}

void GameRolePlayGroupMonsterInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameRolePlayGroupMonsterInformations(tree);
}

void GameRolePlayGroupMonsterInformations::deserializeAsyncAs_GameRolePlayGroupMonsterInformations(FuncTree tree)
{
  GameRolePlayActorInformations::deserializeAsync(tree);
  tree.addChild(std::bind(&GameRolePlayGroupMonsterInformations::deserializeByteBoxes, this, std::placeholders::_1));
  this->_staticInfostree = tree.addChild(std::bind(&GameRolePlayGroupMonsterInformations::_staticInfostreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameRolePlayGroupMonsterInformations::_lootShareFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameRolePlayGroupMonsterInformations::_alignmentSideFunc, this, std::placeholders::_1));
}

void GameRolePlayGroupMonsterInformations::deserializeByteBoxes(Reader *input)
{
  uint _box0 = input->readByte();
  this->keyRingBonus = BooleanByteWrapper::getFlag(_box0, 0);
  this->hasHardcoreDrop = BooleanByteWrapper::getFlag(_box0, 1);
  this->hasAVARewardToken = BooleanByteWrapper::getFlag(_box0, 2);
}

void GameRolePlayGroupMonsterInformations::_staticInfostreeFunc(Reader *input)
{
  uint _id = input->readUShort();
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

GameRolePlayGroupMonsterInformations::GameRolePlayGroupMonsterInformations()
{
  m_types<<ClassEnum::GAMEROLEPLAYGROUPMONSTERINFORMATIONS;
}

bool GameRolePlayGroupMonsterInformations::operator==(const GameRolePlayGroupMonsterInformations &compared)
{
  if(staticInfos == compared.staticInfos)
  if(lootShare == compared.lootShare)
  if(alignmentSide == compared.alignmentSide)
  if(keyRingBonus == compared.keyRingBonus)
  if(hasHardcoreDrop == compared.hasHardcoreDrop)
  if(hasAVARewardToken == compared.hasAVARewardToken)
  if(_staticInfostree == compared._staticInfostree)
  return true;
  
  return false;
}

