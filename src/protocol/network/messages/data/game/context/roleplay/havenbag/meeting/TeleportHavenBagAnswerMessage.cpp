#include "TeleportHavenBagAnswerMessage.h"

void TeleportHavenBagAnswerMessage::serialize(Writer *output)
{
  this->serializeAs_TeleportHavenBagAnswerMessage(output);
}

void TeleportHavenBagAnswerMessage::serializeAs_TeleportHavenBagAnswerMessage(Writer *output)
{
  output->writeBool(this->accept);
}

void TeleportHavenBagAnswerMessage::deserialize(Reader *input)
{
  this->deserializeAs_TeleportHavenBagAnswerMessage(input);
}

void TeleportHavenBagAnswerMessage::deserializeAs_TeleportHavenBagAnswerMessage(Reader *input)
{
  this->_acceptFunc(input);
}

void TeleportHavenBagAnswerMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TeleportHavenBagAnswerMessage(tree);
}

void TeleportHavenBagAnswerMessage::deserializeAsyncAs_TeleportHavenBagAnswerMessage(FuncTree tree)
{
  tree.addChild(std::bind(&TeleportHavenBagAnswerMessage::_acceptFunc, this, std::placeholders::_1));
}

void TeleportHavenBagAnswerMessage::_acceptFunc(Reader *input)
{
  this->accept = input->readBool();
}

TeleportHavenBagAnswerMessage::TeleportHavenBagAnswerMessage()
{
  m_type = MessageEnum::TELEPORTHAVENBAGANSWERMESSAGE;
}

