#include "AllianceListApplicationModifiedMessage.h"

void AllianceListApplicationModifiedMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceListApplicationModifiedMessage(output);
}

void AllianceListApplicationModifiedMessage::serializeAs_AllianceListApplicationModifiedMessage(Writer *output)
{
  this->apply.serializeAs_SocialApplicationInformation(output);
  output->writeByte(this->state);
  if(this->playerId < 0 || this->playerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - AllianceListApplicationModifiedMessage -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  output->writeVarLong((double)this->playerId);
}

void AllianceListApplicationModifiedMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceListApplicationModifiedMessage(input);
}

void AllianceListApplicationModifiedMessage::deserializeAs_AllianceListApplicationModifiedMessage(Reader *input)
{
  this->apply = SocialApplicationInformation();
  this->apply.deserialize(input);
  this->_stateFunc(input);
  this->_playerIdFunc(input);
}

void AllianceListApplicationModifiedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceListApplicationModifiedMessage(tree);
}

void AllianceListApplicationModifiedMessage::deserializeAsyncAs_AllianceListApplicationModifiedMessage(FuncTree tree)
{
  this->_applytree = tree.addChild(std::bind(&AllianceListApplicationModifiedMessage::_applytreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AllianceListApplicationModifiedMessage::_stateFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AllianceListApplicationModifiedMessage::_playerIdFunc, this, std::placeholders::_1));
}

void AllianceListApplicationModifiedMessage::_applytreeFunc(Reader *input)
{
  this->apply = SocialApplicationInformation();
  this->apply.deserializeAsync(this->_applytree);
}

void AllianceListApplicationModifiedMessage::_stateFunc(Reader *input)
{
  this->state = input->readByte();
  if(this->state < 0)
  {
    qDebug()<<"ERREUR - AllianceListApplicationModifiedMessage -"<<"Forbidden value (" << this->state << ") on element of AllianceListApplicationModifiedMessage.state.";
  }
}

void AllianceListApplicationModifiedMessage::_playerIdFunc(Reader *input)
{
  this->playerId = input->readVarUhLong();
  if(this->playerId < 0 || this->playerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - AllianceListApplicationModifiedMessage -"<<"Forbidden value (" << this->playerId << ") on element of AllianceListApplicationModifiedMessage.playerId.";
  }
}

AllianceListApplicationModifiedMessage::AllianceListApplicationModifiedMessage()
{
  m_type = MessageEnum::ALLIANCELISTAPPLICATIONMODIFIEDMESSAGE;
}

