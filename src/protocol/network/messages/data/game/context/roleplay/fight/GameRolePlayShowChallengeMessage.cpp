#include "GameRolePlayShowChallengeMessage.h"

void GameRolePlayShowChallengeMessage::serialize(Writer *output)
{
  this->serializeAs_GameRolePlayShowChallengeMessage(output);
}

void GameRolePlayShowChallengeMessage::serializeAs_GameRolePlayShowChallengeMessage(Writer *output)
{
  this->commonsInfos->serializeAs_FightCommonInformations(output);
}

void GameRolePlayShowChallengeMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameRolePlayShowChallengeMessage(input);
}

void GameRolePlayShowChallengeMessage::deserializeAs_GameRolePlayShowChallengeMessage(Reader *input)
{
  this->commonsInfos = QSharedPointer<FightCommonInformations>(new FightCommonInformations() );
  this->commonsInfos->deserialize(input);
}

void GameRolePlayShowChallengeMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameRolePlayShowChallengeMessage(tree);
}

void GameRolePlayShowChallengeMessage::deserializeAsyncAs_GameRolePlayShowChallengeMessage(FuncTree tree)
{
  this->_commonsInfostree = tree.addChild(std::bind(&GameRolePlayShowChallengeMessage::_commonsInfostreeFunc, this, std::placeholders::_1));
}

void GameRolePlayShowChallengeMessage::_commonsInfostreeFunc(Reader *input)
{
  this->commonsInfos = QSharedPointer<FightCommonInformations>(new FightCommonInformations() );
  this->commonsInfos->deserializeAsync(this->_commonsInfostree);
}

GameRolePlayShowChallengeMessage::GameRolePlayShowChallengeMessage()
{
  m_type = MessageEnum::GAMEROLEPLAYSHOWCHALLENGEMESSAGE;
}

