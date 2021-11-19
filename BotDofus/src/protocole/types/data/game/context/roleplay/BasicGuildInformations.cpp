#include "BasicGuildInformations.h"

void BasicGuildInformations::serialize(Writer *output)
{
  this->serializeAs_BasicGuildInformations(output);
}

void BasicGuildInformations::serializeAs_BasicGuildInformations(Writer *output)
{
  AbstractSocialGroupInfos::serializeAs_AbstractSocialGroupInfos(output);
  if(this->guildId < 0)
  {
    qDebug()<<"ERREUR - BasicGuildInformations -"<<"Forbidden value (" << this->guildId << ") on element guildId.";
  }
  output->writeVarInt((int)this->guildId);
  output->writeUTF(this->guildName);
  if(this->guildLevel < 0 || this->guildLevel > 200)
  {
    qDebug()<<"ERREUR - BasicGuildInformations -"<<"Forbidden value (" << this->guildLevel << ") on element guildLevel.";
  }
  output->writeByte(this->guildLevel);
}

void BasicGuildInformations::deserialize(Reader *input)
{
  this->deserializeAs_BasicGuildInformations(input);
}

void BasicGuildInformations::deserializeAs_BasicGuildInformations(Reader *input)
{
  AbstractSocialGroupInfos::deserialize(input);
  this->_guildIdFunc(input);
  this->_guildNameFunc(input);
  this->_guildLevelFunc(input);
}

void BasicGuildInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_BasicGuildInformations(tree);
}

void BasicGuildInformations::deserializeAsyncAs_BasicGuildInformations(FuncTree tree)
{
  AbstractSocialGroupInfos::deserializeAsync(tree);
  tree.addChild(std::bind(&BasicGuildInformations::_guildIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&BasicGuildInformations::_guildNameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&BasicGuildInformations::_guildLevelFunc, this, std::placeholders::_1));
}

void BasicGuildInformations::_guildIdFunc(Reader *input)
{
  this->guildId = input->readVarUhInt();
  if(this->guildId < 0)
  {
    qDebug()<<"ERREUR - BasicGuildInformations -"<<"Forbidden value (" << this->guildId << ") on element of BasicGuildInformations.guildId.";
  }
}

void BasicGuildInformations::_guildNameFunc(Reader *input)
{
  this->guildName = input->readUTF();
}

void BasicGuildInformations::_guildLevelFunc(Reader *input)
{
  this->guildLevel = input->readUByte();
  if(this->guildLevel < 0 || this->guildLevel > 200)
  {
    qDebug()<<"ERREUR - BasicGuildInformations -"<<"Forbidden value (" << this->guildLevel << ") on element of BasicGuildInformations.guildLevel.";
  }
}

BasicGuildInformations::BasicGuildInformations()
{
  m_types<<ClassEnum::BASICGUILDINFORMATIONS;
}

bool BasicGuildInformations::operator==(const BasicGuildInformations &compared)
{
  if(guildId == compared.guildId)
  if(guildName == compared.guildName)
  if(guildLevel == compared.guildLevel)
  return true;
  
  return false;
}

