#include "AlmanachCalendarDateMessage.h"

void AlmanachCalendarDateMessage::serialize(Writer *output)
{
  this->serializeAs_AlmanachCalendarDateMessage(output);
}

void AlmanachCalendarDateMessage::serializeAs_AlmanachCalendarDateMessage(Writer *output)
{
  output->writeInt((int)this->date);
}

void AlmanachCalendarDateMessage::deserialize(Reader *input)
{
  this->deserializeAs_AlmanachCalendarDateMessage(input);
}

void AlmanachCalendarDateMessage::deserializeAs_AlmanachCalendarDateMessage(Reader *input)
{
  this->_dateFunc(input);
}

void AlmanachCalendarDateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AlmanachCalendarDateMessage(tree);
}

void AlmanachCalendarDateMessage::deserializeAsyncAs_AlmanachCalendarDateMessage(FuncTree tree)
{
  tree.addChild(std::bind(&AlmanachCalendarDateMessage::_dateFunc, this, std::placeholders::_1));
}

void AlmanachCalendarDateMessage::_dateFunc(Reader *input)
{
  this->date = input->readInt();
}

AlmanachCalendarDateMessage::AlmanachCalendarDateMessage()
{
  m_type = MessageEnum::ALMANACHCALENDARDATEMESSAGE;
}

