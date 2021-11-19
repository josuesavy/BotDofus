#include "GuildInformationsMemberUpdateMessage.h"

void GuildInformationsMemberUpdateMessage::serialize(Writer *output)
{
  this->serializeAs_GuildInformationsMemberUpdateMessage(output);
}

void GuildInformationsMemberUpdateMessage::serializeAs_GuildInformationsMemberUpdateMessage(Writer *output)
{
  this->member->serializeAs_GuildMember(output);
}

void GuildInformationsMemberUpdateMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildInformationsMemberUpdateMessage(input);
}

void GuildInformationsMemberUpdateMessage::deserializeAs_GuildInformationsMemberUpdateMessage(Reader *input)
{
  this->member = QSharedPointer<GuildMember>(new GuildMember() );
  this->member->deserialize(input);
}

void GuildInformationsMemberUpdateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildInformationsMemberUpdateMessage(tree);
}

void GuildInformationsMemberUpdateMessage::deserializeAsyncAs_GuildInformationsMemberUpdateMessage(FuncTree tree)
{
  this->_membertree = tree.addChild(std::bind(&GuildInformationsMemberUpdateMessage::_membertreeFunc, this, std::placeholders::_1));
}

void GuildInformationsMemberUpdateMessage::_membertreeFunc(Reader *input)
{
  this->member = QSharedPointer<GuildMember>(new GuildMember() );
  this->member->deserializeAsync(this->_membertree);
}

GuildInformationsMemberUpdateMessage::GuildInformationsMemberUpdateMessage()
{
  m_type = MessageEnum::GUILDINFORMATIONSMEMBERUPDATEMESSAGE;
}

