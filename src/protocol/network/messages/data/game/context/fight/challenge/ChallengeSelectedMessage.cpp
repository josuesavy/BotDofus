#include "ChallengeSelectedMessage.h"

void ChallengeSelectedMessage::serialize(Writer *output)
{
  this->serializeAs_ChallengeSelectedMessage(output);
}

void ChallengeSelectedMessage::serializeAs_ChallengeSelectedMessage(Writer *output)
{
  this->challengeInformation->serializeAs_ChallengeInformation(output);
}

void ChallengeSelectedMessage::deserialize(Reader *input)
{
  this->deserializeAs_ChallengeSelectedMessage(input);
}

void ChallengeSelectedMessage::deserializeAs_ChallengeSelectedMessage(Reader *input)
{
  this->challengeInformation = QSharedPointer<ChallengeInformation>(new ChallengeInformation() );
  this->challengeInformation->deserialize(input);
}

void ChallengeSelectedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ChallengeSelectedMessage(tree);
}

void ChallengeSelectedMessage::deserializeAsyncAs_ChallengeSelectedMessage(FuncTree tree)
{
  this->_challengeInformationtree = tree.addChild(std::bind(&ChallengeSelectedMessage::_challengeInformationtreeFunc, this, std::placeholders::_1));
}

void ChallengeSelectedMessage::_challengeInformationtreeFunc(Reader *input)
{
  this->challengeInformation = QSharedPointer<ChallengeInformation>(new ChallengeInformation() );
  this->challengeInformation->deserializeAsync(this->_challengeInformationtree);
}

ChallengeSelectedMessage::ChallengeSelectedMessage()
{
  m_type = MessageEnum::CHALLENGESELECTEDMESSAGE;
}

