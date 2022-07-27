#include "TeleportPlayerAnswerMessage.h"

void TeleportPlayerAnswerMessage::serialize(Writer *output)
{
  this->serializeAs_TeleportPlayerAnswerMessage(output);
}

void TeleportPlayerAnswerMessage::serializeAs_TeleportPlayerAnswerMessage(Writer *output)
{
  output->writeBool(this->accept);
  if(this->requesterId < 0 || this->requesterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - TeleportPlayerAnswerMessage -"<<"Forbidden value (" << this->requesterId << ") on element requesterId.";
  }
  output->writeVarLong((double)this->requesterId);
}

void TeleportPlayerAnswerMessage::deserialize(Reader *input)
{
  this->deserializeAs_TeleportPlayerAnswerMessage(input);
}

void TeleportPlayerAnswerMessage::deserializeAs_TeleportPlayerAnswerMessage(Reader *input)
{
  this->_acceptFunc(input);
  this->_requesterIdFunc(input);
}

void TeleportPlayerAnswerMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TeleportPlayerAnswerMessage(tree);
}

void TeleportPlayerAnswerMessage::deserializeAsyncAs_TeleportPlayerAnswerMessage(FuncTree tree)
{
  tree.addChild(std::bind(&TeleportPlayerAnswerMessage::_acceptFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TeleportPlayerAnswerMessage::_requesterIdFunc, this, std::placeholders::_1));
}

void TeleportPlayerAnswerMessage::_acceptFunc(Reader *input)
{
  this->accept = input->readBool();
}

void TeleportPlayerAnswerMessage::_requesterIdFunc(Reader *input)
{
  this->requesterId = input->readVarUhLong();
  if(this->requesterId < 0 || this->requesterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - TeleportPlayerAnswerMessage -"<<"Forbidden value (" << this->requesterId << ") on element of TeleportPlayerAnswerMessage.requesterId.";
  }
}

TeleportPlayerAnswerMessage::TeleportPlayerAnswerMessage()
{
  m_type = MessageEnum::TELEPORTPLAYERANSWERMESSAGE;
}

