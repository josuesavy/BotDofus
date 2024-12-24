#include "RawDataMessage.h"

void RawDataMessage::serialize(Writer *output)
{
  this->serializeAs_RawDataMessage(output);
}

void RawDataMessage::serializeAs_RawDataMessage(Writer *output)
{
  output->writeVarInt((int)this->content.size());
  for(uint _i1 = 0; _i1 < this->content.size(); _i1++)
  {
    output->writeByte(this->content[_i1]);
  }
}

void RawDataMessage::deserialize(Reader *input)
{
  this->deserializeAs_RawDataMessage(input);
}

void RawDataMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_RawDataMessage(tree);
}

void RawDataMessage::deserializeAs_RawDataMessage(Reader *input)
{
  uint _contentLen = uint(input->readVarInt());
  this->content = input->readBytes();
}

void RawDataMessage::deserializeAsyncAs_RawDataMessage(FuncTree tree)
{
  tree.addChild(std::bind(&RawDataMessage::deserializeAs_RawDataMessage, this, std::placeholders::_1));
}

RawDataMessage::RawDataMessage()
{
  m_type = MessageEnum::RAWDATAMESSAGE;
}

