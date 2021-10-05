#include "GameActionFightUnmarkCellsMessage.h"

void GameActionFightUnmarkCellsMessage::serialize(Writer *output)
{
  this->serializeAs_GameActionFightUnmarkCellsMessage(output);
}

void GameActionFightUnmarkCellsMessage::serializeAs_GameActionFightUnmarkCellsMessage(Writer *output)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(output);
  output->writeShort((short)this->markId);
}

void GameActionFightUnmarkCellsMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameActionFightUnmarkCellsMessage(input);
}

void GameActionFightUnmarkCellsMessage::deserializeAs_GameActionFightUnmarkCellsMessage(Reader *input)
{
  AbstractGameActionMessage::deserialize(input);
  this->_markIdFunc(input);
}

void GameActionFightUnmarkCellsMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameActionFightUnmarkCellsMessage(tree);
}

void GameActionFightUnmarkCellsMessage::deserializeAsyncAs_GameActionFightUnmarkCellsMessage(FuncTree tree)
{
  AbstractGameActionMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&GameActionFightUnmarkCellsMessage::_markIdFunc, this, std::placeholders::_1));
}

void GameActionFightUnmarkCellsMessage::_markIdFunc(Reader *input)
{
  this->markId = input->readShort();
}

GameActionFightUnmarkCellsMessage::GameActionFightUnmarkCellsMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTUNMARKCELLSMESSAGE;
}

