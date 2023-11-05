#include "GameRolePlayArenaInvitationCandidatesAnswerMessage.h"

void GameRolePlayArenaInvitationCandidatesAnswerMessage::serialize(Writer *output)
{
  this->serializeAs_GameRolePlayArenaInvitationCandidatesAnswerMessage(output);
}

void GameRolePlayArenaInvitationCandidatesAnswerMessage::serializeAs_GameRolePlayArenaInvitationCandidatesAnswerMessage(Writer *output)
{
  output->writeShort((short)this->candidates.size());
  for(uint _i1 = 0; _i1 < this->candidates.size(); _i1++)
  {
    (this->candidates[_i1]).serializeAs_LeagueFriendInformations(output);
  }
}

void GameRolePlayArenaInvitationCandidatesAnswerMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameRolePlayArenaInvitationCandidatesAnswerMessage(input);
}

void GameRolePlayArenaInvitationCandidatesAnswerMessage::deserializeAs_GameRolePlayArenaInvitationCandidatesAnswerMessage(Reader *input)
{
  LeagueFriendInformations _item1 ;
  uint _candidatesLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _candidatesLen; _i1++)
  {
    _item1 = LeagueFriendInformations();
    _item1.deserialize(input);
    this->candidates.append(_item1);
  }
}

void GameRolePlayArenaInvitationCandidatesAnswerMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameRolePlayArenaInvitationCandidatesAnswerMessage(tree);
}

void GameRolePlayArenaInvitationCandidatesAnswerMessage::deserializeAsyncAs_GameRolePlayArenaInvitationCandidatesAnswerMessage(FuncTree tree)
{
  this->_candidatestree = tree.addChild(std::bind(&GameRolePlayArenaInvitationCandidatesAnswerMessage::_candidatestreeFunc, this, std::placeholders::_1));
}

void GameRolePlayArenaInvitationCandidatesAnswerMessage::_candidatestreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_candidatestree.addChild(std::bind(&GameRolePlayArenaInvitationCandidatesAnswerMessage::_candidatesFunc, this, std::placeholders::_1));
  }
}

void GameRolePlayArenaInvitationCandidatesAnswerMessage::_candidatesFunc(Reader *input)
{
  LeagueFriendInformations _item = LeagueFriendInformations();
  _item.deserialize(input);
  this->candidates.append(_item);
}

GameRolePlayArenaInvitationCandidatesAnswerMessage::GameRolePlayArenaInvitationCandidatesAnswerMessage()
{
  m_type = MessageEnum::GAMEROLEPLAYARENAINVITATIONCANDIDATESANSWERMESSAGE;
}

