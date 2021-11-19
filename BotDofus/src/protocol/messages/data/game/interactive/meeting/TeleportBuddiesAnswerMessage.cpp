#include "TeleportBuddiesAnswerMessage.h"

void TeleportBuddiesAnswerMessage::serialize(Writer *output)
{
  this->serializeAs_TeleportBuddiesAnswerMessage(output);
}

void TeleportBuddiesAnswerMessage::serializeAs_TeleportBuddiesAnswerMessage(Writer *output)
{
  output->writeBool(this->accept);
}

void TeleportBuddiesAnswerMessage::deserialize(Reader *input)
{
  this->deserializeAs_TeleportBuddiesAnswerMessage(input);
}

void TeleportBuddiesAnswerMessage::deserializeAs_TeleportBuddiesAnswerMessage(Reader *input)
{
  this->_acceptFunc(input);
}

void TeleportBuddiesAnswerMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TeleportBuddiesAnswerMessage(tree);
}

void TeleportBuddiesAnswerMessage::deserializeAsyncAs_TeleportBuddiesAnswerMessage(FuncTree tree)
{
  tree.addChild(std::bind(&TeleportBuddiesAnswerMessage::_acceptFunc, this, std::placeholders::_1));
}

void TeleportBuddiesAnswerMessage::_acceptFunc(Reader *input)
{
  this->accept = input->readBool();
}

TeleportBuddiesAnswerMessage::TeleportBuddiesAnswerMessage()
{
  m_type = MessageEnum::TELEPORTBUDDIESANSWERMESSAGE;
}

