#include "PartyMemberEjectedMessage.h"

void PartyMemberEjectedMessage::serialize(Writer *output)
{
  this->serializeAs_PartyMemberEjectedMessage(output);
}

void PartyMemberEjectedMessage::serializeAs_PartyMemberEjectedMessage(Writer *output)
{
  PartyMemberRemoveMessage::serializeAs_PartyMemberRemoveMessage(output);
  if(this->kickerId < 0 || this->kickerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - PartyMemberEjectedMessage -"<<"Forbidden value (" << this->kickerId << ") on element kickerId.";
  }
  output->writeVarLong((double)this->kickerId);
}

void PartyMemberEjectedMessage::deserialize(Reader *input)
{
  this->deserializeAs_PartyMemberEjectedMessage(input);
}

void PartyMemberEjectedMessage::deserializeAs_PartyMemberEjectedMessage(Reader *input)
{
  PartyMemberRemoveMessage::deserialize(input);
  this->_kickerIdFunc(input);
}

void PartyMemberEjectedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PartyMemberEjectedMessage(tree);
}

void PartyMemberEjectedMessage::deserializeAsyncAs_PartyMemberEjectedMessage(FuncTree tree)
{
  PartyMemberRemoveMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&PartyMemberEjectedMessage::_kickerIdFunc, this, std::placeholders::_1));
}

void PartyMemberEjectedMessage::_kickerIdFunc(Reader *input)
{
  this->kickerId = input->readVarUhLong();
  if(this->kickerId < 0 || this->kickerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - PartyMemberEjectedMessage -"<<"Forbidden value (" << this->kickerId << ") on element of PartyMemberEjectedMessage.kickerId.";
  }
}

PartyMemberEjectedMessage::PartyMemberEjectedMessage()
{
  m_type = MessageEnum::PARTYMEMBEREJECTEDMESSAGE;
}

