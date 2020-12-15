#include "GuildModificationStartedMessage.h"

void GuildModificationStartedMessage::serialize(Writer *output)
{
  this->serializeAs_GuildModificationStartedMessage(output);
}

void GuildModificationStartedMessage::serializeAs_GuildModificationStartedMessage(Writer *output)
{
  uint _box0 = 0;
  _box0 = BooleanByteWrapper::setFlag(_box0, 0, this->canChangeName);
  _box0 = BooleanByteWrapper::setFlag(_box0, 1, this->canChangeEmblem);
  output->writeByte(_box0);
}

void GuildModificationStartedMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildModificationStartedMessage(input);
}

void GuildModificationStartedMessage::deserializeAs_GuildModificationStartedMessage(Reader *input)
{
  this->deserializeByteBoxes(input);
}

void GuildModificationStartedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildModificationStartedMessage(tree);
}

void GuildModificationStartedMessage::deserializeAsyncAs_GuildModificationStartedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GuildModificationStartedMessage::deserializeByteBoxes, this, std::placeholders::_1));
}

void GuildModificationStartedMessage::deserializeByteBoxes(Reader *input)
{
  uint _box0 = input->readByte();
  this->canChangeName = BooleanByteWrapper::getFlag(_box0, 0);
  this->canChangeEmblem = BooleanByteWrapper::getFlag(_box0, 1);
}

GuildModificationStartedMessage::GuildModificationStartedMessage()
{
  m_type = MessageEnum::GUILDMODIFICATIONSTARTEDMESSAGE;
}

