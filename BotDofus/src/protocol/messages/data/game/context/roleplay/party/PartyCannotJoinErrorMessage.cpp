#include "PartyCannotJoinErrorMessage.h"

void PartyCannotJoinErrorMessage::serialize(Writer *output)
{
  this->serializeAs_PartyCannotJoinErrorMessage(output);
}

void PartyCannotJoinErrorMessage::serializeAs_PartyCannotJoinErrorMessage(Writer *output)
{
  AbstractPartyMessage::serializeAs_AbstractPartyMessage(output);
  output->writeByte(this->reason);
}

void PartyCannotJoinErrorMessage::deserialize(Reader *input)
{
  this->deserializeAs_PartyCannotJoinErrorMessage(input);
}

void PartyCannotJoinErrorMessage::deserializeAs_PartyCannotJoinErrorMessage(Reader *input)
{
  AbstractPartyMessage::deserialize(input);
  this->_reasonFunc(input);
}

void PartyCannotJoinErrorMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PartyCannotJoinErrorMessage(tree);
}

void PartyCannotJoinErrorMessage::deserializeAsyncAs_PartyCannotJoinErrorMessage(FuncTree tree)
{
  AbstractPartyMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&PartyCannotJoinErrorMessage::_reasonFunc, this, std::placeholders::_1));
}

void PartyCannotJoinErrorMessage::_reasonFunc(Reader *input)
{
  this->reason = input->readByte();
  if(this->reason < 0)
  {
    qDebug()<<"ERREUR - PartyCannotJoinErrorMessage -"<<"Forbidden value (" << this->reason << ") on element of PartyCannotJoinErrorMessage.reason.";
  }
}

PartyCannotJoinErrorMessage::PartyCannotJoinErrorMessage()
{
  m_type = MessageEnum::PARTYCANNOTJOINERRORMESSAGE;
}

