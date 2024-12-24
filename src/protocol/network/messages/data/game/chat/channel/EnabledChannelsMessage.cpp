#include "EnabledChannelsMessage.h"

void EnabledChannelsMessage::serialize(Writer *output)
{
  this->serializeAs_EnabledChannelsMessage(output);
}

void EnabledChannelsMessage::serializeAs_EnabledChannelsMessage(Writer *output)
{
  output->writeShort((short)this->channels.size());
  for(uint _i1 = 0; _i1 < this->channels.size(); _i1++)
  {
    output->writeByte(this->channels[_i1]);
  }
  output->writeShort((short)this->disallowed.size());
  for(uint _i2 = 0; _i2 < this->disallowed.size(); _i2++)
  {
    output->writeByte(this->disallowed[_i2]);
  }
}

void EnabledChannelsMessage::deserialize(Reader *input)
{
  this->deserializeAs_EnabledChannelsMessage(input);
}

void EnabledChannelsMessage::deserializeAs_EnabledChannelsMessage(Reader *input)
{
  uint _val1 = 0;
  uint _val2 = 0;
  uint _channelsLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _channelsLen; _i1++)
  {
    _val1 = uint(input->readByte());
    if(_val1 < 0)
    {
      qDebug()<<"ERREUR - EnabledChannelsMessage -"<<"Forbidden value (" << _val1 << ") on elements of channels.";
    }
    this->channels.append(_val1);
  }
  uint _disallowedLen = uint(input->readUShort());
  for(uint _i2 = 0; _i2 < _disallowedLen; _i2++)
  {
    _val2 = uint(input->readByte());
    if(_val2 < 0)
    {
      qDebug()<<"ERREUR - EnabledChannelsMessage -"<<"Forbidden value (" << _val2 << ") on elements of disallowed.";
    }
    this->disallowed.append(_val2);
  }
}

void EnabledChannelsMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_EnabledChannelsMessage(tree);
}

void EnabledChannelsMessage::deserializeAsyncAs_EnabledChannelsMessage(FuncTree tree)
{
  this->_channelstree = tree.addChild(std::bind(&EnabledChannelsMessage::_channelstreeFunc, this, std::placeholders::_1));
  this->_disallowedtree = tree.addChild(std::bind(&EnabledChannelsMessage::_disallowedtreeFunc, this, std::placeholders::_1));
}

void EnabledChannelsMessage::_channelstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_channelstree.addChild(std::bind(&EnabledChannelsMessage::_channelsFunc, this, std::placeholders::_1));
  }
}

void EnabledChannelsMessage::_channelsFunc(Reader *input)
{
  uint _val = uint(input->readByte());
  if(_val < 0)
  {
    qDebug()<<"ERREUR - EnabledChannelsMessage -"<<"Forbidden value (" << _val << ") on elements of channels.";
  }
  this->channels.append(_val);
}

void EnabledChannelsMessage::_disallowedtreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_disallowedtree.addChild(std::bind(&EnabledChannelsMessage::_disallowedFunc, this, std::placeholders::_1));
  }
}

void EnabledChannelsMessage::_disallowedFunc(Reader *input)
{
  uint _val = uint(input->readByte());
  if(_val < 0)
  {
    qDebug()<<"ERREUR - EnabledChannelsMessage -"<<"Forbidden value (" << _val << ") on elements of disallowed.";
  }
  this->disallowed.append(_val);
}

EnabledChannelsMessage::EnabledChannelsMessage()
{
  m_type = MessageEnum::ENABLEDCHANNELSMESSAGE;
}

