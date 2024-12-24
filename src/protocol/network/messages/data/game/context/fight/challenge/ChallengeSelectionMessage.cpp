#include "ChallengeSelectionMessage.h"

void ChallengeSelectionMessage::serialize(Writer *output)
{
  this->serializeAs_ChallengeSelectionMessage(output);
}

void ChallengeSelectionMessage::serializeAs_ChallengeSelectionMessage(Writer *output)
{
  if(this->challengeId < 0)
  {
    qDebug()<<"ERREUR - ChallengeSelectionMessage -"<<"Forbidden value (" << this->challengeId << ") on element challengeId.";
  }
  output->writeVarInt((int)this->challengeId);
}

void ChallengeSelectionMessage::deserialize(Reader *input)
{
  this->deserializeAs_ChallengeSelectionMessage(input);
}

void ChallengeSelectionMessage::deserializeAs_ChallengeSelectionMessage(Reader *input)
{
  this->_challengeIdFunc(input);
}

void ChallengeSelectionMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ChallengeSelectionMessage(tree);
}

void ChallengeSelectionMessage::deserializeAsyncAs_ChallengeSelectionMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ChallengeSelectionMessage::_challengeIdFunc, this, std::placeholders::_1));
}

void ChallengeSelectionMessage::_challengeIdFunc(Reader *input)
{
  this->challengeId = input->readVarUhInt();
  if(this->challengeId < 0)
  {
    qDebug()<<"ERREUR - ChallengeSelectionMessage -"<<"Forbidden value (" << this->challengeId << ") on element of ChallengeSelectionMessage.challengeId.";
  }
}

ChallengeSelectionMessage::ChallengeSelectionMessage()
{
  m_type = MessageEnum::CHALLENGESELECTIONMESSAGE;
}

