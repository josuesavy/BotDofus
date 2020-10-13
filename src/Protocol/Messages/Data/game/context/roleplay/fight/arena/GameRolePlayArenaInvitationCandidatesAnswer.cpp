#include "GameRolePlayArenaInvitationCandidatesAnswer.h"

void GameRolePlayArenaInvitationCandidatesAnswer::serialize(Writer *output)
{
  this->serializeAs_GameRolePlayArenaInvitationCandidatesAnswer(output);
}

void GameRolePlayArenaInvitationCandidatesAnswer::serializeAs_GameRolePlayArenaInvitationCandidatesAnswer(Writer *output)
{
  output->writeShort((short)this->candidates.size());
  for(uint _i1 = 0; _i1 < this->candidates.size(); _i1++)
  {
    (this->candidates[_i1]).serializeAs_LeagueFriendInformations(output);
  }
}

void GameRolePlayArenaInvitationCandidatesAnswer::deserialize(Reader *input)
{
  this->deserializeAs_GameRolePlayArenaInvitationCandidatesAnswer(input);
}

void GameRolePlayArenaInvitationCandidatesAnswer::deserializeAs_GameRolePlayArenaInvitationCandidatesAnswer(Reader *input)
{
  LeagueFriendInformations _item1 ;
  uint _candidatesLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _candidatesLen; _i1++)
  {
    _item1 = LeagueFriendInformations();
    _item1.deserialize(input);
    this->candidates.append(_item1);
  }
}

void GameRolePlayArenaInvitationCandidatesAnswer::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameRolePlayArenaInvitationCandidatesAnswer(tree);
}

void GameRolePlayArenaInvitationCandidatesAnswer::deserializeAsyncAs_GameRolePlayArenaInvitationCandidatesAnswer(FuncTree tree)
{
  this->_candidatestree = tree.addChild(std::bind(&GameRolePlayArenaInvitationCandidatesAnswer::_candidatestreeFunc, this, std::placeholders::_1));
}

void GameRolePlayArenaInvitationCandidatesAnswer::_candidatestreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_candidatestree.addChild(std::bind(&GameRolePlayArenaInvitationCandidatesAnswer::_candidatesFunc, this, std::placeholders::_1));
  }
}

void GameRolePlayArenaInvitationCandidatesAnswer::_candidatesFunc(Reader *input)
{
  LeagueFriendInformations _item = LeagueFriendInformations();
  _item.deserialize(input);
  this->candidates.append(_item);
}

GameRolePlayArenaInvitationCandidatesAnswer::GameRolePlayArenaInvitationCandidatesAnswer()
{
  m_type = MessageEnum::GAMEROLEPLAYARENAINVITATIONCANDIDATESANSWER;
}

