#include "GameRolePlayPrismInformations.h"

void GameRolePlayPrismInformations::serialize(Writer *output)
{
  this->serializeAs_GameRolePlayPrismInformations(output);
}

void GameRolePlayPrismInformations::serializeAs_GameRolePlayPrismInformations(Writer *output)
{
  GameRolePlayActorInformations::serializeAs_GameRolePlayActorInformations(output);
  output->writeShort((short)this->prism->getTypes().last());
  this->prism->serialize(output);
}

void GameRolePlayPrismInformations::deserialize(Reader *input)
{
  this->deserializeAs_GameRolePlayPrismInformations(input);
}

void GameRolePlayPrismInformations::deserializeAs_GameRolePlayPrismInformations(Reader *input)
{
  GameRolePlayActorInformations::deserialize(input);
  uint _id1 = uint(input->readUShort());
  this->prism = qSharedPointerCast<PrismInformation>(ClassManagerSingleton::get()->getClass(_id1));
  this->prism->deserialize(input);
}

void GameRolePlayPrismInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameRolePlayPrismInformations(tree);
}

void GameRolePlayPrismInformations::deserializeAsyncAs_GameRolePlayPrismInformations(FuncTree tree)
{
  GameRolePlayActorInformations::deserializeAsync(tree);
  this->_prismtree = tree.addChild(std::bind(&GameRolePlayPrismInformations::_prismtreeFunc, this, std::placeholders::_1));
}

void GameRolePlayPrismInformations::_prismtreeFunc(Reader *input)
{
  uint _id = uint(input->readUShort());
  this->prism = qSharedPointerCast<PrismInformation>(ClassManagerSingleton::get()->getClass(_id));
  this->prism->deserializeAsync(this->_prismtree);
}

GameRolePlayPrismInformations::GameRolePlayPrismInformations()
{
  m_types<<ClassEnum::GAMEROLEPLAYPRISMINFORMATIONS;
}

bool GameRolePlayPrismInformations::operator==(const GameRolePlayPrismInformations &compared)
{
  if(prism == compared.prism)
  if(_prismtree == compared._prismtree)
  return true;
  
  return false;
}

