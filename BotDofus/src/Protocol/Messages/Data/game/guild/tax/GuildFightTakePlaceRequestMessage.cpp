#include "GuildFightTakePlaceRequestMessage.h"

void GuildFightTakePlaceRequestMessage::serialize(Writer *output)
{
  this->serializeAs_GuildFightTakePlaceRequestMessage(output);
}

void GuildFightTakePlaceRequestMessage::serializeAs_GuildFightTakePlaceRequestMessage(Writer *output)
{
  GuildFightJoinRequestMessage::serializeAs_GuildFightJoinRequestMessage(output);
  if(this->replacedCharacterId < 0 || this->replacedCharacterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildFightTakePlaceRequestMessage -"<<"Forbidden value (" << this->replacedCharacterId << ") on element replacedCharacterId.";
  }
  output->writeVarLong((double)this->replacedCharacterId);
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
  this->replacedCharacterId = input->readVarUhLong();
  if(this->replacedCharacterId < 0 || this->replacedCharacterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildFightTakePlaceRequestMessage -"<<"Forbidden value (" << this->replacedCharacterId << ") on element of GuildFightTakePlaceRequestMessage.replacedCharacterId.";
  }
}

GuildFightTakePlaceRequestMessage::GuildFightTakePlaceRequestMessage()
{
  m_type = MessageEnum::GUILDFIGHTTAKEPLACEREQUESTMESSAGE;
}

