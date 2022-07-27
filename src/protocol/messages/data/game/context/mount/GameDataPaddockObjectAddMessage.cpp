#include "GameDataPaddockObjectAddMessage.h"

void GameDataPaddockObjectAddMessage::serialize(Writer *output)
{
  this->serializeAs_GameDataPaddockObjectAddMessage(output);
}

void GameDataPaddockObjectAddMessage::serializeAs_GameDataPaddockObjectAddMessage(Writer *output)
{
  this->paddockItemDescription.serializeAs_PaddockItem(output);
}

void GameDataPaddockObjectAddMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameDataPaddockObjectAddMessage(input);
}

void GameDataPaddockObjectAddMessage::deserializeAs_GameDataPaddockObjectAddMessage(Reader *input)
{
  this->paddockItemDescription = PaddockItem();
  this->paddockItemDescription.deserialize(input);
}

void GameDataPaddockObjectAddMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameDataPaddockObjectAddMessage(tree);
}

void GameDataPaddockObjectAddMessage::deserializeAsyncAs_GameDataPaddockObjectAddMessage(FuncTree tree)
{
  this->_paddockItemDescriptiontree = tree.addChild(std::bind(&GameDataPaddockObjectAddMessage::_paddockItemDescriptiontreeFunc, this, std::placeholders::_1));
}

void GameDataPaddockObjectAddMessage::_paddockItemDescriptiontreeFunc(Reader *input)
{
  this->paddockItemDescription = PaddockItem();
  this->paddockItemDescription.deserializeAsync(this->_paddockItemDescriptiontree);
}

GameDataPaddockObjectAddMessage::GameDataPaddockObjectAddMessage()
{
  m_type = MessageEnum::GAMEDATAPADDOCKOBJECTADDMESSAGE;
}

