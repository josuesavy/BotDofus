#include "GameMapChangeOrientationsMessage.h"

void GameMapChangeOrientationsMessage::serialize(Writer *output)
{
  this->serializeAs_GameMapChangeOrientationsMessage(output);
}

void GameMapChangeOrientationsMessage::serializeAs_GameMapChangeOrientationsMessage(Writer *output)
{
  output->writeShort((short)this->orientations.size());
  for(uint _i1 = 0; _i1 < this->orientations.size(); _i1++)
  {
    (this->orientations[_i1]).serializeAs_ActorOrientation(output);
  }
}

void GameMapChangeOrientationsMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameMapChangeOrientationsMessage(input);
}

void GameMapChangeOrientationsMessage::deserializeAs_GameMapChangeOrientationsMessage(Reader *input)
{
  ActorOrientation _item1 ;
  uint _orientationsLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _orientationsLen; _i1++)
  {
    _item1 = ActorOrientation();
    _item1.deserialize(input);
    this->orientations.append(_item1);
  }
}

void GameMapChangeOrientationsMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameMapChangeOrientationsMessage(tree);
}

void GameMapChangeOrientationsMessage::deserializeAsyncAs_GameMapChangeOrientationsMessage(FuncTree tree)
{
  this->_orientationstree = tree.addChild(std::bind(&GameMapChangeOrientationsMessage::_orientationstreeFunc, this, std::placeholders::_1));
}

void GameMapChangeOrientationsMessage::_orientationstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_orientationstree.addChild(std::bind(&GameMapChangeOrientationsMessage::_orientationsFunc, this, std::placeholders::_1));
  }
}

void GameMapChangeOrientationsMessage::_orientationsFunc(Reader *input)
{
  ActorOrientation _item = ActorOrientation();
  _item.deserialize(input);
  this->orientations.append(_item);
}

GameMapChangeOrientationsMessage::GameMapChangeOrientationsMessage()
{
  m_type = MessageEnum::GAMEMAPCHANGEORIENTATIONSMESSAGE;
}

