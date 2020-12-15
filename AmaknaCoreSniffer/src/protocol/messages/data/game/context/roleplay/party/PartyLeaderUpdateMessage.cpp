#include "PartyLeaderUpdateMessage.h"

void PartyLeaderUpdateMessage::serialize(Writer *output)
{
  this->serializeAs_PartyLeaderUpdateMessage(output);
}

void PartyLeaderUpdateMessage::serializeAs_PartyLeaderUpdateMessage(Writer *output)
{
  AbstractPartyEventMessage::serializeAs_AbstractPartyEventMessage(output);
  if(this->partyLeaderId < 0 || this->partyLeaderId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PartyLeaderUpdateMessage -"<<"Forbidden value (" << this->partyLeaderId << ") on element partyLeaderId.";
  }
  output->writeVarLong((double)this->partyLeaderId);
}

void PartyLeaderUpdateMessage::deserialize(Reader *input)
{
  this->deserializeAs_PartyLeaderUpdateMessage(input);
}

void PartyLeaderUpdateMessage::deserializeAs_PartyLeaderUpdateMessage(Reader *input)
{
  AbstractPartyEventMessage::deserialize(input);
  this->_partyLeaderIdFunc(input);
}

void PartyLeaderUpdateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PartyLeaderUpdateMessage(tree);
}

void PartyLeaderUpdateMessage::deserializeAsyncAs_PartyLeaderUpdateMessage(FuncTree tree)
{
  AbstractPartyEventMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&PartyLeaderUpdateMessage::_partyLeaderIdFunc, this, std::placeholders::_1));
}

void PartyLeaderUpdateMessage::_partyLeaderIdFunc(Reader *input)
{
  this->partyLeaderId = input->readVarUhLong();
  if(this->partyLeaderId < 0 || this->partyLeaderId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PartyLeaderUpdateMessage -"<<"Forbidden value (" << this->partyLeaderId << ") on element of PartyLeaderUpdateMessage.partyLeaderId.";
  }
}

PartyLeaderUpdateMessage::PartyLeaderUpdateMessage()
{
  m_type = MessageEnum::PARTYLEADERUPDATEMESSAGE;
}

