#include "ChannelEnablingMessage.h"

void ChannelEnablingMessage::serialize(Writer *output)
{
  this->serializeAs_ChannelEnablingMessage(output);
}

void ChannelEnablingMessage::serializeAs_ChannelEnablingMessage(Writer *output)
{
  output->writeByte(this->channel);
  output->writeBool(this->enable);
}

void ChannelEnablingMessage::deserialize(Reader *input)
{
  this->deserializeAs_ChannelEnablingMessage(input);
}

void ChannelEnablingMessage::deserializeAs_ChannelEnablingMessage(Reader *input)
{
  this->_channelFunc(input);
  this->_enableFunc(input);
}

void ChannelEnablingMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ChannelEnablingMessage(tree);
}

void ChannelEnablingMessage::deserializeAsyncAs_ChannelEnablingMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ChannelEnablingMessage::_channelFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ChannelEnablingMessage::_enableFunc, this, std::placeholders::_1));
}

void ChannelEnablingMessage::_channelFunc(Reader *input)
{
  this->channel = input->readByte();
  if(this->channel < 0)
  {
    qDebug()<<"ERREUR - ChannelEnablingMessage -"<<"Forbidden value (" << this->channel << ") on element of ChannelEnablingMessage.channel.";
  }
}

void ChannelEnablingMessage::_enableFunc(Reader *input)
{
  this->enable = input->readBool();
}

ChannelEnablingMessage::ChannelEnablingMessage()
{
  m_type = MessageEnum::CHANNELENABLINGMESSAGE;
}

