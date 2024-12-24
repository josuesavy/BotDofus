#include "ChallengeTargetsRequestMessage.h"

void ChallengeTargetsRequestMessage::serialize(Writer *output)
{
  this->serializeAs_ChallengeTargetsRequestMessage(output);
}

void ChallengeTargetsRequestMessage::serializeAs_ChallengeTargetsRequestMessage(Writer *output)
{
  if(this->challengeId < 0)
  {
    qDebug()<<"ERREUR - ChallengeTargetsRequestMessage -"<<"Forbidden value (" << this->challengeId << ") on element challengeId.";
  }
  output->writeVarInt((int)this->challengeId);
}

void ChallengeTargetsRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_ChallengeTargetsRequestMessage(input);
}

void ChallengeTargetsRequestMessage::deserializeAs_ChallengeTargetsRequestMessage(Reader *input)
{
  this->_challengeIdFunc(input);
}

void ChallengeTargetsRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ChallengeTargetsRequestMessage(tree);
}

void ChallengeTargetsRequestMessage::deserializeAsyncAs_ChallengeTargetsRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ChallengeTargetsRequestMessage::_challengeIdFunc, this, std::placeholders::_1));
}

void ChallengeTargetsRequestMessage::_challengeIdFunc(Reader *input)
{
  this->challengeId = input->readVarUhInt();
  if(this->challengeId < 0)
  {
    qDebug()<<"ERREUR - ChallengeTargetsRequestMessage -"<<"Forbidden value (" << this->challengeId << ") on element of ChallengeTargetsRequestMessage.challengeId.";
  }
}

ChallengeTargetsRequestMessage::ChallengeTargetsRequestMessage()
{
  m_type = MessageEnum::CHALLENGETARGETSREQUESTMESSAGE;
}

