#include "PartyInvitationDungeonDetailsMessage.h"

void PartyInvitationDungeonDetailsMessage::serialize(Writer *output)
{
  this->serializeAs_PartyInvitationDungeonDetailsMessage(output);
}

void PartyInvitationDungeonDetailsMessage::serializeAs_PartyInvitationDungeonDetailsMessage(Writer *output)
{
  PartyInvitationDetailsMessage::serializeAs_PartyInvitationDetailsMessage(output);
  if(this->dungeonId < 0)
  {
    qDebug()<<"ERREUR - PartyInvitationDungeonDetailsMessage -"<<"Forbidden value (" << this->dungeonId << ") on element dungeonId.";
  }
  output->writeVarShort((int)this->dungeonId);
  output->writeShort((short)this->playersDungeonReady.size());
  for(uint _i2 = 0; _i2 < this->playersDungeonReady.size(); _i2++)
  {
    output->writeBool(this->playersDungeonReady[_i2]);
  }
}

void PartyInvitationDungeonDetailsMessage::deserialize(Reader *input)
{
  this->deserializeAs_PartyInvitationDungeonDetailsMessage(input);
}

void PartyInvitationDungeonDetailsMessage::deserializeAs_PartyInvitationDungeonDetailsMessage(Reader *input)
{
  auto _val2 = false;
  PartyInvitationDetailsMessage::deserialize(input);
  this->_dungeonIdFunc(input);
  uint _playersDungeonReadyLen = input->readUShort();
  for(uint _i2 = 0; _i2 < _playersDungeonReadyLen; _i2++)
  {
    _val2 = input->readBool();
    this->playersDungeonReady.append(_val2);
  }
}

void PartyInvitationDungeonDetailsMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PartyInvitationDungeonDetailsMessage(tree);
}

void PartyInvitationDungeonDetailsMessage::deserializeAsyncAs_PartyInvitationDungeonDetailsMessage(FuncTree tree)
{
  PartyInvitationDetailsMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&PartyInvitationDungeonDetailsMessage::_dungeonIdFunc, this, std::placeholders::_1));
  this->_playersDungeonReadytree = tree.addChild(std::bind(&PartyInvitationDungeonDetailsMessage::_playersDungeonReadytreeFunc, this, std::placeholders::_1));
}

void PartyInvitationDungeonDetailsMessage::_dungeonIdFunc(Reader *input)
{
  this->dungeonId = input->readVarUhShort();
  if(this->dungeonId < 0)
  {
    qDebug()<<"ERREUR - PartyInvitationDungeonDetailsMessage -"<<"Forbidden value (" << this->dungeonId << ") on element of PartyInvitationDungeonDetailsMessage.dungeonId.";
  }
}

void PartyInvitationDungeonDetailsMessage::_playersDungeonReadytreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_playersDungeonReadytree.addChild(std::bind(&PartyInvitationDungeonDetailsMessage::_playersDungeonReadyFunc, this, std::placeholders::_1));
  }
}

void PartyInvitationDungeonDetailsMessage::_playersDungeonReadyFunc(Reader *input)
{
  bool _val = input->readBool();
  this->playersDungeonReady.append(_val);
}

PartyInvitationDungeonDetailsMessage::PartyInvitationDungeonDetailsMessage()
{
  m_type = MessageEnum::PARTYINVITATIONDUNGEONDETAILSMESSAGE;
}

