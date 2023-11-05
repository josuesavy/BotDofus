#include "AllianceApplicationAnswerMessage.h"

void AllianceApplicationAnswerMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceApplicationAnswerMessage(output);
}

void AllianceApplicationAnswerMessage::serializeAs_AllianceApplicationAnswerMessage(Writer *output)
{
  output->writeBool(this->accepted);
  if(this->playerId < 0 || this->playerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - AllianceApplicationAnswerMessage -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  output->writeVarLong((double)this->playerId);
}

void AllianceApplicationAnswerMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceApplicationAnswerMessage(input);
}

void AllianceApplicationAnswerMessage::deserializeAs_AllianceApplicationAnswerMessage(Reader *input)
{
  this->_acceptedFunc(input);
  this->_playerIdFunc(input);
}

void AllianceApplicationAnswerMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceApplicationAnswerMessage(tree);
}

void AllianceApplicationAnswerMessage::deserializeAsyncAs_AllianceApplicationAnswerMessage(FuncTree tree)
{
  tree.addChild(std::bind(&AllianceApplicationAnswerMessage::_acceptedFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AllianceApplicationAnswerMessage::_playerIdFunc, this, std::placeholders::_1));
}

void AllianceApplicationAnswerMessage::_acceptedFunc(Reader *input)
{
  this->accepted = input->readBool();
}

void AllianceApplicationAnswerMessage::_playerIdFunc(Reader *input)
{
  this->playerId = input->readVarUhLong();
  if(this->playerId < 0 || this->playerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - AllianceApplicationAnswerMessage -"<<"Forbidden value (" << this->playerId << ") on element of AllianceApplicationAnswerMessage.playerId.";
  }
}

AllianceApplicationAnswerMessage::AllianceApplicationAnswerMessage()
{
  m_type = MessageEnum::ALLIANCEAPPLICATIONANSWERMESSAGE;
}

