#include "GroupTeleportPlayerAnswerMessage.h"

void GroupTeleportPlayerAnswerMessage::serialize(Writer *output)
{
  this->serializeAs_GroupTeleportPlayerAnswerMessage(output);
}

void GroupTeleportPlayerAnswerMessage::serializeAs_GroupTeleportPlayerAnswerMessage(Writer *output)
{
  output->writeBool(this->accept);
  if(this->requesterId < 0 || this->requesterId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GroupTeleportPlayerAnswerMessage -"<<"Forbidden value (" << this->requesterId << ") on element requesterId.";
  }
  output->writeVarLong((double)this->requesterId);
}

void GroupTeleportPlayerAnswerMessage::deserialize(Reader *input)
{
  this->deserializeAs_GroupTeleportPlayerAnswerMessage(input);
}

void GroupTeleportPlayerAnswerMessage::deserializeAs_GroupTeleportPlayerAnswerMessage(Reader *input)
{
  this->_acceptFunc(input);
  this->_requesterIdFunc(input);
}

void GroupTeleportPlayerAnswerMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GroupTeleportPlayerAnswerMessage(tree);
}

void GroupTeleportPlayerAnswerMessage::deserializeAsyncAs_GroupTeleportPlayerAnswerMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GroupTeleportPlayerAnswerMessage::_acceptFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GroupTeleportPlayerAnswerMessage::_requesterIdFunc, this, std::placeholders::_1));
}

void GroupTeleportPlayerAnswerMessage::_acceptFunc(Reader *input)
{
  this->accept = input->readBool();
}

void GroupTeleportPlayerAnswerMessage::_requesterIdFunc(Reader *input)
{
  this->requesterId = input->readVarUhLong();
  if(this->requesterId < 0 || this->requesterId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GroupTeleportPlayerAnswerMessage -"<<"Forbidden value (" << this->requesterId << ") on element of GroupTeleportPlayerAnswerMessage.requesterId.";
  }
}

GroupTeleportPlayerAnswerMessage::GroupTeleportPlayerAnswerMessage()
{
  m_type = MessageEnum::GROUPTELEPORTPLAYERANSWERMESSAGE;
}

