#include "FighterStatsListMessage.h"

void FighterStatsListMessage::serialize(Writer *output)
{
  this->serializeAs_FighterStatsListMessage(output);
}

void FighterStatsListMessage::serializeAs_FighterStatsListMessage(Writer *output)
{
  this->stats.serializeAs_CharacterCharacteristicsInformations(output);
}

void FighterStatsListMessage::deserialize(Reader *input)
{
  this->deserializeAs_FighterStatsListMessage(input);
}

void FighterStatsListMessage::deserializeAs_FighterStatsListMessage(Reader *input)
{
  this->stats = CharacterCharacteristicsInformations();
  this->stats.deserialize(input);
}

void FighterStatsListMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_FighterStatsListMessage(tree);
}

void FighterStatsListMessage::deserializeAsyncAs_FighterStatsListMessage(FuncTree tree)
{
  this->_statstree = tree.addChild(std::bind(&FighterStatsListMessage::_statstreeFunc, this, std::placeholders::_1));
}

void FighterStatsListMessage::_statstreeFunc(Reader *input)
{
  this->stats = CharacterCharacteristicsInformations();
  this->stats.deserializeAsync(this->_statstree);
}

FighterStatsListMessage::FighterStatsListMessage()
{
  m_type = MessageEnum::FIGHTERSTATSLISTMESSAGE;
}

