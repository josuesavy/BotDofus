#include "PartyFollowMemberRequestMessage.h"

void PartyFollowMemberRequestMessage::serialize(Writer *output)
{
  this->serializeAs_PartyFollowMemberRequestMessage(output);
}

void PartyFollowMemberRequestMessage::serializeAs_PartyFollowMemberRequestMessage(Writer *output)
{
  AbstractPartyMessage::serializeAs_AbstractPartyMessage(output);
  if(this->playerId < 0 || this->playerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - PartyFollowMemberRequestMessage -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  output->writeVarLong((double)this->playerId);
}

void PartyFollowMemberRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_PartyFollowMemberRequestMessage(input);
}

void PartyFollowMemberRequestMessage::deserializeAs_PartyFollowMemberRequestMessage(Reader *input)
{
  AbstractPartyMessage::deserialize(input);
  this->_playerIdFunc(input);
}

void PartyFollowMemberRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PartyFollowMemberRequestMessage(tree);
}

void PartyFollowMemberRequestMessage::deserializeAsyncAs_PartyFollowMemberRequestMessage(FuncTree tree)
{
  AbstractPartyMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&PartyFollowMemberRequestMessage::_playerIdFunc, this, std::placeholders::_1));
}

void PartyFollowMemberRequestMessage::_playerIdFunc(Reader *input)
{
  this->playerId = input->readVarUhLong();
  if(this->playerId < 0 || this->playerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - PartyFollowMemberRequestMessage -"<<"Forbidden value (" << this->playerId << ") on element of PartyFollowMemberRequestMessage.playerId.";
  }
}

PartyFollowMemberRequestMessage::PartyFollowMemberRequestMessage()
{
  m_type = MessageEnum::PARTYFOLLOWMEMBERREQUESTMESSAGE;
}

