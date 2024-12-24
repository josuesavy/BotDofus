#include "PartyKickedByMessage.h"

void PartyKickedByMessage::serialize(Writer *output)
{
  this->serializeAs_PartyKickedByMessage(output);
}

void PartyKickedByMessage::serializeAs_PartyKickedByMessage(Writer *output)
{
  AbstractPartyMessage::serializeAs_AbstractPartyMessage(output);
  if(this->kickerId < 0 || this->kickerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - PartyKickedByMessage -"<<"Forbidden value (" << this->kickerId << ") on element kickerId.";
  }
  output->writeVarLong((double)this->kickerId);
}

void PartyKickedByMessage::deserialize(Reader *input)
{
  this->deserializeAs_PartyKickedByMessage(input);
}

void PartyKickedByMessage::deserializeAs_PartyKickedByMessage(Reader *input)
{
  AbstractPartyMessage::deserialize(input);
  this->_kickerIdFunc(input);
}

void PartyKickedByMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PartyKickedByMessage(tree);
}

void PartyKickedByMessage::deserializeAsyncAs_PartyKickedByMessage(FuncTree tree)
{
  AbstractPartyMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&PartyKickedByMessage::_kickerIdFunc, this, std::placeholders::_1));
}

void PartyKickedByMessage::_kickerIdFunc(Reader *input)
{
  this->kickerId = input->readVarUhLong();
  if(this->kickerId < 0 || this->kickerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - PartyKickedByMessage -"<<"Forbidden value (" << this->kickerId << ") on element of PartyKickedByMessage.kickerId.";
  }
}

PartyKickedByMessage::PartyKickedByMessage()
{
  m_type = MessageEnum::PARTYKICKEDBYMESSAGE;
}

