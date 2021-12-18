#include "GuildApplicationInformation.h"

void GuildApplicationInformation::serialize(Writer *output)
{
  this->serializeAs_GuildApplicationInformation(output);
}

void GuildApplicationInformation::serializeAs_GuildApplicationInformation(Writer *output)
{
  this->playerInfo->serializeAs_ApplicationPlayerInformation(output);
  output->writeUTF(this->applyText);
  if(this->creationDate < -9.007199254740992E15 || this->creationDate > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildApplicationInformation -"<<"Forbidden value (" << this->creationDate << ") on element creationDate.";
  }
  output->writeDouble(this->creationDate);
}

void GuildApplicationInformation::deserialize(Reader *input)
{
  this->deserializeAs_GuildApplicationInformation(input);
}

void GuildApplicationInformation::deserializeAs_GuildApplicationInformation(Reader *input)
{
  this->playerInfo = QSharedPointer<ApplicationPlayerInformation>(new ApplicationPlayerInformation() );
  this->playerInfo->deserialize(input);
  this->_applyTextFunc(input);
  this->_creationDateFunc(input);
}

void GuildApplicationInformation::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildApplicationInformation(tree);
}

void GuildApplicationInformation::deserializeAsyncAs_GuildApplicationInformation(FuncTree tree)
{
  this->_playerInfotree = tree.addChild(std::bind(&GuildApplicationInformation::_playerInfotreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildApplicationInformation::_applyTextFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildApplicationInformation::_creationDateFunc, this, std::placeholders::_1));
}

void GuildApplicationInformation::_playerInfotreeFunc(Reader *input)
{
  this->playerInfo = QSharedPointer<ApplicationPlayerInformation>(new ApplicationPlayerInformation() );
  this->playerInfo->deserializeAsync(this->_playerInfotree);
}

void GuildApplicationInformation::_applyTextFunc(Reader *input)
{
  this->applyText = input->readUTF();
}

void GuildApplicationInformation::_creationDateFunc(Reader *input)
{
  this->creationDate = input->readDouble();
  if(this->creationDate < -9.007199254740992E15 || this->creationDate > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildApplicationInformation -"<<"Forbidden value (" << this->creationDate << ") on element of GuildApplicationInformation.creationDate.";
  }
}

GuildApplicationInformation::GuildApplicationInformation()
{
  m_types<<ClassEnum::GUILDAPPLICATIONINFORMATION;
}

bool GuildApplicationInformation::operator==(const GuildApplicationInformation &compared)
{
  if(playerInfo == compared.playerInfo)
  if(applyText == compared.applyText)
  if(creationDate == compared.creationDate)
  if(_playerInfotree == compared._playerInfotree)
  return true;
  
  return false;
}

