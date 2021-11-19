#include "AllianceInvitedMessage.h"

void AllianceInvitedMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceInvitedMessage(output);
}

void AllianceInvitedMessage::serializeAs_AllianceInvitedMessage(Writer *output)
{
  if(this->recruterId < 0 || this->recruterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - AllianceInvitedMessage -"<<"Forbidden value (" << this->recruterId << ") on element recruterId.";
  }
  output->writeVarLong((double)this->recruterId);
  output->writeUTF(this->recruterName);
  this->allianceInfo->serializeAs_BasicNamedAllianceInformations(output);
}

void AllianceInvitedMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceInvitedMessage(input);
}

void AllianceInvitedMessage::deserializeAs_AllianceInvitedMessage(Reader *input)
{
  this->_recruterIdFunc(input);
  this->_recruterNameFunc(input);
  this->allianceInfo = QSharedPointer<BasicNamedAllianceInformations>(new BasicNamedAllianceInformations() );
  this->allianceInfo->deserialize(input);
}

void AllianceInvitedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceInvitedMessage(tree);
}

void AllianceInvitedMessage::deserializeAsyncAs_AllianceInvitedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&AllianceInvitedMessage::_recruterIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AllianceInvitedMessage::_recruterNameFunc, this, std::placeholders::_1));
  this->_allianceInfotree = tree.addChild(std::bind(&AllianceInvitedMessage::_allianceInfotreeFunc, this, std::placeholders::_1));
}

void AllianceInvitedMessage::_recruterIdFunc(Reader *input)
{
  this->recruterId = input->readVarUhLong();
  if(this->recruterId < 0 || this->recruterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - AllianceInvitedMessage -"<<"Forbidden value (" << this->recruterId << ") on element of AllianceInvitedMessage.recruterId.";
  }
}

void AllianceInvitedMessage::_recruterNameFunc(Reader *input)
{
  this->recruterName = input->readUTF();
}

void AllianceInvitedMessage::_allianceInfotreeFunc(Reader *input)
{
  this->allianceInfo = QSharedPointer<BasicNamedAllianceInformations>(new BasicNamedAllianceInformations() );
  this->allianceInfo->deserializeAsync(this->_allianceInfotree);
}

AllianceInvitedMessage::AllianceInvitedMessage()
{
  m_type = MessageEnum::ALLIANCEINVITEDMESSAGE;
}

