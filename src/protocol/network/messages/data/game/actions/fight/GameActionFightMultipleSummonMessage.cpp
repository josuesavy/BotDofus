#include "GameActionFightMultipleSummonMessage.h"

void GameActionFightMultipleSummonMessage::serialize(Writer *output)
{
  this->serializeAs_GameActionFightMultipleSummonMessage(output);
}

void GameActionFightMultipleSummonMessage::serializeAs_GameActionFightMultipleSummonMessage(Writer *output)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(output);
  output->writeShort((short)this->summons.size());
  for(uint _i1 = 0; _i1 < this->summons.size(); _i1++)
  {
    output->writeShort((short)qSharedPointerCast<GameContextSummonsInformation>(this->summons[_i1])->getTypes().last());
    qSharedPointerCast<GameContextSummonsInformation>(this->summons[_i1])->serialize(output);
  }
}

void GameActionFightMultipleSummonMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameActionFightMultipleSummonMessage(input);
}

void GameActionFightMultipleSummonMessage::deserializeAs_GameActionFightMultipleSummonMessage(Reader *input)
{
  uint _id1 = 0;
  QSharedPointer<GameContextSummonsInformation> _item1 ;
  AbstractGameActionMessage::deserialize(input);
  uint _summonsLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _summonsLen; _i1++)
  {
    _id1 = uint(input->readUShort());
    _item1 = qSharedPointerCast<GameContextSummonsInformation>(ClassManagerSingleton::get()->getClass(_id1));
    _item1->deserialize(input);
    this->summons.append(_item1);
  }
}

void GameActionFightMultipleSummonMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameActionFightMultipleSummonMessage(tree);
}

void GameActionFightMultipleSummonMessage::deserializeAsyncAs_GameActionFightMultipleSummonMessage(FuncTree tree)
{
  AbstractGameActionMessage::deserializeAsync(tree);
  this->_summonstree = tree.addChild(std::bind(&GameActionFightMultipleSummonMessage::_summonstreeFunc, this, std::placeholders::_1));
}

void GameActionFightMultipleSummonMessage::_summonstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_summonstree.addChild(std::bind(&GameActionFightMultipleSummonMessage::_summonsFunc, this, std::placeholders::_1));
  }
}

void GameActionFightMultipleSummonMessage::_summonsFunc(Reader *input)
{
  uint _id = uint(input->readUShort());
  QSharedPointer<GameContextSummonsInformation> _item = qSharedPointerCast<GameContextSummonsInformation>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->summons.append(_item);
}

GameActionFightMultipleSummonMessage::GameActionFightMultipleSummonMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTMULTIPLESUMMONMESSAGE;
}

