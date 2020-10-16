#include "BasicAllianceInformations.h"

void BasicAllianceInformations::serialize(Writer *output)
{
  this->serializeAs_BasicAllianceInformations(output);
}

void BasicAllianceInformations::serializeAs_BasicAllianceInformations(Writer *output)
{
  AbstractSocialGroupInfos::serializeAs_AbstractSocialGroupInfos(output);
  if(this->allianceId < 0)
  {
    qDebug()<<"ERREUR - BasicAllianceInformations -"<<"Forbidden value (" << this->allianceId << ") on element allianceId.";
  }
  output->writeVarInt((int)this->allianceId);
  output->writeUTF(this->allianceTag);
}

void BasicAllianceInformations::deserialize(Reader *input)
{
  this->deserializeAs_BasicAllianceInformations(input);
}

void BasicAllianceInformations::deserializeAs_BasicAllianceInformations(Reader *input)
{
  AbstractSocialGroupInfos::deserialize(input);
  this->_allianceIdFunc(input);
  this->_allianceTagFunc(input);
}

void BasicAllianceInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_BasicAllianceInformations(tree);
}

void BasicAllianceInformations::deserializeAsyncAs_BasicAllianceInformations(FuncTree tree)
{
  AbstractSocialGroupInfos::deserializeAsync(tree);
  tree.addChild(std::bind(&BasicAllianceInformations::_allianceIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&BasicAllianceInformations::_allianceTagFunc, this, std::placeholders::_1));
}

void BasicAllianceInformations::_allianceIdFunc(Reader *input)
{
  this->allianceId = input->readVarUhInt();
  if(this->allianceId < 0)
  {
    qDebug()<<"ERREUR - BasicAllianceInformations -"<<"Forbidden value (" << this->allianceId << ") on element of BasicAllianceInformations.allianceId.";
  }
}

void BasicAllianceInformations::_allianceTagFunc(Reader *input)
{
  this->allianceTag = input->readUTF();
}

BasicAllianceInformations::BasicAllianceInformations()
{
  m_types<<ClassEnum::BASICALLIANCEINFORMATIONS;
}

bool BasicAllianceInformations::operator==(const BasicAllianceInformations &compared)
{
  if(allianceId == compared.allianceId)
  if(allianceTag == compared.allianceTag)
  return true;
  
  return false;
}

