#include "GuildApplicationListenMessage.h"

void GuildApplicationListenMessage::serialize(Writer *output)
{
  this->serializeAs_GuildApplicationListenMessage(output);
}

void GuildApplicationListenMessage::serializeAs_GuildApplicationListenMessage(Writer *output)
{
  output->writeBool(this->listen);
}

void GuildApplicationListenMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildApplicationListenMessage(input);
}

void GuildApplicationListenMessage::deserializeAs_GuildApplicationListenMessage(Reader *input)
{
  this->_listenFunc(input);
}

void GuildApplicationListenMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildApplicationListenMessage(tree);
}

void GuildApplicationListenMessage::deserializeAsyncAs_GuildApplicationListenMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GuildApplicationListenMessage::_listenFunc, this, std::placeholders::_1));
}

void GuildApplicationListenMessage::_listenFunc(Reader *input)
{
  this->listen = input->readBool();
}

GuildApplicationListenMessage::GuildApplicationListenMessage()
{
  m_type = MessageEnum::GUILDAPPLICATIONLISTENMESSAGE;
}

