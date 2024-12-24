#include "ChallengeTargetsMessage.h"

void ChallengeTargetsMessage::serialize(Writer *output)
{
  this->serializeAs_ChallengeTargetsMessage(output);
}

void ChallengeTargetsMessage::serializeAs_ChallengeTargetsMessage(Writer *output)
{
  this->challengeInformation->serializeAs_ChallengeInformation(output);
}

void ChallengeTargetsMessage::deserialize(Reader *input)
{
  this->deserializeAs_ChallengeTargetsMessage(input);
}

void ChallengeTargetsMessage::deserializeAs_ChallengeTargetsMessage(Reader *input)
{
  this->challengeInformation = QSharedPointer<ChallengeInformation>(new ChallengeInformation() );
  this->challengeInformation->deserialize(input);
}

void ChallengeTargetsMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ChallengeTargetsMessage(tree);
}

void ChallengeTargetsMessage::deserializeAsyncAs_ChallengeTargetsMessage(FuncTree tree)
{
  this->_challengeInformationtree = tree.addChild(std::bind(&ChallengeTargetsMessage::_challengeInformationtreeFunc, this, std::placeholders::_1));
}

void ChallengeTargetsMessage::_challengeInformationtreeFunc(Reader *input)
{
  this->challengeInformation = QSharedPointer<ChallengeInformation>(new ChallengeInformation() );
  this->challengeInformation->deserializeAsync(this->_challengeInformationtree);
}

ChallengeTargetsMessage::ChallengeTargetsMessage()
{
  m_type = MessageEnum::CHALLENGETARGETSMESSAGE;
}

