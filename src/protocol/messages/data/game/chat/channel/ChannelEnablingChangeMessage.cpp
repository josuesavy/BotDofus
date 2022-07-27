#include "ChannelEnablingChangeMessage.h"

void ChannelEnablingChangeMessage::serialize(Writer *output)
{
  this->serializeAs_ChannelEnablingChangeMessage(output);
}

void ChannelEnablingChangeMessage::serializeAs_ChannelEnablingChangeMessage(Writer *output)
{
  output->writeByte(this->channel);
  output->writeBool(this->enable);
}

void ChannelEnablingChangeMessage::deserialize(Reader *input)
{
  this->deserializeAs_ChannelEnablingChangeMessage(input);
}

void ChannelEnablingChangeMessage::deserializeAs_ChannelEnablingChangeMessage(Reader *input)
{
  this->_channelFunc(input);
  this->_enableFunc(input);
}

void ChannelEnablingChangeMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ChannelEnablingChangeMessage(tree);
}

void ChannelEnablingChangeMessage::deserializeAsyncAs_ChannelEnablingChangeMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ChannelEnablingChangeMessage::_channelFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ChannelEnablingChangeMessage::_enableFunc, this, std::placeholders::_1));
}

void ChannelEnablingChangeMessage::_channelFunc(Reader *input)
{
  this->channel = input->readByte();
  if(this->channel < 0)
  {
    qDebug()<<"ERREUR - ChannelEnablingChangeMessage -"<<"Forbidden value (" << this->channel << ") on element of ChannelEnablingChangeMessage.channel.";
  }
}

void ChannelEnablingChangeMessage::_enableFunc(Reader *input)
{
  this->enable = input->readBool();
}

ChannelEnablingChangeMessage::ChannelEnablingChangeMessage()
{
  m_type = MessageEnum::CHANNELENABLINGCHANGEMESSAGE;
}

