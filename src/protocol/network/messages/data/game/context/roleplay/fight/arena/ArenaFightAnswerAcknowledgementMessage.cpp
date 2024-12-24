#include "ArenaFightAnswerAcknowledgementMessage.h"

void ArenaFightAnswerAcknowledgementMessage::serialize(Writer *output)
{
  this->serializeAs_ArenaFightAnswerAcknowledgementMessage(output);
}

void ArenaFightAnswerAcknowledgementMessage::serializeAs_ArenaFightAnswerAcknowledgementMessage(Writer *output)
{
  output->writeBool(this->acknowledged);
}

void ArenaFightAnswerAcknowledgementMessage::deserialize(Reader *input)
{
  this->deserializeAs_ArenaFightAnswerAcknowledgementMessage(input);
}

void ArenaFightAnswerAcknowledgementMessage::deserializeAs_ArenaFightAnswerAcknowledgementMessage(Reader *input)
{
  this->_acknowledgedFunc(input);
}

void ArenaFightAnswerAcknowledgementMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ArenaFightAnswerAcknowledgementMessage(tree);
}

void ArenaFightAnswerAcknowledgementMessage::deserializeAsyncAs_ArenaFightAnswerAcknowledgementMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ArenaFightAnswerAcknowledgementMessage::_acknowledgedFunc, this, std::placeholders::_1));
}

void ArenaFightAnswerAcknowledgementMessage::_acknowledgedFunc(Reader *input)
{
  this->acknowledged = input->readBool();
}

ArenaFightAnswerAcknowledgementMessage::ArenaFightAnswerAcknowledgementMessage()
{
  m_type = MessageEnum::ARENAFIGHTANSWERACKNOWLEDGEMENTMESSAGE;
}

