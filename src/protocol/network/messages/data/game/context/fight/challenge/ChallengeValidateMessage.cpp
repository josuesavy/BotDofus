#include "ChallengeValidateMessage.h"

void ChallengeValidateMessage::serialize(Writer *output)
{
  this->serializeAs_ChallengeValidateMessage(output);
}

void ChallengeValidateMessage::serializeAs_ChallengeValidateMessage(Writer *output)
{
  if(this->challengeId < 0)
  {
    qDebug()<<"ERREUR - ChallengeValidateMessage -"<<"Forbidden value (" << this->challengeId << ") on element challengeId.";
  }
  output->writeVarInt((int)this->challengeId);
}

void ChallengeValidateMessage::deserialize(Reader *input)
{
  this->deserializeAs_ChallengeValidateMessage(input);
}

void ChallengeValidateMessage::deserializeAs_ChallengeValidateMessage(Reader *input)
{
  this->_challengeIdFunc(input);
}

void ChallengeValidateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ChallengeValidateMessage(tree);
}

void ChallengeValidateMessage::deserializeAsyncAs_ChallengeValidateMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ChallengeValidateMessage::_challengeIdFunc, this, std::placeholders::_1));
}

void ChallengeValidateMessage::_challengeIdFunc(Reader *input)
{
  this->challengeId = input->readVarUhInt();
  if(this->challengeId < 0)
  {
    qDebug()<<"ERREUR - ChallengeValidateMessage -"<<"Forbidden value (" << this->challengeId << ") on element of ChallengeValidateMessage.challengeId.";
  }
}

ChallengeValidateMessage::ChallengeValidateMessage()
{
  m_type = MessageEnum::CHALLENGEVALIDATEMESSAGE;
}

