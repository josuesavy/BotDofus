#include "SurrenderVoteStartMessage.h"

void SurrenderVoteStartMessage::serialize(Writer *output)
{
  this->serializeAs_SurrenderVoteStartMessage(output);
}

void SurrenderVoteStartMessage::serializeAs_SurrenderVoteStartMessage(Writer *output)
{
  output->writeBool(this->alreadyCastedVote);
  output->writeInt((int)this->numberOfParticipants);
  output->writeInt((int)this->castedVoteNumber);
  output->writeInt((int)this->voteDuration);
}

void SurrenderVoteStartMessage::deserialize(Reader *input)
{
  this->deserializeAs_SurrenderVoteStartMessage(input);
}

void SurrenderVoteStartMessage::deserializeAs_SurrenderVoteStartMessage(Reader *input)
{
  this->_alreadyCastedVoteFunc(input);
  this->_numberOfParticipantsFunc(input);
  this->_castedVoteNumberFunc(input);
  this->_voteDurationFunc(input);
}

void SurrenderVoteStartMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_SurrenderVoteStartMessage(tree);
}

void SurrenderVoteStartMessage::deserializeAsyncAs_SurrenderVoteStartMessage(FuncTree tree)
{
  tree.addChild(std::bind(&SurrenderVoteStartMessage::_alreadyCastedVoteFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&SurrenderVoteStartMessage::_numberOfParticipantsFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&SurrenderVoteStartMessage::_castedVoteNumberFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&SurrenderVoteStartMessage::_voteDurationFunc, this, std::placeholders::_1));
}

void SurrenderVoteStartMessage::_alreadyCastedVoteFunc(Reader *input)
{
  this->alreadyCastedVote = input->readBool();
}

void SurrenderVoteStartMessage::_numberOfParticipantsFunc(Reader *input)
{
  this->numberOfParticipants = input->readInt();
}

void SurrenderVoteStartMessage::_castedVoteNumberFunc(Reader *input)
{
  this->castedVoteNumber = input->readInt();
}

void SurrenderVoteStartMessage::_voteDurationFunc(Reader *input)
{
  this->voteDuration = input->readInt();
}

SurrenderVoteStartMessage::SurrenderVoteStartMessage()
{
  m_type = MessageEnum::SURRENDERVOTESTARTMESSAGE;
}

