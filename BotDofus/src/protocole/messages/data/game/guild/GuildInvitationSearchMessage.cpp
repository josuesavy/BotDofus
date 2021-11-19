#include "GuildInvitationSearchMessage.h"

void GuildInvitationSearchMessage::serialize(Writer *output)
{
  this->serializeAs_GuildInvitationSearchMessage(output);
}

void GuildInvitationSearchMessage::serializeAs_GuildInvitationSearchMessage(Writer *output)
{
  output->writeShort((short)this->target->getTypes().last());
  this->target->serialize(output);
}

void GuildInvitationSearchMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildInvitationSearchMessage(input);
}

void GuildInvitationSearchMessage::deserializeAs_GuildInvitationSearchMessage(Reader *input)
{
  uint _id1 = input->readUShort();
  this->target = qSharedPointerCast<AbstractPlayerSearchInformation>(ClassManagerSingleton::get()->getClass(_id1));
  this->target->deserialize(input);
}

void GuildInvitationSearchMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildInvitationSearchMessage(tree);
}

void GuildInvitationSearchMessage::deserializeAsyncAs_GuildInvitationSearchMessage(FuncTree tree)
{
  this->_targettree = tree.addChild(std::bind(&GuildInvitationSearchMessage::_targettreeFunc, this, std::placeholders::_1));
}

void GuildInvitationSearchMessage::_targettreeFunc(Reader *input)
{
  uint _id = input->readUShort();
  this->target = qSharedPointerCast<AbstractPlayerSearchInformation>(ClassManagerSingleton::get()->getClass(_id));
  this->target->deserializeAsync(this->_targettree);
}

GuildInvitationSearchMessage::GuildInvitationSearchMessage()
{
  m_type = MessageEnum::GUILDINVITATIONSEARCHMESSAGE;
}

