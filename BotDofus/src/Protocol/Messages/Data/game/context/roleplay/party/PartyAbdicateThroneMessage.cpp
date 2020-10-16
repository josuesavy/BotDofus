#include "PartyAbdicateThroneMessage.h"

void PartyAbdicateThroneMessage::serialize(Writer *output)
{
  this->serializeAs_PartyAbdicateThroneMessage(output);
}

void PartyAbdicateThroneMessage::serializeAs_PartyAbdicateThroneMessage(Writer *output)
{
  AbstractPartyMessage::serializeAs_AbstractPartyMessage(output);
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PartyAbdicateThroneMessage -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  output->writeVarLong((double)this->playerId);
}

void PartyAbdicateThroneMessage::deserialize(Reader *input)
{
  this->deserializeAs_PartyAbdicateThroneMessage(input);
}

void PartyAbdicateThroneMessage::deserializeAs_PartyAbdicateThroneMessage(Reader *input)
{
  AbstractPartyMessage::deserialize(input);
  this->_playerIdFunc(input);
}

void PartyAbdicateThroneMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PartyAbdicateThroneMessage(tree);
}

void PartyAbdicateThroneMessage::deserializeAsyncAs_PartyAbdicateThroneMessage(FuncTree tree)
{
  AbstractPartyMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&PartyAbdicateThroneMessage::_playerIdFunc, this, std::placeholders::_1));
}

void PartyAbdicateThroneMessage::_playerIdFunc(Reader *input)
{
  this->playerId = input->readVarUhLong();
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PartyAbdicateThroneMessage -"<<"Forbidden value (" << this->playerId << ") on element of PartyAbdicateThroneMessage.playerId.";
  }
}

PartyAbdicateThroneMessage::PartyAbdicateThroneMessage()
{
  m_type = MessageEnum::PARTYABDICATETHRONEMESSAGE;
}

