#include "SurrenderStateMessage.h"

void SurrenderStateMessage::serialize(Writer *output)
{
  this->serializeAs_SurrenderStateMessage(output);
}

void SurrenderStateMessage::serializeAs_SurrenderStateMessage(Writer *output)
{
  uint _box0 = 0;
  _box0 = BooleanByteWrapper::setFlag(_box0, 0, this->canSurrender);
  _box0 = BooleanByteWrapper::setFlag(_box0, 1, this->permitVote);
  output->writeByte(_box0);
}

void SurrenderStateMessage::deserialize(Reader *input)
{
  this->deserializeAs_SurrenderStateMessage(input);
}

void SurrenderStateMessage::deserializeAs_SurrenderStateMessage(Reader *input)
{
  this->deserializeByteBoxes(input);
}

void SurrenderStateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_SurrenderStateMessage(tree);
}

void SurrenderStateMessage::deserializeAsyncAs_SurrenderStateMessage(FuncTree tree)
{
  tree.addChild(std::bind(&SurrenderStateMessage::deserializeByteBoxes, this, std::placeholders::_1));
}

void SurrenderStateMessage::deserializeByteBoxes(Reader *input)
{
  uint _box0 = uint(input->readByte());
  this->canSurrender = BooleanByteWrapper::getFlag(_box0, 0);
  this->permitVote = BooleanByteWrapper::getFlag(_box0, 1);
}

SurrenderStateMessage::SurrenderStateMessage()
{
  m_type = MessageEnum::SURRENDERSTATEMESSAGE;
}

