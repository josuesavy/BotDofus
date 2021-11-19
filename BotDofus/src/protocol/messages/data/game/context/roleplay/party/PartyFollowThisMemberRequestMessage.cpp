#include "PartyFollowThisMemberRequestMessage.h"

void PartyFollowThisMemberRequestMessage::serialize(Writer *output)
{
  this->serializeAs_PartyFollowThisMemberRequestMessage(output);
}

void PartyFollowThisMemberRequestMessage::serializeAs_PartyFollowThisMemberRequestMessage(Writer *output)
{
  PartyFollowMemberRequestMessage::serializeAs_PartyFollowMemberRequestMessage(output);
  output->writeBool(this->enabled);
}

void PartyFollowThisMemberRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_PartyFollowThisMemberRequestMessage(input);
}

void PartyFollowThisMemberRequestMessage::deserializeAs_PartyFollowThisMemberRequestMessage(Reader *input)
{
  PartyFollowMemberRequestMessage::deserialize(input);
  this->_enabledFunc(input);
}

void PartyFollowThisMemberRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PartyFollowThisMemberRequestMessage(tree);
}

void PartyFollowThisMemberRequestMessage::deserializeAsyncAs_PartyFollowThisMemberRequestMessage(FuncTree tree)
{
  PartyFollowMemberRequestMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&PartyFollowThisMemberRequestMessage::_enabledFunc, this, std::placeholders::_1));
}

void PartyFollowThisMemberRequestMessage::_enabledFunc(Reader *input)
{
  this->enabled = input->readBool();
}

PartyFollowThisMemberRequestMessage::PartyFollowThisMemberRequestMessage()
{
  m_type = MessageEnum::PARTYFOLLOWTHISMEMBERREQUESTMESSAGE;
}

