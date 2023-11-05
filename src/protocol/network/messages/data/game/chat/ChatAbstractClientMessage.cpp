#include "ChatAbstractClientMessage.h"

void ChatAbstractClientMessage::serialize(Writer *output)
{
  this->serializeAs_ChatAbstractClientMessage(output);
}

void ChatAbstractClientMessage::serializeAs_ChatAbstractClientMessage(Writer *output)
{
  output->writeUTF(this->content);
}

void ChatAbstractClientMessage::deserialize(Reader *input)
{
  this->deserializeAs_ChatAbstractClientMessage(input);
}

void ChatAbstractClientMessage::deserializeAs_ChatAbstractClientMessage(Reader *input)
{
  this->_contentFunc(input);
}

void ChatAbstractClientMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ChatAbstractClientMessage(tree);
}

void ChatAbstractClientMessage::deserializeAsyncAs_ChatAbstractClientMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ChatAbstractClientMessage::_contentFunc, this, std::placeholders::_1));
}

void ChatAbstractClientMessage::_contentFunc(Reader *input)
{
  this->content = input->readUTF();
}

ChatAbstractClientMessage::ChatAbstractClientMessage()
{
  m_type = MessageEnum::CHATABSTRACTCLIENTMESSAGE;
}

