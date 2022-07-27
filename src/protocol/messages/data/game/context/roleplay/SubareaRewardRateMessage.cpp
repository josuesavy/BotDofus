#include "SubareaRewardRateMessage.h"

void SubareaRewardRateMessage::serialize(Writer *output)
{
  this->serializeAs_SubareaRewardRateMessage(output);
}

void SubareaRewardRateMessage::serializeAs_SubareaRewardRateMessage(Writer *output)
{
  output->writeVarShort((int)this->subAreaRate);
}

void SubareaRewardRateMessage::deserialize(Reader *input)
{
  this->deserializeAs_SubareaRewardRateMessage(input);
}

void SubareaRewardRateMessage::deserializeAs_SubareaRewardRateMessage(Reader *input)
{
  this->_subAreaRateFunc(input);
}

void SubareaRewardRateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_SubareaRewardRateMessage(tree);
}

void SubareaRewardRateMessage::deserializeAsyncAs_SubareaRewardRateMessage(FuncTree tree)
{
  tree.addChild(std::bind(&SubareaRewardRateMessage::_subAreaRateFunc, this, std::placeholders::_1));
}

void SubareaRewardRateMessage::_subAreaRateFunc(Reader *input)
{
  this->subAreaRate = input->readVarShort();
}

SubareaRewardRateMessage::SubareaRewardRateMessage()
{
  m_type = MessageEnum::SUBAREAREWARDRATEMESSAGE;
}

