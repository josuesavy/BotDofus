#include "ChallengeTargetUpdateMessage.h"

void ChallengeTargetUpdateMessage::serialize(Writer *output)
{
  this->serializeAs_ChallengeTargetUpdateMessage(output);
}

void ChallengeTargetUpdateMessage::serializeAs_ChallengeTargetUpdateMessage(Writer *output)
{
  if(this->challengeId < 0)
  {
    qDebug()<<"ERREUR - ChallengeTargetUpdateMessage -"<<"Forbidden value (" << this->challengeId << ") on element challengeId.";
  }
  output->writeVarShort((int)this->challengeId);
  if(this->targetId < -9007199254740992 || this->targetId > 9007199254740992)
  {
    qDebug()<<"ERREUR - ChallengeTargetUpdateMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  output->writeDouble(this->targetId);
}

void ChallengeTargetUpdateMessage::deserialize(Reader *input)
{
  this->deserializeAs_ChallengeTargetUpdateMessage(input);
}

void ChallengeTargetUpdateMessage::deserializeAs_ChallengeTargetUpdateMessage(Reader *input)
{
  this->_challengeIdFunc(input);
  this->_targetIdFunc(input);
}

void ChallengeTargetUpdateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ChallengeTargetUpdateMessage(tree);
}

void ChallengeTargetUpdateMessage::deserializeAsyncAs_ChallengeTargetUpdateMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ChallengeTargetUpdateMessage::_challengeIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ChallengeTargetUpdateMessage::_targetIdFunc, this, std::placeholders::_1));
}

void ChallengeTargetUpdateMessage::_challengeIdFunc(Reader *input)
{
  this->challengeId = input->readVarUhShort();
  if(this->challengeId < 0)
  {
    qDebug()<<"ERREUR - ChallengeTargetUpdateMessage -"<<"Forbidden value (" << this->challengeId << ") on element of ChallengeTargetUpdateMessage.challengeId.";
  }
}

void ChallengeTargetUpdateMessage::_targetIdFunc(Reader *input)
{
  this->targetId = input->readDouble();
  if(this->targetId < -9007199254740992 || this->targetId > 9007199254740992)
  {
    qDebug()<<"ERREUR - ChallengeTargetUpdateMessage -"<<"Forbidden value (" << this->targetId << ") on element of ChallengeTargetUpdateMessage.targetId.";
  }
}

ChallengeTargetUpdateMessage::ChallengeTargetUpdateMessage()
{
  m_type = MessageEnum::CHALLENGETARGETUPDATEMESSAGE;
}

