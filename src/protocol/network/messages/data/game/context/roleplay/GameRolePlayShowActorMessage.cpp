#include "GameRolePlayShowActorMessage.h"

void GameRolePlayShowActorMessage::serialize(Writer *output)
{
  this->serializeAs_GameRolePlayShowActorMessage(output);
}

void GameRolePlayShowActorMessage::serializeAs_GameRolePlayShowActorMessage(Writer *output)
{
  output->writeShort((short)this->informations->getTypes().last());
  this->informations->serialize(output);
}

void GameRolePlayShowActorMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameRolePlayShowActorMessage(input);
}

void GameRolePlayShowActorMessage::deserializeAs_GameRolePlayShowActorMessage(Reader *input)
{
  uint _id1 = uint(input->readUShort());
  this->informations = qSharedPointerCast<GameRolePlayActorInformations>(ClassManagerSingleton::get()->getClass(_id1));
  this->informations->deserialize(input);
}

void GameRolePlayShowActorMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameRolePlayShowActorMessage(tree);
}

void GameRolePlayShowActorMessage::deserializeAsyncAs_GameRolePlayShowActorMessage(FuncTree tree)
{
  this->_informationstree = tree.addChild(std::bind(&GameRolePlayShowActorMessage::_informationstreeFunc, this, std::placeholders::_1));
}

void GameRolePlayShowActorMessage::_informationstreeFunc(Reader *input)
{
  uint _id = uint(input->readUShort());
  this->informations = qSharedPointerCast<GameRolePlayActorInformations>(ClassManagerSingleton::get()->getClass(_id));
  this->informations->deserializeAsync(this->_informationstree);
}

GameRolePlayShowActorMessage::GameRolePlayShowActorMessage()
{
  m_type = MessageEnum::GAMEROLEPLAYSHOWACTORMESSAGE;
}

