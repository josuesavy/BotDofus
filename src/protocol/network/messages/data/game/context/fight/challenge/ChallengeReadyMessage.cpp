#include "ChallengeReadyMessage.h"

void ChallengeReadyMessage::serialize(Writer *output)
{
  this->serializeAs_ChallengeReadyMessage(output);
}

void ChallengeReadyMessage::serializeAs_ChallengeReadyMessage(Writer *output)
{
  output->writeByte(this->challengeMod);
}

void ChallengeReadyMessage::deserialize(Reader *input)
{
  this->deserializeAs_ChallengeReadyMessage(input);
}

void ChallengeReadyMessage::deserializeAs_ChallengeReadyMessage(Reader *input)
{
  this->_challengeModFunc(input);
}

void ChallengeReadyMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ChallengeReadyMessage(tree);
}

void ChallengeReadyMessage::deserializeAsyncAs_ChallengeReadyMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ChallengeReadyMessage::_challengeModFunc, this, std::placeholders::_1));
}

void ChallengeReadyMessage::_challengeModFunc(Reader *input)
{
  this->challengeMod = input->readByte();
  if(this->challengeMod < 0)
  {
    qDebug()<<"ERREUR - ChallengeReadyMessage -"<<"Forbidden value (" << this->challengeMod << ") on element of ChallengeReadyMessage.challengeMod.";
  }
}

ChallengeReadyMessage::ChallengeReadyMessage()
{
  m_type = MessageEnum::CHALLENGEREADYMESSAGE;
}

