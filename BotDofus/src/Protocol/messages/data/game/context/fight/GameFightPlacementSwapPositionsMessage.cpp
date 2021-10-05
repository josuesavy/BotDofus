#include "GameFightPlacementSwapPositionsMessage.h"

void GameFightPlacementSwapPositionsMessage::serialize(Writer *output)
{
  this->serializeAs_GameFightPlacementSwapPositionsMessage(output);
}

void GameFightPlacementSwapPositionsMessage::serializeAs_GameFightPlacementSwapPositionsMessage(Writer *output)
{
  for(uint _i1 = 0; _i1 < 2; _i1++)
  {
    this->dispositions[_i1]->serializeAs_IdentifiedEntityDispositionInformations(output);
  }
}

void GameFightPlacementSwapPositionsMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameFightPlacementSwapPositionsMessage(input);
}

void GameFightPlacementSwapPositionsMessage::deserializeAs_GameFightPlacementSwapPositionsMessage(Reader *input)
{
  for(uint _i1 = 0; _i1 < 2; _i1++)
  {
    this->dispositions<<QSharedPointer<IdentifiedEntityDispositionInformations>(new IdentifiedEntityDispositionInformations() );
    this->dispositions[_i1]->deserialize(input);
  }
}

void GameFightPlacementSwapPositionsMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameFightPlacementSwapPositionsMessage(tree);
}

void GameFightPlacementSwapPositionsMessage::deserializeAsyncAs_GameFightPlacementSwapPositionsMessage(FuncTree tree)
{
  this->_dispositionstree = tree.addChild(std::bind(&GameFightPlacementSwapPositionsMessage::_dispositionstreeFunc, this, std::placeholders::_1));
}

void GameFightPlacementSwapPositionsMessage::_dispositionstreeFunc(Reader *input)
{
  for(uint i = 0; i < 2; i++)
  {
    this->_dispositionstree.addChild(std::bind(&GameFightPlacementSwapPositionsMessage::_dispositionsFunc, this, std::placeholders::_1));
  }
}

void GameFightPlacementSwapPositionsMessage::_dispositionsFunc(Reader *input)
{
  this->dispositions<<QSharedPointer<IdentifiedEntityDispositionInformations>(new IdentifiedEntityDispositionInformations() );
  this->dispositions[this->_dispositionsindex]->deserializeAsync(this->_dispositionstree.getChild(this->_dispositionsindex));
  this->_dispositionsindex++;
}

GameFightPlacementSwapPositionsMessage::GameFightPlacementSwapPositionsMessage()
{
  m_type = MessageEnum::GAMEFIGHTPLACEMENTSWAPPOSITIONSMESSAGE;
}

