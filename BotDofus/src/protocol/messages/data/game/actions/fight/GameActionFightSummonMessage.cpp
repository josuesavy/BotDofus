#include "GameActionFightSummonMessage.h"

void GameActionFightSummonMessage::serialize(Writer *output)
{
  this->serializeAs_GameActionFightSummonMessage(output);
}

void GameActionFightSummonMessage::serializeAs_GameActionFightSummonMessage(Writer *output)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(output);
  output->writeShort((short)this->summons.size());
  for(uint _i1 = 0; _i1 < this->summons.size(); _i1++)
  {
    output->writeShort((short)qSharedPointerCast<GameFightFighterInformations>(this->summons[_i1])->getTypes().last());
    qSharedPointerCast<GameFightFighterInformations>(this->summons[_i1])->serialize(output);
  }
}

void GameActionFightSummonMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameActionFightSummonMessage(input);
}

void GameActionFightSummonMessage::deserializeAs_GameActionFightSummonMessage(Reader *input)
{
  uint _id1 = 0;
  QSharedPointer<GameFightFighterInformations> _item1 ;
  AbstractGameActionMessage::deserialize(input);
  uint _summonsLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _summonsLen; _i1++)
  {
    _id1 = input->readUShort();
    _item1 = qSharedPointerCast<GameFightFighterInformations>(ClassManagerSingleton::get()->getClass(_id1));
    _item1->deserialize(input);
    this->summons.append(_item1);
  }
}

void GameActionFightSummonMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameActionFightSummonMessage(tree);
}

void GameActionFightSummonMessage::deserializeAsyncAs_GameActionFightSummonMessage(FuncTree tree)
{
  AbstractGameActionMessage::deserializeAsync(tree);
  this->_summonstree = tree.addChild(std::bind(&GameActionFightSummonMessage::_summonstreeFunc, this, std::placeholders::_1));
}

void GameActionFightSummonMessage::_summonstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_summonstree.addChild(std::bind(&GameActionFightSummonMessage::_summonsFunc, this, std::placeholders::_1));
  }
}

void GameActionFightSummonMessage::_summonsFunc(Reader *input)
{
  uint _id = input->readUShort();
  QSharedPointer<GameFightFighterInformations> _item = qSharedPointerCast<GameFightFighterInformations>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->summons.append(_item);
}

GameActionFightSummonMessage::GameActionFightSummonMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTSUMMONMESSAGE;
}

