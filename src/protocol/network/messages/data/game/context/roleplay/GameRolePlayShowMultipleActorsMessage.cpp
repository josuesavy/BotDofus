#include "GameRolePlayShowMultipleActorsMessage.h"

void GameRolePlayShowMultipleActorsMessage::serialize(Writer *output)
{
  this->serializeAs_GameRolePlayShowMultipleActorsMessage(output);
}

void GameRolePlayShowMultipleActorsMessage::serializeAs_GameRolePlayShowMultipleActorsMessage(Writer *output)
{
  output->writeShort((short)this->informationsList.size());
  for(uint _i1 = 0; _i1 < this->informationsList.size(); _i1++)
  {
    output->writeShort((short)qSharedPointerCast<GameRolePlayActorInformations>(this->informationsList[_i1])->getTypes().last());
    qSharedPointerCast<GameRolePlayActorInformations>(this->informationsList[_i1])->serialize(output);
  }
}

void GameRolePlayShowMultipleActorsMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameRolePlayShowMultipleActorsMessage(input);
}

void GameRolePlayShowMultipleActorsMessage::deserializeAs_GameRolePlayShowMultipleActorsMessage(Reader *input)
{
  uint _id1 = 0;
  QSharedPointer<GameRolePlayActorInformations> _item1 ;
  uint _informationsListLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _informationsListLen; _i1++)
  {
    _id1 = uint(input->readUShort());
    _item1 = qSharedPointerCast<GameRolePlayActorInformations>(ClassManagerSingleton::get()->getClass(_id1));
    _item1->deserialize(input);
    this->informationsList.append(_item1);
  }
}

void GameRolePlayShowMultipleActorsMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameRolePlayShowMultipleActorsMessage(tree);
}

void GameRolePlayShowMultipleActorsMessage::deserializeAsyncAs_GameRolePlayShowMultipleActorsMessage(FuncTree tree)
{
  this->_informationsListtree = tree.addChild(std::bind(&GameRolePlayShowMultipleActorsMessage::_informationsListtreeFunc, this, std::placeholders::_1));
}

void GameRolePlayShowMultipleActorsMessage::_informationsListtreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_informationsListtree.addChild(std::bind(&GameRolePlayShowMultipleActorsMessage::_informationsListFunc, this, std::placeholders::_1));
  }
}

void GameRolePlayShowMultipleActorsMessage::_informationsListFunc(Reader *input)
{
  uint _id = uint(input->readUShort());
  QSharedPointer<GameRolePlayActorInformations> _item = qSharedPointerCast<GameRolePlayActorInformations>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->informationsList.append(_item);
}

GameRolePlayShowMultipleActorsMessage::GameRolePlayShowMultipleActorsMessage()
{
  m_type = MessageEnum::GAMEROLEPLAYSHOWMULTIPLEACTORSMESSAGE;
}

