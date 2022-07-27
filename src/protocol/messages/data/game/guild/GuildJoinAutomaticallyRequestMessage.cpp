#include "GuildJoinAutomaticallyRequestMessage.h"

void GuildJoinAutomaticallyRequestMessage::serialize(Writer *output)
{
  this->serializeAs_GuildJoinAutomaticallyRequestMessage(output);
}

void GuildJoinAutomaticallyRequestMessage::serializeAs_GuildJoinAutomaticallyRequestMessage(Writer *output)
{
  output->writeInt((int)this->guildId);
}

void GuildJoinAutomaticallyRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildJoinAutomaticallyRequestMessage(input);
}

void GuildJoinAutomaticallyRequestMessage::deserializeAs_GuildJoinAutomaticallyRequestMessage(Reader *input)
{
  this->_guildIdFunc(input);
}

void GuildJoinAutomaticallyRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildJoinAutomaticallyRequestMessage(tree);
}

void GuildJoinAutomaticallyRequestMessage::deserializeAsyncAs_GuildJoinAutomaticallyRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GuildJoinAutomaticallyRequestMessage::_guildIdFunc, this, std::placeholders::_1));
}

void GuildJoinAutomaticallyRequestMessage::_guildIdFunc(Reader *input)
{
  this->guildId = input->readInt();
}

GuildJoinAutomaticallyRequestMessage::GuildJoinAutomaticallyRequestMessage()
{
  m_type = MessageEnum::GUILDJOINAUTOMATICALLYREQUESTMESSAGE;
}

