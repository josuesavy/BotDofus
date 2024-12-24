#include "GameContextMoveMultipleElementsMessage.h"

void GameContextMoveMultipleElementsMessage::serialize(Writer *output)
{
  this->serializeAs_GameContextMoveMultipleElementsMessage(output);
}

void GameContextMoveMultipleElementsMessage::serializeAs_GameContextMoveMultipleElementsMessage(Writer *output)
{
  output->writeShort((short)this->movements.size());
  for(uint _i1 = 0; _i1 < this->movements.size(); _i1++)
  {
    (this->movements[_i1]).serializeAs_EntityMovementInformations(output);
  }
}

void GameContextMoveMultipleElementsMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameContextMoveMultipleElementsMessage(input);
}

void GameContextMoveMultipleElementsMessage::deserializeAs_GameContextMoveMultipleElementsMessage(Reader *input)
{
  EntityMovementInformations _item1 ;
  uint _movementsLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _movementsLen; _i1++)
  {
    _item1 = EntityMovementInformations();
    _item1.deserialize(input);
    this->movements.append(_item1);
  }
}

void GameContextMoveMultipleElementsMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameContextMoveMultipleElementsMessage(tree);
}

void GameContextMoveMultipleElementsMessage::deserializeAsyncAs_GameContextMoveMultipleElementsMessage(FuncTree tree)
{
  this->_movementstree = tree.addChild(std::bind(&GameContextMoveMultipleElementsMessage::_movementstreeFunc, this, std::placeholders::_1));
}

void GameContextMoveMultipleElementsMessage::_movementstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_movementstree.addChild(std::bind(&GameContextMoveMultipleElementsMessage::_movementsFunc, this, std::placeholders::_1));
  }
}

void GameContextMoveMultipleElementsMessage::_movementsFunc(Reader *input)
{
  EntityMovementInformations _item = EntityMovementInformations();
  _item.deserialize(input);
  this->movements.append(_item);
}

GameContextMoveMultipleElementsMessage::GameContextMoveMultipleElementsMessage()
{
  m_type = MessageEnum::GAMECONTEXTMOVEMULTIPLEELEMENTSMESSAGE;
}

