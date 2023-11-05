#include "ChatClientMultiMessage.h"

void ChatClientMultiMessage::serialize(Writer *output)
{
  this->serializeAs_ChatClientMultiMessage(output);
}

void ChatClientMultiMessage::serializeAs_ChatClientMultiMessage(Writer *output)
{
  ChatAbstractClientMessage::serializeAs_ChatAbstractClientMessage(output);
  output->writeByte(this->channel);
}

void ChatClientMultiMessage::deserialize(Reader *input)
{
  this->deserializeAs_ChatClientMultiMessage(input);
}

void ChatClientMultiMessage::deserializeAs_ChatClientMultiMessage(Reader *input)
{
  ChatAbstractClientMessage::deserialize(input);
  this->_channelFunc(input);
}

void ChatClientMultiMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ChatClientMultiMessage(tree);
}

void ChatClientMultiMessage::deserializeAsyncAs_ChatClientMultiMessage(FuncTree tree)
{
  ChatAbstractClientMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&ChatClientMultiMessage::_channelFunc, this, std::placeholders::_1));
}

void ChatClientMultiMessage::_channelFunc(Reader *input)
{
  this->channel = input->readByte();
  if(this->channel < 0)
  {
    qDebug()<<"ERREUR - ChatClientMultiMessage -"<<"Forbidden value (" << this->channel << ") on element of ChatClientMultiMessage.channel.";
  }
}

ChatClientMultiMessage::ChatClientMultiMessage()
{
  m_type = MessageEnum::CHATCLIENTMULTIMESSAGE;
  m_needsHash = true;
}

