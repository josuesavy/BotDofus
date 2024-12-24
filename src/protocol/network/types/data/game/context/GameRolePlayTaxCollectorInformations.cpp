#include "GameRolePlayTaxCollectorInformations.h"

void GameRolePlayTaxCollectorInformations::serialize(Writer *output)
{
  this->serializeAs_GameRolePlayTaxCollectorInformations(output);
}

void GameRolePlayTaxCollectorInformations::serializeAs_GameRolePlayTaxCollectorInformations(Writer *output)
{
  GameRolePlayActorInformations::serializeAs_GameRolePlayActorInformations(output);
  output->writeShort((short)this->identification->getTypes().last());
  this->identification->serialize(output);
  output->writeInt((int)this->taxCollectorAttack);
}

void GameRolePlayTaxCollectorInformations::deserialize(Reader *input)
{
  this->deserializeAs_GameRolePlayTaxCollectorInformations(input);
}

void GameRolePlayTaxCollectorInformations::deserializeAs_GameRolePlayTaxCollectorInformations(Reader *input)
{
  GameRolePlayActorInformations::deserialize(input);
  uint _id1 = uint(input->readUShort());
  this->identification = qSharedPointerCast<TaxCollectorStaticInformations>(ClassManagerSingleton::get()->getClass(_id1));
  this->identification->deserialize(input);
  this->_taxCollectorAttackFunc(input);
}

void GameRolePlayTaxCollectorInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameRolePlayTaxCollectorInformations(tree);
}

void GameRolePlayTaxCollectorInformations::deserializeAsyncAs_GameRolePlayTaxCollectorInformations(FuncTree tree)
{
  GameRolePlayActorInformations::deserializeAsync(tree);
  this->_identificationtree = tree.addChild(std::bind(&GameRolePlayTaxCollectorInformations::_identificationtreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameRolePlayTaxCollectorInformations::_taxCollectorAttackFunc, this, std::placeholders::_1));
}

void GameRolePlayTaxCollectorInformations::_identificationtreeFunc(Reader *input)
{
  uint _id = uint(input->readUShort());
  this->identification = qSharedPointerCast<TaxCollectorStaticInformations>(ClassManagerSingleton::get()->getClass(_id));
  this->identification->deserializeAsync(this->_identificationtree);
}

void GameRolePlayTaxCollectorInformations::_taxCollectorAttackFunc(Reader *input)
{
  this->taxCollectorAttack = input->readInt();
}

GameRolePlayTaxCollectorInformations::GameRolePlayTaxCollectorInformations()
{
  m_types<<ClassEnum::GAMEROLEPLAYTAXCOLLECTORINFORMATIONS;
}

bool GameRolePlayTaxCollectorInformations::operator==(const GameRolePlayTaxCollectorInformations &compared)
{
  if(identification == compared.identification)
  if(taxCollectorAttack == compared.taxCollectorAttack)
  if(_identificationtree == compared._identificationtree)
  return true;
  
  return false;
}

