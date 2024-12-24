#include "AllianceMemberOnlineStatusMessage.h"

void AllianceMemberOnlineStatusMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceMemberOnlineStatusMessage(output);
}

void AllianceMemberOnlineStatusMessage::serializeAs_AllianceMemberOnlineStatusMessage(Writer *output)
{
  if(this->memberId < 0 || this->memberId > 9007199254740992)
  {
    qDebug()<<"ERREUR - AllianceMemberOnlineStatusMessage -"<<"Forbidden value (" << this->memberId << ") on element memberId.";
  }
  output->writeVarLong((double)this->memberId);
  output->writeBool(this->online);
}

void AllianceMemberOnlineStatusMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceMemberOnlineStatusMessage(input);
}

void AllianceMemberOnlineStatusMessage::deserializeAs_AllianceMemberOnlineStatusMessage(Reader *input)
{
  this->_memberIdFunc(input);
  this->_onlineFunc(input);
}

void AllianceMemberOnlineStatusMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceMemberOnlineStatusMessage(tree);
}

void AllianceMemberOnlineStatusMessage::deserializeAsyncAs_AllianceMemberOnlineStatusMessage(FuncTree tree)
{
  tree.addChild(std::bind(&AllianceMemberOnlineStatusMessage::_memberIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AllianceMemberOnlineStatusMessage::_onlineFunc, this, std::placeholders::_1));
}

void AllianceMemberOnlineStatusMessage::_memberIdFunc(Reader *input)
{
  this->memberId = input->readVarUhLong();
  if(this->memberId < 0 || this->memberId > 9007199254740992)
  {
    qDebug()<<"ERREUR - AllianceMemberOnlineStatusMessage -"<<"Forbidden value (" << this->memberId << ") on element of AllianceMemberOnlineStatusMessage.memberId.";
  }
}

void AllianceMemberOnlineStatusMessage::_onlineFunc(Reader *input)
{
  this->online = input->readBool();
}

AllianceMemberOnlineStatusMessage::AllianceMemberOnlineStatusMessage()
{
  m_type = MessageEnum::ALLIANCEMEMBERONLINESTATUSMESSAGE;
}

