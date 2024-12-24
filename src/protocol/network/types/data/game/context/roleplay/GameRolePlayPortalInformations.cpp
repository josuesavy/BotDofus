#include "GameRolePlayPortalInformations.h"

void GameRolePlayPortalInformations::serialize(Writer *output)
{
  this->serializeAs_GameRolePlayPortalInformations(output);
}

void GameRolePlayPortalInformations::serializeAs_GameRolePlayPortalInformations(Writer *output)
{
  GameRolePlayActorInformations::serializeAs_GameRolePlayActorInformations(output);
  output->writeShort((short)this->portal->getTypes().last());
  this->portal->serialize(output);
}

void GameRolePlayPortalInformations::deserialize(Reader *input)
{
  this->deserializeAs_GameRolePlayPortalInformations(input);
}

void GameRolePlayPortalInformations::deserializeAs_GameRolePlayPortalInformations(Reader *input)
{
  GameRolePlayActorInformations::deserialize(input);
  uint _id1 = uint(input->readUShort());
  this->portal = qSharedPointerCast<PortalInformation>(ClassManagerSingleton::get()->getClass(_id1));
  this->portal->deserialize(input);
}

void GameRolePlayPortalInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameRolePlayPortalInformations(tree);
}

void GameRolePlayPortalInformations::deserializeAsyncAs_GameRolePlayPortalInformations(FuncTree tree)
{
  GameRolePlayActorInformations::deserializeAsync(tree);
  this->_portaltree = tree.addChild(std::bind(&GameRolePlayPortalInformations::_portaltreeFunc, this, std::placeholders::_1));
}

void GameRolePlayPortalInformations::_portaltreeFunc(Reader *input)
{
  uint _id = uint(input->readUShort());
  this->portal = qSharedPointerCast<PortalInformation>(ClassManagerSingleton::get()->getClass(_id));
  this->portal->deserializeAsync(this->_portaltree);
}

GameRolePlayPortalInformations::GameRolePlayPortalInformations()
{
  m_types<<ClassEnum::GAMEROLEPLAYPORTALINFORMATIONS;
}

bool GameRolePlayPortalInformations::operator==(const GameRolePlayPortalInformations &compared)
{
  if(portal == compared.portal)
  if(_portaltree == compared._portaltree)
  return true;
  
  return false;
}

