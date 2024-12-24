#include "ChatAbstractServerMessage.h"

void ChatAbstractServerMessage::serialize(Writer *output)
{
  this->serializeAs_ChatAbstractServerMessage(output);
}

void ChatAbstractServerMessage::serializeAs_ChatAbstractServerMessage(Writer *output)
{
  output->writeByte(this->channel);
  output->writeUTF(this->content);
  if(this->timestamp < 0)
  {
    qDebug()<<"ERREUR - ChatAbstractServerMessage -"<<"Forbidden value (" << this->timestamp << ") on element timestamp.";
  }
  output->writeInt((int)this->timestamp);
  output->writeUTF(this->fingerprint);
}

void ChatAbstractServerMessage::deserialize(Reader *input)
{
  this->deserializeAs_ChatAbstractServerMessage(input);
}

void ChatAbstractServerMessage::deserializeAs_ChatAbstractServerMessage(Reader *input)
{
  this->_channelFunc(input);
  this->_contentFunc(input);
  this->_timestampFunc(input);
  this->_fingerprintFunc(input);
}

void ChatAbstractServerMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ChatAbstractServerMessage(tree);
}

void ChatAbstractServerMessage::deserializeAsyncAs_ChatAbstractServerMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ChatAbstractServerMessage::_channelFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ChatAbstractServerMessage::_contentFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ChatAbstractServerMessage::_timestampFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ChatAbstractServerMessage::_fingerprintFunc, this, std::placeholders::_1));
}

void ChatAbstractServerMessage::_channelFunc(Reader *input)
{
  this->channel = input->readByte();
  if(this->channel < 0)
  {
    qDebug()<<"ERREUR - ChatAbstractServerMessage -"<<"Forbidden value (" << this->channel << ") on element of ChatAbstractServerMessage.channel.";
  }
}

void ChatAbstractServerMessage::_contentFunc(Reader *input)
{
  this->content = input->readUTF();
}

void ChatAbstractServerMessage::_timestampFunc(Reader *input)
{
  this->timestamp = input->readInt();
  if(this->timestamp < 0)
  {
    qDebug()<<"ERREUR - ChatAbstractServerMessage -"<<"Forbidden value (" << this->timestamp << ") on element of ChatAbstractServerMessage.timestamp.";
  }
}

void ChatAbstractServerMessage::_fingerprintFunc(Reader *input)
{
  this->fingerprint = input->readUTF();
}

ChatAbstractServerMessage::ChatAbstractServerMessage()
{
  m_type = MessageEnum::CHATABSTRACTSERVERMESSAGE;
}

