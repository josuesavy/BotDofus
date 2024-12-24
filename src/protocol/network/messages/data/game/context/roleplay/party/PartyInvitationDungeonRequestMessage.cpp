#include "PartyInvitationDungeonRequestMessage.h"

void PartyInvitationDungeonRequestMessage::serialize(Writer *output)
{
  this->serializeAs_PartyInvitationDungeonRequestMessage(output);
}

void PartyInvitationDungeonRequestMessage::serializeAs_PartyInvitationDungeonRequestMessage(Writer *output)
{
  PartyInvitationRequestMessage::serializeAs_PartyInvitationRequestMessage(output);
  if(this->dungeonId < 0)
  {
    qDebug()<<"ERREUR - PartyInvitationDungeonRequestMessage -"<<"Forbidden value (" << this->dungeonId << ") on element dungeonId.";
  }
  output->writeVarShort((int)this->dungeonId);
}

void PartyInvitationDungeonRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_PartyInvitationDungeonRequestMessage(input);
}

void PartyInvitationDungeonRequestMessage::deserializeAs_PartyInvitationDungeonRequestMessage(Reader *input)
{
  PartyInvitationRequestMessage::deserialize(input);
  this->_dungeonIdFunc(input);
}

void PartyInvitationDungeonRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PartyInvitationDungeonRequestMessage(tree);
}

void PartyInvitationDungeonRequestMessage::deserializeAsyncAs_PartyInvitationDungeonRequestMessage(FuncTree tree)
{
  PartyInvitationRequestMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&PartyInvitationDungeonRequestMessage::_dungeonIdFunc, this, std::placeholders::_1));
}

void PartyInvitationDungeonRequestMessage::_dungeonIdFunc(Reader *input)
{
  this->dungeonId = input->readVarUhShort();
  if(this->dungeonId < 0)
  {
    qDebug()<<"ERREUR - PartyInvitationDungeonRequestMessage -"<<"Forbidden value (" << this->dungeonId << ") on element of PartyInvitationDungeonRequestMessage.dungeonId.";
  }
}

PartyInvitationDungeonRequestMessage::PartyInvitationDungeonRequestMessage()
{
  m_type = MessageEnum::PARTYINVITATIONDUNGEONREQUESTMESSAGE;
  m_needsHash = true;
}

