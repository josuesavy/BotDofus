#include "ChallengeModSelectedMessage.h"

void ChallengeModSelectedMessage::serialize(Writer *output)
{
  this->serializeAs_ChallengeModSelectedMessage(output);
}

void ChallengeModSelectedMessage::serializeAs_ChallengeModSelectedMessage(Writer *output)
{
  output->writeByte(this->challengeMod);
}

void ChallengeModSelectedMessage::deserialize(Reader *input)
{
  this->deserializeAs_ChallengeModSelectedMessage(input);
}

void ChallengeModSelectedMessage::deserializeAs_ChallengeModSelectedMessage(Reader *input)
{
  this->_challengeModFunc(input);
}

void ChallengeModSelectedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ChallengeModSelectedMessage(tree);
}

void ChallengeModSelectedMessage::deserializeAsyncAs_ChallengeModSelectedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ChallengeModSelectedMessage::_challengeModFunc, this, std::placeholders::_1));
}

void ChallengeModSelectedMessage::_challengeModFunc(Reader *input)
{
  this->challengeMod = input->readByte();
  if(this->challengeMod < 0)
  {
    qDebug()<<"ERREUR - ChallengeModSelectedMessage -"<<"Forbidden value (" << this->challengeMod << ") on element of ChallengeModSelectedMessage.challengeMod.";
  }
}

ChallengeModSelectedMessage::ChallengeModSelectedMessage()
{
  m_type = MessageEnum::CHALLENGEMODSELECTEDMESSAGE;
}

