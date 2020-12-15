#include "GuildFightTakePlaceRequestMessage.h"

void GuildFightTakePlaceRequestMessage::serialize(Writer *output)
{
  this->serializeAs_GuildFightTakePlaceRequestMessage(output);
}

void GuildFightTakePlaceRequestMessage::serializeAs_GuildFightTakePlaceRequestMessage(Writer *output)
{
  GuildFightJoinRequestMessage::serializeAs_GuildFightJoinRequestMessage(output);
  output->writeInt((int)this->replacedCharacterId);
}

void GuildFightTakePlaceRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildFightTakePlaceRequestMessage(input);
}

void GuildFightTakePlaceRequestMessage::deserializeAs_GuildFightTakePlaceRequestMessage(Reader *input)
{
  GuildFightJoinRequestMessage::deserialize(input);
  this->_replacedCharacterIdFunc(input);
}

void GuildFightTakePlaceRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildFightTakePlaceRequestMessage(tree);
}

void GuildFightTakePlaceRequestMessage::deserializeAsyncAs_GuildFightTakePlaceRequestMessage(FuncTree tree)
{
  GuildFightJoinRequestMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&GuildFightTakePlaceRequestMessage::_replacedCharacterIdFunc, this, std::placeholders::_1));
}

void GuildFightTakePlaceRequestMessage::_replacedCharacterIdFunc(Reader *input)
{
  this->replacedCharacterId = input->readInt();
}

GuildFightTakePlaceRequestMessage::GuildFightTakePlaceRequestMessage()
{
  m_type = MessageEnum::GUILDFIGHTTAKEPLACEREQUESTMESSAGE;
}

