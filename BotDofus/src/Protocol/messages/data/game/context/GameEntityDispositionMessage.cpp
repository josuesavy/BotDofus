#include "GameEntityDispositionMessage.h"

void GameEntityDispositionMessage::serialize(Writer *output)
{
  this->serializeAs_GameEntityDispositionMessage(output);
}

void GameEntityDispositionMessage::serializeAs_GameEntityDispositionMessage(Writer *output)
{
  this->disposition->serializeAs_IdentifiedEntityDispositionInformations(output);
}

void GameEntityDispositionMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameEntityDispositionMessage(input);
}

void GameEntityDispositionMessage::deserializeAs_GameEntityDispositionMessage(Reader *input)
{
  this->disposition = QSharedPointer<IdentifiedEntityDispositionInformations>(new IdentifiedEntityDispositionInformations() );
  this->disposition->deserialize(input);
}

void GameEntityDispositionMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameEntityDispositionMessage(tree);
}

void GameEntityDispositionMessage::deserializeAsyncAs_GameEntityDispositionMessage(FuncTree tree)
{
  this->_dispositiontree = tree.addChild(std::bind(&GameEntityDispositionMessage::_dispositiontreeFunc, this, std::placeholders::_1));
}

void GameEntityDispositionMessage::_dispositiontreeFunc(Reader *input)
{
  this->disposition = QSharedPointer<IdentifiedEntityDispositionInformations>(new IdentifiedEntityDispositionInformations() );
  this->disposition->deserializeAsync(this->_dispositiontree);
}

GameEntityDispositionMessage::GameEntityDispositionMessage()
{
  m_type = MessageEnum::GAMEENTITYDISPOSITIONMESSAGE;
}

