#include "PartyInvitationMessage.h"

void PartyInvitationMessage::serialize(Writer *output)
{
  this->serializeAs_PartyInvitationMessage(output);
}

void PartyInvitationMessage::serializeAs_PartyInvitationMessage(Writer *output)
{
  AbstractPartyMessage::serializeAs_AbstractPartyMessage(output);
  output->writeByte(this->partyType);
  output->writeUTF(this->partyName);
  if(this->maxParticipants < 0)
  {
    qDebug()<<"ERREUR - PartyInvitationMessage -"<<"Forbidden value (" << this->maxParticipants << ") on element maxParticipants.";
  }
  output->writeByte(this->maxParticipants);
  if(this->fromId < 0 || this->fromId > 9007199254740992)
  {
    qDebug()<<"ERREUR - PartyInvitationMessage -"<<"Forbidden value (" << this->fromId << ") on element fromId.";
  }
  output->writeVarLong((double)this->fromId);
  output->writeUTF(this->fromName);
  if(this->toId < 0 || this->toId > 9007199254740992)
  {
    qDebug()<<"ERREUR - PartyInvitationMessage -"<<"Forbidden value (" << this->toId << ") on element toId.";
  }
  output->writeVarLong((double)this->toId);
}

void PartyInvitationMessage::deserialize(Reader *input)
{
  this->deserializeAs_PartyInvitationMessage(input);
}

void PartyInvitationMessage::deserializeAs_PartyInvitationMessage(Reader *input)
{
  AbstractPartyMessage::deserialize(input);
  this->_partyTypeFunc(input);
  this->_partyNameFunc(input);
  this->_maxParticipantsFunc(input);
  this->_fromIdFunc(input);
  this->_fromNameFunc(input);
  this->_toIdFunc(input);
}

void PartyInvitationMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PartyInvitationMessage(tree);
}

void PartyInvitationMessage::deserializeAsyncAs_PartyInvitationMessage(FuncTree tree)
{
  AbstractPartyMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&PartyInvitationMessage::_partyTypeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PartyInvitationMessage::_partyNameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PartyInvitationMessage::_maxParticipantsFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PartyInvitationMessage::_fromIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PartyInvitationMessage::_fromNameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PartyInvitationMessage::_toIdFunc, this, std::placeholders::_1));
}

void PartyInvitationMessage::_partyTypeFunc(Reader *input)
{
  this->partyType = input->readByte();
  if(this->partyType < 0)
  {
    qDebug()<<"ERREUR - PartyInvitationMessage -"<<"Forbidden value (" << this->partyType << ") on element of PartyInvitationMessage.partyType.";
  }
}

void PartyInvitationMessage::_partyNameFunc(Reader *input)
{
  this->partyName = input->readUTF();
}

void PartyInvitationMessage::_maxParticipantsFunc(Reader *input)
{
  this->maxParticipants = input->readByte();
  if(this->maxParticipants < 0)
  {
    qDebug()<<"ERREUR - PartyInvitationMessage -"<<"Forbidden value (" << this->maxParticipants << ") on element of PartyInvitationMessage.maxParticipants.";
  }
}

void PartyInvitationMessage::_fromIdFunc(Reader *input)
{
  this->fromId = input->readVarUhLong();
  if(this->fromId < 0 || this->fromId > 9007199254740992)
  {
    qDebug()<<"ERREUR - PartyInvitationMessage -"<<"Forbidden value (" << this->fromId << ") on element of PartyInvitationMessage.fromId.";
  }
}

void PartyInvitationMessage::_fromNameFunc(Reader *input)
{
  this->fromName = input->readUTF();
}

void PartyInvitationMessage::_toIdFunc(Reader *input)
{
  this->toId = input->readVarUhLong();
  if(this->toId < 0 || this->toId > 9007199254740992)
  {
    qDebug()<<"ERREUR - PartyInvitationMessage -"<<"Forbidden value (" << this->toId << ") on element of PartyInvitationMessage.toId.";
  }
}

PartyInvitationMessage::PartyInvitationMessage()
{
  m_type = MessageEnum::PARTYINVITATIONMESSAGE;
}

