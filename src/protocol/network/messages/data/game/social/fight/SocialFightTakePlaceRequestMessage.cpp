#include "SocialFightTakePlaceRequestMessage.h"

void SocialFightTakePlaceRequestMessage::serialize(Writer *output)
{
  this->serializeAs_SocialFightTakePlaceRequestMessage(output);
}

void SocialFightTakePlaceRequestMessage::serializeAs_SocialFightTakePlaceRequestMessage(Writer *output)
{
  this->socialFightInfo.serializeAs_SocialFightInfo(output);
  if(this->replacedCharacterId < 0 || this->replacedCharacterId > 9007199254740992)
  {
    qDebug()<<"ERREUR - SocialFightTakePlaceRequestMessage -"<<"Forbidden value (" << this->replacedCharacterId << ") on element replacedCharacterId.";
  }
  output->writeVarLong((double)this->replacedCharacterId);
}

void SocialFightTakePlaceRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_SocialFightTakePlaceRequestMessage(input);
}

void SocialFightTakePlaceRequestMessage::deserializeAs_SocialFightTakePlaceRequestMessage(Reader *input)
{
  this->socialFightInfo = SocialFightInfo();
  this->socialFightInfo.deserialize(input);
  this->_replacedCharacterIdFunc(input);
}

void SocialFightTakePlaceRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_SocialFightTakePlaceRequestMessage(tree);
}

void SocialFightTakePlaceRequestMessage::deserializeAsyncAs_SocialFightTakePlaceRequestMessage(FuncTree tree)
{
  this->_socialFightInfotree = tree.addChild(std::bind(&SocialFightTakePlaceRequestMessage::_socialFightInfotreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&SocialFightTakePlaceRequestMessage::_replacedCharacterIdFunc, this, std::placeholders::_1));
}

void SocialFightTakePlaceRequestMessage::_socialFightInfotreeFunc(Reader *input)
{
  this->socialFightInfo = SocialFightInfo();
  this->socialFightInfo.deserializeAsync(this->_socialFightInfotree);
}

void SocialFightTakePlaceRequestMessage::_replacedCharacterIdFunc(Reader *input)
{
  this->replacedCharacterId = input->readVarUhLong();
  if(this->replacedCharacterId < 0 || this->replacedCharacterId > 9007199254740992)
  {
    qDebug()<<"ERREUR - SocialFightTakePlaceRequestMessage -"<<"Forbidden value (" << this->replacedCharacterId << ") on element of SocialFightTakePlaceRequestMessage.replacedCharacterId.";
  }
}

SocialFightTakePlaceRequestMessage::SocialFightTakePlaceRequestMessage()
{
  m_type = MessageEnum::SOCIALFIGHTTAKEPLACEREQUESTMESSAGE;
}

