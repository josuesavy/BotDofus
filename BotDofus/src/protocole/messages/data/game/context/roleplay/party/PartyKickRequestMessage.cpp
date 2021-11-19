#include "PartyKickRequestMessage.h"

void PartyKickRequestMessage::serialize(Writer *output)
{
  this->serializeAs_PartyKickRequestMessage(output);
}

void PartyKickRequestMessage::serializeAs_PartyKickRequestMessage(Writer *output)
{
  AbstractPartyMessage::serializeAs_AbstractPartyMessage(output);
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PartyKickRequestMessage -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  output->writeVarLong((double)this->playerId);
}

void PartyKickRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_PartyKickRequestMessage(input);
}

void PartyKickRequestMessage::deserializeAs_PartyKickRequestMessage(Reader *input)
{
  AbstractPartyMessage::deserialize(input);
  this->_playerIdFunc(input);
}

void PartyKickRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PartyKickRequestMessage(tree);
}

void PartyKickRequestMessage::deserializeAsyncAs_PartyKickRequestMessage(FuncTree tree)
{
  AbstractPartyMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&PartyKickRequestMessage::_playerIdFunc, this, std::placeholders::_1));
}

void PartyKickRequestMessage::_playerIdFunc(Reader *input)
{
  this->playerId = input->readVarUhLong();
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PartyKickRequestMessage -"<<"Forbidden value (" << this->playerId << ") on element of PartyKickRequestMessage.playerId.";
  }
}

PartyKickRequestMessage::PartyKickRequestMessage()
{
  m_type = MessageEnum::PARTYKICKREQUESTMESSAGE;
}

