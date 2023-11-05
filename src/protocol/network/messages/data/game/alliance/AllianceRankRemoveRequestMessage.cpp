#include "AllianceRankRemoveRequestMessage.h"

void AllianceRankRemoveRequestMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceRankRemoveRequestMessage(output);
}

void AllianceRankRemoveRequestMessage::serializeAs_AllianceRankRemoveRequestMessage(Writer *output)
{
  if(this->rankId < 0)
  {
    qDebug()<<"ERREUR - AllianceRankRemoveRequestMessage -"<<"Forbidden value (" << this->rankId << ") on element rankId.";
  }
  output->writeVarInt((int)this->rankId);
  if(this->newRankId < 0)
  {
    qDebug()<<"ERREUR - AllianceRankRemoveRequestMessage -"<<"Forbidden value (" << this->newRankId << ") on element newRankId.";
  }
  output->writeVarInt((int)this->newRankId);
}

void AllianceRankRemoveRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceRankRemoveRequestMessage(input);
}

void AllianceRankRemoveRequestMessage::deserializeAs_AllianceRankRemoveRequestMessage(Reader *input)
{
  this->_rankIdFunc(input);
  this->_newRankIdFunc(input);
}

void AllianceRankRemoveRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceRankRemoveRequestMessage(tree);
}

void AllianceRankRemoveRequestMessage::deserializeAsyncAs_AllianceRankRemoveRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&AllianceRankRemoveRequestMessage::_rankIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AllianceRankRemoveRequestMessage::_newRankIdFunc, this, std::placeholders::_1));
}

void AllianceRankRemoveRequestMessage::_rankIdFunc(Reader *input)
{
  this->rankId = input->readVarUhInt();
  if(this->rankId < 0)
  {
    qDebug()<<"ERREUR - AllianceRankRemoveRequestMessage -"<<"Forbidden value (" << this->rankId << ") on element of AllianceRankRemoveRequestMessage.rankId.";
  }
}

void AllianceRankRemoveRequestMessage::_newRankIdFunc(Reader *input)
{
  this->newRankId = input->readVarUhInt();
  if(this->newRankId < 0)
  {
    qDebug()<<"ERREUR - AllianceRankRemoveRequestMessage -"<<"Forbidden value (" << this->newRankId << ") on element of AllianceRankRemoveRequestMessage.newRankId.";
  }
}

AllianceRankRemoveRequestMessage::AllianceRankRemoveRequestMessage()
{
  m_type = MessageEnum::ALLIANCERANKREMOVEREQUESTMESSAGE;
}

