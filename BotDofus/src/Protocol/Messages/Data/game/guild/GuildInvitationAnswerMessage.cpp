#include "GuildInvitationAnswerMessage.h"

void GuildInvitationAnswerMessage::serialize(Writer *output)
{
  this->serializeAs_GuildInvitationAnswerMessage(output);
}

void GuildInvitationAnswerMessage::serializeAs_GuildInvitationAnswerMessage(Writer *output)
{
  output->writeBool(this->accept);
}

void GuildInvitationAnswerMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildInvitationAnswerMessage(input);
}

void GuildInvitationAnswerMessage::deserializeAs_GuildInvitationAnswerMessage(Reader *input)
{
  this->_acceptFunc(input);
}

void GuildInvitationAnswerMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildInvitationAnswerMessage(tree);
}

void GuildInvitationAnswerMessage::deserializeAsyncAs_GuildInvitationAnswerMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GuildInvitationAnswerMessage::_acceptFunc, this, std::placeholders::_1));
}

void GuildInvitationAnswerMessage::_acceptFunc(Reader *input)
{
  this->accept = input->readBool();
}

GuildInvitationAnswerMessage::GuildInvitationAnswerMessage()
{
  m_type = MessageEnum::GUILDINVITATIONANSWERMESSAGE;
}

