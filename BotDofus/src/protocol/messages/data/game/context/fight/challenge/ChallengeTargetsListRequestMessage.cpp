#include "ChallengeTargetsListRequestMessage.h"

void ChallengeTargetsListRequestMessage::serialize(Writer *output)
{
  this->serializeAs_ChallengeTargetsListRequestMessage(output);
}

void ChallengeTargetsListRequestMessage::serializeAs_ChallengeTargetsListRequestMessage(Writer *output)
{
  if(this->challengeId < 0)
  {
    qDebug()<<"ERREUR - ChallengeTargetsListRequestMessage -"<<"Forbidden value (" << this->challengeId << ") on element challengeId.";
  }
  output->writeVarShort((int)this->challengeId);
}

void ChallengeTargetsListRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_ChallengeTargetsListRequestMessage(input);
}

void ChallengeTargetsListRequestMessage::deserializeAs_ChallengeTargetsListRequestMessage(Reader *input)
{
  this->_challengeIdFunc(input);
}

void ChallengeTargetsListRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ChallengeTargetsListRequestMessage(tree);
}

void ChallengeTargetsListRequestMessage::deserializeAsyncAs_ChallengeTargetsListRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ChallengeTargetsListRequestMessage::_challengeIdFunc, this, std::placeholders::_1));
}

void ChallengeTargetsListRequestMessage::_challengeIdFunc(Reader *input)
{
  this->challengeId = input->readVarUhShort();
  if(this->challengeId < 0)
  {
    qDebug()<<"ERREUR - ChallengeTargetsListRequestMessage -"<<"Forbidden value (" << this->challengeId << ") on element of ChallengeTargetsListRequestMessage.challengeId.";
  }
}

ChallengeTargetsListRequestMessage::ChallengeTargetsListRequestMessage()
{
  m_type = MessageEnum::CHALLENGETARGETSLISTREQUESTMESSAGE;
}

