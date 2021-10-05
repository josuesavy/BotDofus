#include "AllianceInvitationAnswerMessage.h"

void AllianceInvitationAnswerMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceInvitationAnswerMessage(output);
}

void AllianceInvitationAnswerMessage::serializeAs_AllianceInvitationAnswerMessage(Writer *output)
{
  output->writeBool(this->accept);
}

void AllianceInvitationAnswerMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceInvitationAnswerMessage(input);
}

void AllianceInvitationAnswerMessage::deserializeAs_AllianceInvitationAnswerMessage(Reader *input)
{
  this->_acceptFunc(input);
}

void AllianceInvitationAnswerMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceInvitationAnswerMessage(tree);
}

void AllianceInvitationAnswerMessage::deserializeAsyncAs_AllianceInvitationAnswerMessage(FuncTree tree)
{
  tree.addChild(std::bind(&AllianceInvitationAnswerMessage::_acceptFunc, this, std::placeholders::_1));
}

void AllianceInvitationAnswerMessage::_acceptFunc(Reader *input)
{
  this->accept = input->readBool();
}

AllianceInvitationAnswerMessage::AllianceInvitationAnswerMessage()
{
  m_type = MessageEnum::ALLIANCEINVITATIONANSWERMESSAGE;
}

