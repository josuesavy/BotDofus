#include "PartyMemberInStandardFightMessage.h"

void PartyMemberInStandardFightMessage::serialize(Writer *output)
{
  this->serializeAs_PartyMemberInStandardFightMessage(output);
}

void PartyMemberInStandardFightMessage::serializeAs_PartyMemberInStandardFightMessage(Writer *output)
{
  AbstractPartyMemberInFightMessage::serializeAs_AbstractPartyMemberInFightMessage(output);
  this->fightMap->serializeAs_MapCoordinatesExtended(output);
}

void PartyMemberInStandardFightMessage::deserialize(Reader *input)
{
  this->deserializeAs_PartyMemberInStandardFightMessage(input);
}

void PartyMemberInStandardFightMessage::deserializeAs_PartyMemberInStandardFightMessage(Reader *input)
{
  AbstractPartyMemberInFightMessage::deserialize(input);
  this->fightMap = QSharedPointer<MapCoordinatesExtended>(new MapCoordinatesExtended() );
  this->fightMap->deserialize(input);
}

void PartyMemberInStandardFightMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PartyMemberInStandardFightMessage(tree);
}

void PartyMemberInStandardFightMessage::deserializeAsyncAs_PartyMemberInStandardFightMessage(FuncTree tree)
{
  AbstractPartyMemberInFightMessage::deserializeAsync(tree);
  this->_fightMaptree = tree.addChild(std::bind(&PartyMemberInStandardFightMessage::_fightMaptreeFunc, this, std::placeholders::_1));
}

void PartyMemberInStandardFightMessage::_fightMaptreeFunc(Reader *input)
{
  this->fightMap = QSharedPointer<MapCoordinatesExtended>(new MapCoordinatesExtended() );
  this->fightMap->deserializeAsync(this->_fightMaptree);
}

PartyMemberInStandardFightMessage::PartyMemberInStandardFightMessage()
{
  m_type = MessageEnum::PARTYMEMBERINSTANDARDFIGHTMESSAGE;
}

