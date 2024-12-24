#include "ChatClientPrivateMessage.h"

void ChatClientPrivateMessage::serialize(Writer *output)
{
  this->serializeAs_ChatClientPrivateMessage(output);
}

void ChatClientPrivateMessage::serializeAs_ChatClientPrivateMessage(Writer *output)
{
  ChatAbstractClientMessage::serializeAs_ChatAbstractClientMessage(output);
  output->writeShort((short)this->receiver->getTypes().last());
  this->receiver->serialize(output);
}

void ChatClientPrivateMessage::deserialize(Reader *input)
{
  this->deserializeAs_ChatClientPrivateMessage(input);
}

void ChatClientPrivateMessage::deserializeAs_ChatClientPrivateMessage(Reader *input)
{
  ChatAbstractClientMessage::deserialize(input);
  uint _id1 = uint(input->readUShort());
  this->receiver = qSharedPointerCast<AbstractPlayerSearchInformation>(ClassManagerSingleton::get()->getClass(_id1));
  this->receiver->deserialize(input);
}

void ChatClientPrivateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ChatClientPrivateMessage(tree);
}

void ChatClientPrivateMessage::deserializeAsyncAs_ChatClientPrivateMessage(FuncTree tree)
{
  ChatAbstractClientMessage::deserializeAsync(tree);
  this->_receivertree = tree.addChild(std::bind(&ChatClientPrivateMessage::_receivertreeFunc, this, std::placeholders::_1));
}

void ChatClientPrivateMessage::_receivertreeFunc(Reader *input)
{
  uint _id = uint(input->readUShort());
  this->receiver = qSharedPointerCast<AbstractPlayerSearchInformation>(ClassManagerSingleton::get()->getClass(_id));
  this->receiver->deserializeAsync(this->_receivertree);
}

ChatClientPrivateMessage::ChatClientPrivateMessage()
{
  m_type = MessageEnum::CHATCLIENTPRIVATEMESSAGE;
  m_needsHash = true;
}

