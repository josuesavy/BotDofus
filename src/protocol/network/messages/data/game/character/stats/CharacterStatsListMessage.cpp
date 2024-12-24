#include "CharacterStatsListMessage.h"

void CharacterStatsListMessage::serialize(Writer *output)
{
  this->serializeAs_CharacterStatsListMessage(output);
}

void CharacterStatsListMessage::serializeAs_CharacterStatsListMessage(Writer *output)
{
  this->stats->serializeAs_CharacterCharacteristicsInformations(output);
}

void CharacterStatsListMessage::deserialize(Reader *input)
{
  this->deserializeAs_CharacterStatsListMessage(input);
}

void CharacterStatsListMessage::deserializeAs_CharacterStatsListMessage(Reader *input)
{
  this->stats = QSharedPointer<CharacterCharacteristicsInformations>(new CharacterCharacteristicsInformations() );
  this->stats->deserialize(input);
}

void CharacterStatsListMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_CharacterStatsListMessage(tree);
}

void CharacterStatsListMessage::deserializeAsyncAs_CharacterStatsListMessage(FuncTree tree)
{
  this->_statstree = tree.addChild(std::bind(&CharacterStatsListMessage::_statstreeFunc, this, std::placeholders::_1));
}

void CharacterStatsListMessage::_statstreeFunc(Reader *input)
{
  this->stats = QSharedPointer<CharacterCharacteristicsInformations>(new CharacterCharacteristicsInformations() );
  this->stats->deserializeAsync(this->_statstree);
}

CharacterStatsListMessage::CharacterStatsListMessage()
{
  m_type = MessageEnum::CHARACTERSTATSLISTMESSAGE;
}

