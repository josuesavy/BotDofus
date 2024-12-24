#include "ChallengeResultMessage.h"

void ChallengeResultMessage::serialize(Writer *output)
{
  this->serializeAs_ChallengeResultMessage(output);
}

void ChallengeResultMessage::serializeAs_ChallengeResultMessage(Writer *output)
{
  if(this->challengeId < 0)
  {
    qDebug()<<"ERREUR - ChallengeResultMessage -"<<"Forbidden value (" << this->challengeId << ") on element challengeId.";
  }
  output->writeVarInt((int)this->challengeId);
  output->writeBool(this->success);
}

void ChallengeResultMessage::deserialize(Reader *input)
{
  this->deserializeAs_ChallengeResultMessage(input);
}

void ChallengeResultMessage::deserializeAs_ChallengeResultMessage(Reader *input)
{
  this->_challengeIdFunc(input);
  this->_successFunc(input);
}

void ChallengeResultMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ChallengeResultMessage(tree);
}

void ChallengeResultMessage::deserializeAsyncAs_ChallengeResultMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ChallengeResultMessage::_challengeIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ChallengeResultMessage::_successFunc, this, std::placeholders::_1));
}

void ChallengeResultMessage::_challengeIdFunc(Reader *input)
{
  this->challengeId = input->readVarUhInt();
  if(this->challengeId < 0)
  {
    qDebug()<<"ERREUR - ChallengeResultMessage -"<<"Forbidden value (" << this->challengeId << ") on element of ChallengeResultMessage.challengeId.";
  }
}

void ChallengeResultMessage::_successFunc(Reader *input)
{
  this->success = input->readBool();
}

ChallengeResultMessage::ChallengeResultMessage()
{
  m_type = MessageEnum::CHALLENGERESULTMESSAGE;
}

