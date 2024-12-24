#include "ChallengeModSelectMessage.h"

void ChallengeModSelectMessage::serialize(Writer *output)
{
  this->serializeAs_ChallengeModSelectMessage(output);
}

void ChallengeModSelectMessage::serializeAs_ChallengeModSelectMessage(Writer *output)
{
  output->writeByte(this->challengeMod);
}

void ChallengeModSelectMessage::deserialize(Reader *input)
{
  this->deserializeAs_ChallengeModSelectMessage(input);
}

void ChallengeModSelectMessage::deserializeAs_ChallengeModSelectMessage(Reader *input)
{
  this->_challengeModFunc(input);
}

void ChallengeModSelectMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ChallengeModSelectMessage(tree);
}

void ChallengeModSelectMessage::deserializeAsyncAs_ChallengeModSelectMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ChallengeModSelectMessage::_challengeModFunc, this, std::placeholders::_1));
}

void ChallengeModSelectMessage::_challengeModFunc(Reader *input)
{
  this->challengeMod = input->readByte();
  if(this->challengeMod < 0)
  {
    qDebug()<<"ERREUR - ChallengeModSelectMessage -"<<"Forbidden value (" << this->challengeMod << ") on element of ChallengeModSelectMessage.challengeMod.";
  }
}

ChallengeModSelectMessage::ChallengeModSelectMessage()
{
  m_type = MessageEnum::CHALLENGEMODSELECTMESSAGE;
}

