#include "ChallengeAddMessage.h"

void ChallengeAddMessage::serialize(Writer *output)
{
  this->serializeAs_ChallengeAddMessage(output);
}

void ChallengeAddMessage::serializeAs_ChallengeAddMessage(Writer *output)
{
  this->challengeInformation->serializeAs_ChallengeInformation(output);
}

void ChallengeAddMessage::deserialize(Reader *input)
{
  this->deserializeAs_ChallengeAddMessage(input);
}

void ChallengeAddMessage::deserializeAs_ChallengeAddMessage(Reader *input)
{
  this->challengeInformation = QSharedPointer<ChallengeInformation>(new ChallengeInformation() );
  this->challengeInformation->deserialize(input);
}

void ChallengeAddMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ChallengeAddMessage(tree);
}

void ChallengeAddMessage::deserializeAsyncAs_ChallengeAddMessage(FuncTree tree)
{
  this->_challengeInformationtree = tree.addChild(std::bind(&ChallengeAddMessage::_challengeInformationtreeFunc, this, std::placeholders::_1));
}

void ChallengeAddMessage::_challengeInformationtreeFunc(Reader *input)
{
  this->challengeInformation = QSharedPointer<ChallengeInformation>(new ChallengeInformation() );
  this->challengeInformation->deserializeAsync(this->_challengeInformationtree);
}

ChallengeAddMessage::ChallengeAddMessage()
{
  m_type = MessageEnum::CHALLENGEADDMESSAGE;
}

