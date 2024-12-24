#include "AllianceChangeMemberRankMessage.h"

void AllianceChangeMemberRankMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceChangeMemberRankMessage(output);
}

void AllianceChangeMemberRankMessage::serializeAs_AllianceChangeMemberRankMessage(Writer *output)
{
  if(this->memberId < 0 || this->memberId > 9007199254740992)
  {
    qDebug()<<"ERREUR - AllianceChangeMemberRankMessage -"<<"Forbidden value (" << this->memberId << ") on element memberId.";
  }
  output->writeVarLong((double)this->memberId);
  if(this->rankId < 0)
  {
    qDebug()<<"ERREUR - AllianceChangeMemberRankMessage -"<<"Forbidden value (" << this->rankId << ") on element rankId.";
  }
  output->writeVarInt((int)this->rankId);
}

void AllianceChangeMemberRankMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceChangeMemberRankMessage(input);
}

void AllianceChangeMemberRankMessage::deserializeAs_AllianceChangeMemberRankMessage(Reader *input)
{
  this->_memberIdFunc(input);
  this->_rankIdFunc(input);
}

void AllianceChangeMemberRankMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceChangeMemberRankMessage(tree);
}

void AllianceChangeMemberRankMessage::deserializeAsyncAs_AllianceChangeMemberRankMessage(FuncTree tree)
{
  tree.addChild(std::bind(&AllianceChangeMemberRankMessage::_memberIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AllianceChangeMemberRankMessage::_rankIdFunc, this, std::placeholders::_1));
}

void AllianceChangeMemberRankMessage::_memberIdFunc(Reader *input)
{
  this->memberId = input->readVarUhLong();
  if(this->memberId < 0 || this->memberId > 9007199254740992)
  {
    qDebug()<<"ERREUR - AllianceChangeMemberRankMessage -"<<"Forbidden value (" << this->memberId << ") on element of AllianceChangeMemberRankMessage.memberId.";
  }
}

void AllianceChangeMemberRankMessage::_rankIdFunc(Reader *input)
{
  this->rankId = input->readVarUhInt();
  if(this->rankId < 0)
  {
    qDebug()<<"ERREUR - AllianceChangeMemberRankMessage -"<<"Forbidden value (" << this->rankId << ") on element of AllianceChangeMemberRankMessage.rankId.";
  }
}

AllianceChangeMemberRankMessage::AllianceChangeMemberRankMessage()
{
  m_type = MessageEnum::ALLIANCECHANGEMEMBERRANKMESSAGE;
}

