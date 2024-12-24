#include "GameActionSpamMessage.h"

void GameActionSpamMessage::serialize(Writer *output)
{
  this->serializeAs_GameActionSpamMessage(output);
}

void GameActionSpamMessage::serializeAs_GameActionSpamMessage(Writer *output)
{
  output->writeShort((short)this->cells.size());
  for(uint _i1 = 0; _i1 < this->cells.size(); _i1++)
  {
    output->writeShort((short)this->cells[_i1]);
  }
}

void GameActionSpamMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameActionSpamMessage(input);
}

void GameActionSpamMessage::deserializeAs_GameActionSpamMessage(Reader *input)
{
  int _val1 = 0;
  uint _cellsLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _cellsLen; _i1++)
  {
    _val1 = int(input->readShort());
    this->cells.append(_val1);
  }
}

void GameActionSpamMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameActionSpamMessage(tree);
}

void GameActionSpamMessage::deserializeAsyncAs_GameActionSpamMessage(FuncTree tree)
{
  this->_cellstree = tree.addChild(std::bind(&GameActionSpamMessage::_cellstreeFunc, this, std::placeholders::_1));
}

void GameActionSpamMessage::_cellstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_cellstree.addChild(std::bind(&GameActionSpamMessage::_cellsFunc, this, std::placeholders::_1));
  }
}

void GameActionSpamMessage::_cellsFunc(Reader *input)
{
  int _val = int(input->readShort());
  this->cells.append(_val);
}

GameActionSpamMessage::GameActionSpamMessage()
{
  m_type = MessageEnum::GAMEACTIONSPAMMESSAGE;
}

