#include "PartyInvitationDungeonMessage.h"

void PartyInvitationDungeonMessage::serialize(Writer *output)
{
  this->serializeAs_PartyInvitationDungeonMessage(output);
}

void PartyInvitationDungeonMessage::serializeAs_PartyInvitationDungeonMessage(Writer *output)
{
  PartyInvitationMessage::serializeAs_PartyInvitationMessage(output);
  if(this->dungeonId < 0)
  {
    qDebug()<<"ERREUR - PartyInvitationDungeonMessage -"<<"Forbidden value (" << this->dungeonId << ") on element dungeonId.";
  }
  output->writeVarShort((int)this->dungeonId);
}

void PartyInvitationDungeonMessage::deserialize(Reader *input)
{
  this->deserializeAs_PartyInvitationDungeonMessage(input);
}

void PartyInvitationDungeonMessage::deserializeAs_PartyInvitationDungeonMessage(Reader *input)
{
  PartyInvitationMessage::deserialize(input);
  this->_dungeonIdFunc(input);
}

void PartyInvitationDungeonMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PartyInvitationDungeonMessage(tree);
}

void PartyInvitationDungeonMessage::deserializeAsyncAs_PartyInvitationDungeonMessage(FuncTree tree)
{
  PartyInvitationMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&PartyInvitationDungeonMessage::_dungeonIdFunc, this, std::placeholders::_1));
}

void PartyInvitationDungeonMessage::_dungeonIdFunc(Reader *input)
{
  this->dungeonId = input->readVarUhShort();
  if(this->dungeonId < 0)
  {
    qDebug()<<"ERREUR - PartyInvitationDungeonMessage -"<<"Forbidden value (" << this->dungeonId << ") on element of PartyInvitationDungeonMessage.dungeonId.";
  }
}

PartyInvitationDungeonMessage::PartyInvitationDungeonMessage()
{
  m_type = MessageEnum::PARTYINVITATIONDUNGEONMESSAGE;
}

