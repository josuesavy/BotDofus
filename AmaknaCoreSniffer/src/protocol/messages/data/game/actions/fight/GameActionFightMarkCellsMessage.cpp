#include "GameActionFightMarkCellsMessage.h"

void GameActionFightMarkCellsMessage::serialize(Writer *output)
{
  this->serializeAs_GameActionFightMarkCellsMessage(output);
}

void GameActionFightMarkCellsMessage::serializeAs_GameActionFightMarkCellsMessage(Writer *output)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(output);
  this->mark.serializeAs_GameActionMark(output);
}

void GameActionFightMarkCellsMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameActionFightMarkCellsMessage(input);
}

void GameActionFightMarkCellsMessage::deserializeAs_GameActionFightMarkCellsMessage(Reader *input)
{
  AbstractGameActionMessage::deserialize(input);
  this->mark = GameActionMark();
  this->mark.deserialize(input);
}

void GameActionFightMarkCellsMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameActionFightMarkCellsMessage(tree);
}

void GameActionFightMarkCellsMessage::deserializeAsyncAs_GameActionFightMarkCellsMessage(FuncTree tree)
{
  AbstractGameActionMessage::deserializeAsync(tree);
  this->_marktree = tree.addChild(std::bind(&GameActionFightMarkCellsMessage::_marktreeFunc, this, std::placeholders::_1));
}

void GameActionFightMarkCellsMessage::_marktreeFunc(Reader *input)
{
  this->mark = GameActionMark();
  this->mark.deserializeAsync(this->_marktree);
}

GameActionFightMarkCellsMessage::GameActionFightMarkCellsMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTMARKCELLSMESSAGE;
}

