#include "ChatServerCopyMessage.h"

void ChatServerCopyMessage::serialize(Writer *output)
{
  this->serializeAs_ChatServerCopyMessage(output);
}

void ChatServerCopyMessage::serializeAs_ChatServerCopyMessage(Writer *output)
{
  ChatAbstractServerMessage::serializeAs_ChatAbstractServerMessage(output);
  if(this->receiverId < 0 || this->receiverId > 9007199254740992)
  {
    qDebug()<<"ERREUR - ChatServerCopyMessage -"<<"Forbidden value (" << this->receiverId << ") on element receiverId.";
  }
  output->writeVarLong((double)this->receiverId);
  output->writeUTF(this->receiverName);
}

void ChatServerCopyMessage::deserialize(Reader *input)
{
  this->deserializeAs_ChatServerCopyMessage(input);
}

void ChatServerCopyMessage::deserializeAs_ChatServerCopyMessage(Reader *input)
{
  ChatAbstractServerMessage::deserialize(input);
  this->_receiverIdFunc(input);
  this->_receiverNameFunc(input);
}

void ChatServerCopyMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ChatServerCopyMessage(tree);
}

void ChatServerCopyMessage::deserializeAsyncAs_ChatServerCopyMessage(FuncTree tree)
{
  ChatAbstractServerMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&ChatServerCopyMessage::_receiverIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ChatServerCopyMessage::_receiverNameFunc, this, std::placeholders::_1));
}

void ChatServerCopyMessage::_receiverIdFunc(Reader *input)
{
  this->receiverId = input->readVarUhLong();
  if(this->receiverId < 0 || this->receiverId > 9007199254740992)
  {
    qDebug()<<"ERREUR - ChatServerCopyMessage -"<<"Forbidden value (" << this->receiverId << ") on element of ChatServerCopyMessage.receiverId.";
  }
}

void ChatServerCopyMessage::_receiverNameFunc(Reader *input)
{
  this->receiverName = input->readUTF();
}

ChatServerCopyMessage::ChatServerCopyMessage()
{
  m_type = MessageEnum::CHATSERVERCOPYMESSAGE;
}

