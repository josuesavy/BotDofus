#include "ChallengeNumberMessage.h"

void ChallengeNumberMessage::serialize(Writer *output)
{
  this->serializeAs_ChallengeNumberMessage(output);
}

void ChallengeNumberMessage::serializeAs_ChallengeNumberMessage(Writer *output)
{
  if(this->challengeNumber < 0)
  {
    qDebug()<<"ERREUR - ChallengeNumberMessage -"<<"Forbidden value (" << this->challengeNumber << ") on element challengeNumber.";
  }
  output->writeVarInt((int)this->challengeNumber);
}

void ChallengeNumberMessage::deserialize(Reader *input)
{
  this->deserializeAs_ChallengeNumberMessage(input);
}

void ChallengeNumberMessage::deserializeAs_ChallengeNumberMessage(Reader *input)
{
  this->_challengeNumberFunc(input);
}

void ChallengeNumberMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ChallengeNumberMessage(tree);
}

void ChallengeNumberMessage::deserializeAsyncAs_ChallengeNumberMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ChallengeNumberMessage::_challengeNumberFunc, this, std::placeholders::_1));
}

void ChallengeNumberMessage::_challengeNumberFunc(Reader *input)
{
  this->challengeNumber = input->readVarUhInt();
  if(this->challengeNumber < 0)
  {
    qDebug()<<"ERREUR - ChallengeNumberMessage -"<<"Forbidden value (" << this->challengeNumber << ") on element of ChallengeNumberMessage.challengeNumber.";
  }
}

ChallengeNumberMessage::ChallengeNumberMessage()
{
  m_type = MessageEnum::CHALLENGENUMBERMESSAGE;
}

