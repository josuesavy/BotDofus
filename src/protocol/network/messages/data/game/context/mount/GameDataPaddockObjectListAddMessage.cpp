#include "GameDataPaddockObjectListAddMessage.h"

void GameDataPaddockObjectListAddMessage::serialize(Writer *output)
{
  this->serializeAs_GameDataPaddockObjectListAddMessage(output);
}

void GameDataPaddockObjectListAddMessage::serializeAs_GameDataPaddockObjectListAddMessage(Writer *output)
{
  output->writeShort((short)this->paddockItemDescription.size());
  for(uint _i1 = 0; _i1 < this->paddockItemDescription.size(); _i1++)
  {
    (this->paddockItemDescription[_i1]).serializeAs_PaddockItem(output);
  }
}

void GameDataPaddockObjectListAddMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameDataPaddockObjectListAddMessage(input);
}

void GameDataPaddockObjectListAddMessage::deserializeAs_GameDataPaddockObjectListAddMessage(Reader *input)
{
  PaddockItem _item1 ;
  uint _paddockItemDescriptionLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _paddockItemDescriptionLen; _i1++)
  {
    _item1 = PaddockItem();
    _item1.deserialize(input);
    this->paddockItemDescription.append(_item1);
  }
}

void GameDataPaddockObjectListAddMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameDataPaddockObjectListAddMessage(tree);
}

void GameDataPaddockObjectListAddMessage::deserializeAsyncAs_GameDataPaddockObjectListAddMessage(FuncTree tree)
{
  this->_paddockItemDescriptiontree = tree.addChild(std::bind(&GameDataPaddockObjectListAddMessage::_paddockItemDescriptiontreeFunc, this, std::placeholders::_1));
}

void GameDataPaddockObjectListAddMessage::_paddockItemDescriptiontreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_paddockItemDescriptiontree.addChild(std::bind(&GameDataPaddockObjectListAddMessage::_paddockItemDescriptionFunc, this, std::placeholders::_1));
  }
}

void GameDataPaddockObjectListAddMessage::_paddockItemDescriptionFunc(Reader *input)
{
  PaddockItem _item = PaddockItem();
  _item.deserialize(input);
  this->paddockItemDescription.append(_item);
}

GameDataPaddockObjectListAddMessage::GameDataPaddockObjectListAddMessage()
{
  m_type = MessageEnum::GAMEDATAPADDOCKOBJECTLISTADDMESSAGE;
}

