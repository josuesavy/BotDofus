#include "ReloginTokenStatusMessage.h"

void ReloginTokenStatusMessage::serialize(Writer *output)
{
  this->serializeAs_ReloginTokenStatusMessage(output);
}

void ReloginTokenStatusMessage::serializeAs_ReloginTokenStatusMessage(Writer *output)
{
  output->writeBool(this->validToken);
  output->writeVarInt((int)this->ticket.size());
  for(uint _i2 = 0; _i2 < this->ticket.size(); _i2++)
  {
    output->writeByte(this->ticket[_i2]);
  }
}

void ReloginTokenStatusMessage::deserialize(Reader *input)
{
  this->deserializeAs_ReloginTokenStatusMessage(input);
}

void ReloginTokenStatusMessage::deserializeAs_ReloginTokenStatusMessage(Reader *input)
{
  auto _val2 = 0;
  this->_validTokenFunc(input);
  uint _ticketLen = input->readVarInt();
  for(uint _i2 = 0; _i2 < _ticketLen; _i2++)
  {
    _val2 = input->readByte();
    this->ticket.append(_val2);
  }
}

void ReloginTokenStatusMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ReloginTokenStatusMessage(tree);
}

void ReloginTokenStatusMessage::deserializeAsyncAs_ReloginTokenStatusMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ReloginTokenStatusMessage::_validTokenFunc, this, std::placeholders::_1));
  this->_tickettree = tree.addChild(std::bind(&ReloginTokenStatusMessage::_tickettreeFunc, this, std::placeholders::_1));
}

void ReloginTokenStatusMessage::_validTokenFunc(Reader *input)
{
  this->validToken = input->readBool();
}

void ReloginTokenStatusMessage::_tickettreeFunc(Reader *input)
{
  uint length = input->readVarInt();
  for(uint i = 0; i < length; i++)
  {
    this->_tickettree.addChild(std::bind(&ReloginTokenStatusMessage::_ticketFunc, this, std::placeholders::_1));
  }
}

void ReloginTokenStatusMessage::_ticketFunc(Reader *input)
{
  int _val = input->readByte();
  this->ticket.append(_val);
}

ReloginTokenStatusMessage::ReloginTokenStatusMessage()
{
  m_type = MessageEnum::RELOGINTOKENSTATUSMESSAGE;
}

