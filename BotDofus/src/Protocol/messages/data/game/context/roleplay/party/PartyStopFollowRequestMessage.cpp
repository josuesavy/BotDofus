#include "PartyStopFollowRequestMessage.h"

void PartyStopFollowRequestMessage::serialize(Writer *output)
{
  this->serializeAs_PartyStopFollowRequestMessage(output);
}

void PartyStopFollowRequestMessage::serializeAs_PartyStopFollowRequestMessage(Writer *output)
{
  AbstractPartyMessage::serializeAs_AbstractPartyMessage(output);
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PartyStopFollowRequestMessage -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  output->writeVarLong((double)this->playerId);
}

void PartyStopFollowRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_PartyStopFollowRequestMessage(input);
}

void PartyStopFollowRequestMessage::deserializeAs_PartyStopFollowRequestMessage(Reader *input)
{
  AbstractPartyMessage::deserialize(input);
  this->_playerIdFunc(input);
}

void PartyStopFollowRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PartyStopFollowRequestMessage(tree);
}

void PartyStopFollowRequestMessage::deserializeAsyncAs_PartyStopFollowRequestMessage(FuncTree tree)
{
  AbstractPartyMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&PartyStopFollowRequestMessage::_playerIdFunc, this, std::placeholders::_1));
}

void PartyStopFollowRequestMessage::_playerIdFunc(Reader *input)
{
  this->playerId = input->readVarUhLong();
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PartyStopFollowRequestMessage -"<<"Forbidden value (" << this->playerId << ") on element of PartyStopFollowRequestMessage.playerId.";
  }
}

PartyStopFollowRequestMessage::PartyStopFollowRequestMessage()
{
  m_type = MessageEnum::PARTYSTOPFOLLOWREQUESTMESSAGE;
}

