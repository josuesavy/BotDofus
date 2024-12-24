#include "AllianceMemberLeavingMessage.h"

void AllianceMemberLeavingMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceMemberLeavingMessage(output);
}

void AllianceMemberLeavingMessage::serializeAs_AllianceMemberLeavingMessage(Writer *output)
{
  output->writeBool(this->kicked);
  if(this->memberId < 0 || this->memberId > 9007199254740992)
  {
    qDebug()<<"ERREUR - AllianceMemberLeavingMessage -"<<"Forbidden value (" << this->memberId << ") on element memberId.";
  }
  output->writeVarLong((double)this->memberId);
}

void AllianceMemberLeavingMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceMemberLeavingMessage(input);
}

void AllianceMemberLeavingMessage::deserializeAs_AllianceMemberLeavingMessage(Reader *input)
{
  this->_kickedFunc(input);
  this->_memberIdFunc(input);
}

void AllianceMemberLeavingMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceMemberLeavingMessage(tree);
}

void AllianceMemberLeavingMessage::deserializeAsyncAs_AllianceMemberLeavingMessage(FuncTree tree)
{
  tree.addChild(std::bind(&AllianceMemberLeavingMessage::_kickedFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AllianceMemberLeavingMessage::_memberIdFunc, this, std::placeholders::_1));
}

void AllianceMemberLeavingMessage::_kickedFunc(Reader *input)
{
  this->kicked = input->readBool();
}

void AllianceMemberLeavingMessage::_memberIdFunc(Reader *input)
{
  this->memberId = input->readVarUhLong();
  if(this->memberId < 0 || this->memberId > 9007199254740992)
  {
    qDebug()<<"ERREUR - AllianceMemberLeavingMessage -"<<"Forbidden value (" << this->memberId << ") on element of AllianceMemberLeavingMessage.memberId.";
  }
}

AllianceMemberLeavingMessage::AllianceMemberLeavingMessage()
{
  m_type = MessageEnum::ALLIANCEMEMBERLEAVINGMESSAGE;
}

