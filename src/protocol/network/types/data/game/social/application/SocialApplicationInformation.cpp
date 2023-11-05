#include "SocialApplicationInformation.h"

void SocialApplicationInformation::serialize(Writer *output)
{
  this->serializeAs_SocialApplicationInformation(output);
}

void SocialApplicationInformation::serializeAs_SocialApplicationInformation(Writer *output)
{
  this->playerInfo.serializeAs_ApplicationPlayerInformation(output);
  output->writeUTF(this->applyText);
  if(this->creationDate < -9007199254740992 || this->creationDate > 9007199254740992)
  {
    qDebug()<<"ERREUR - SocialApplicationInformation -"<<"Forbidden value (" << this->creationDate << ") on element creationDate.";
  }
  output->writeDouble(this->creationDate);
}

void SocialApplicationInformation::deserialize(Reader *input)
{
  this->deserializeAs_SocialApplicationInformation(input);
}

void SocialApplicationInformation::deserializeAs_SocialApplicationInformation(Reader *input)
{
  this->playerInfo = new com.ankamagames.dofus.network.types.game.social.application.ApplicationPlayerInformation();
  this->playerInfo.deserialize(input);
  this->_applyTextFunc(input);
  this->_creationDateFunc(input);
}

void SocialApplicationInformation::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_SocialApplicationInformation(tree);
}

void SocialApplicationInformation::deserializeAsyncAs_SocialApplicationInformation(FuncTree tree)
{
  this->_playerInfotree = tree.addChild(std::bind(&SocialApplicationInformation::_playerInfotreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&SocialApplicationInformation::_applyTextFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&SocialApplicationInformation::_creationDateFunc, this, std::placeholders::_1));
}

void SocialApplicationInformation::_playerInfotreeFunc(Reader *input)
{
  this->playerInfo = new com.ankamagames.dofus.network.types.game.social.application.ApplicationPlayerInformation();
  this->playerInfo.deserializeAsync(this->_playerInfotree);
}

void SocialApplicationInformation::_applyTextFunc(Reader *input)
{
  this->applyText = input->readUTF();
}

void SocialApplicationInformation::_creationDateFunc(Reader *input)
{
  this->creationDate = input->readDouble();
  if(this->creationDate < -9007199254740992 || this->creationDate > 9007199254740992)
  {
    qDebug()<<"ERREUR - SocialApplicationInformation -"<<"Forbidden value (" << this->creationDate << ") on element of SocialApplicationInformation.creationDate.";
  }
}

SocialApplicationInformation::SocialApplicationInformation()
{
  m_types<<ClassEnum::SOCIALAPPLICATIONINFORMATION;
}

bool SocialApplicationInformation::operator==(const SocialApplicationInformation &compared)
{
  if(playerInfo == compared.playerInfo)
  if(applyText == compared.applyText)
  if(creationDate == compared.creationDate)
  if(_playerInfotree == compared._playerInfotree)
  return true;
  
  return false;
}

