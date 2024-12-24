#include "GameActionItemListMessage.h"

void GameActionItemListMessage::serialize(Writer *output)
{
  this->serializeAs_GameActionItemListMessage(output);
}

void GameActionItemListMessage::serializeAs_GameActionItemListMessage(Writer *output)
{
  output->writeShort((short)this->actions.size());
  for(uint _i1 = 0; _i1 < this->actions.size(); _i1++)
  {
    qSharedPointerCast<GameActionItem>(this->actions[_i1])->serializeAs_GameActionItem(output);
  }
}

void GameActionItemListMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameActionItemListMessage(input);
}

void GameActionItemListMessage::deserializeAs_GameActionItemListMessage(Reader *input)
{
  QSharedPointer<GameActionItem> _item1 ;
  uint _actionsLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _actionsLen; _i1++)
  {
    _item1 = QSharedPointer<GameActionItem>(new GameActionItem() );
    _item1->deserialize(input);
    this->actions.append(_item1);
  }
}

void GameActionItemListMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameActionItemListMessage(tree);
}

void GameActionItemListMessage::deserializeAsyncAs_GameActionItemListMessage(FuncTree tree)
{
  this->_actionstree = tree.addChild(std::bind(&GameActionItemListMessage::_actionstreeFunc, this, std::placeholders::_1));
}

void GameActionItemListMessage::_actionstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_actionstree.addChild(std::bind(&GameActionItemListMessage::_actionsFunc, this, std::placeholders::_1));
  }
}

void GameActionItemListMessage::_actionsFunc(Reader *input)
{
  QSharedPointer<GameActionItem> _item = QSharedPointer<GameActionItem>(new GameActionItem() );
  _item->deserialize(input);
  this->actions.append(_item);
}

GameActionItemListMessage::GameActionItemListMessage()
{
  m_type = MessageEnum::GAMEACTIONITEMLISTMESSAGE;
}

