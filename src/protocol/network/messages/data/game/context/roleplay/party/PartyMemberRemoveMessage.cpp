#include "PartyMemberRemoveMessage.h"

void PartyMemberRemoveMessage::serialize(Writer *output)
{
  this->serializeAs_PartyMemberRemoveMessage(output);
}

void PartyMemberRemoveMessage::serializeAs_PartyMemberRemoveMessage(Writer *output)
{
  AbstractPartyEventMessage::serializeAs_AbstractPartyEventMessage(output);
  if(this->leavingPlayerId < 0 || this->leavingPlayerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - PartyMemberRemoveMessage -"<<"Forbidden value (" << this->leavingPlayerId << ") on element leavingPlayerId.";
  }
  output->writeVarLong((double)this->leavingPlayerId);
}

void PartyMemberRemoveMessage::deserialize(Reader *input)
{
  this->deserializeAs_PartyMemberRemoveMessage(input);
}

void PartyMemberRemoveMessage::deserializeAs_PartyMemberRemoveMessage(Reader *input)
{
  AbstractPartyEventMessage::deserialize(input);
  this->_leavingPlayerIdFunc(input);
}

void PartyMemberRemoveMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PartyMemberRemoveMessage(tree);
}

void PartyMemberRemoveMessage::deserializeAsyncAs_PartyMemberRemoveMessage(FuncTree tree)
{
  AbstractPartyEventMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&PartyMemberRemoveMessage::_leavingPlayerIdFunc, this, std::placeholders::_1));
}

void PartyMemberRemoveMessage::_leavingPlayerIdFunc(Reader *input)
{
  this->leavingPlayerId = input->readVarUhLong();
  if(this->leavingPlayerId < 0 || this->leavingPlayerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - PartyMemberRemoveMessage -"<<"Forbidden value (" << this->leavingPlayerId << ") on element of PartyMemberRemoveMessage.leavingPlayerId.";
  }
}

PartyMemberRemoveMessage::PartyMemberRemoveMessage()
{
  m_type = MessageEnum::PARTYMEMBERREMOVEMESSAGE;
}

