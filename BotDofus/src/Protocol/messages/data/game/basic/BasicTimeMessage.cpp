#include "BasicTimeMessage.h"

void BasicTimeMessage::serialize(Writer *output)
{
  this->serializeAs_BasicTimeMessage(output);
}

void BasicTimeMessage::serializeAs_BasicTimeMessage(Writer *output)
{
  if(this->timestamp < 0 || this->timestamp > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - BasicTimeMessage -"<<"Forbidden value (" << this->timestamp << ") on element timestamp.";
  }
  output->writeDouble(this->timestamp);
  output->writeShort((short)this->timezoneOffset);
}

void BasicTimeMessage::deserialize(Reader *input)
{
  this->deserializeAs_BasicTimeMessage(input);
}

void BasicTimeMessage::deserializeAs_BasicTimeMessage(Reader *input)
{
  this->_timestampFunc(input);
  this->_timezoneOffsetFunc(input);
}

void BasicTimeMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_BasicTimeMessage(tree);
}

void BasicTimeMessage::deserializeAsyncAs_BasicTimeMessage(FuncTree tree)
{
  tree.addChild(std::bind(&BasicTimeMessage::_timestampFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&BasicTimeMessage::_timezoneOffsetFunc, this, std::placeholders::_1));
}

void BasicTimeMessage::_timestampFunc(Reader *input)
{
  this->timestamp = input->readDouble();
  if(this->timestamp < 0 || this->timestamp > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - BasicTimeMessage -"<<"Forbidden value (" << this->timestamp << ") on element of BasicTimeMessage.timestamp.";
  }
}

void BasicTimeMessage::_timezoneOffsetFunc(Reader *input)
{
  this->timezoneOffset = input->readShort();
}

BasicTimeMessage::BasicTimeMessage()
{
  m_type = MessageEnum::BASICTIMEMESSAGE;
}

