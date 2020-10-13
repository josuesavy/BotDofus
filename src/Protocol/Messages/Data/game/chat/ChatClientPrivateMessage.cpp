#include "ChatClientPrivateMessage.h"

void ChatClientPrivateMessage::serialize(Writer *output)
{
  this->serializeAs_ChatClientPrivateMessage(output);
}

void ChatClientPrivateMessage::serializeAs_ChatClientPrivateMessage(Writer *output)
{
  ChatAbstractClientMessage::serializeAs_ChatAbstractClientMessage(output);
  output->writeUTF(this->receiver);
}

void ChatClientPrivateMessage::deserialize(Reader *input)
{
  this->deserializeAs_ChatClientPrivateMessage(input);
}

void ChatClientPrivateMessage::deserializeAs_ChatClientPrivateMessage(Reader *input)
{
  ChatAbstractClientMessage::deserialize(input);
  this->_receiverFunc(input);
}

void ChatClientPrivateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ChatClientPrivateMessage(tree);
}

void ChatClientPrivateMessage::deserializeAsyncAs_ChatClientPrivateMessage(FuncTree tree)
{
  ChatAbstractClientMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&ChatClientPrivateMessage::_receiverFunc, this, std::placeholders::_1));
}

void ChatClientPrivateMessage::_receiverFunc(Reader *input)
{
  this->receiver = input->readUTF();
}

ChatClientPrivateMessage::ChatClientPrivateMessage()
{
  m_type = MessageEnum::CHATCLIENTPRIVATEMESSAGE;
  m_needsHash = true;
}

