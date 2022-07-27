#include "ChatErrorMessage.h"

void ChatErrorMessage::serialize(Writer *output)
{
  this->serializeAs_ChatErrorMessage(output);
}

void ChatErrorMessage::serializeAs_ChatErrorMessage(Writer *output)
{
  output->writeByte(this->reason);
}

void ChatErrorMessage::deserialize(Reader *input)
{
  this->deserializeAs_ChatErrorMessage(input);
}

void ChatErrorMessage::deserializeAs_ChatErrorMessage(Reader *input)
{
  this->_reasonFunc(input);
}

void ChatErrorMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ChatErrorMessage(tree);
}

void ChatErrorMessage::deserializeAsyncAs_ChatErrorMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ChatErrorMessage::_reasonFunc, this, std::placeholders::_1));
}

void ChatErrorMessage::_reasonFunc(Reader *input)
{
  this->reason = input->readByte();
  if(this->reason < 0)
  {
    qDebug()<<"ERREUR - ChatErrorMessage -"<<"Forbidden value (" << this->reason << ") on element of ChatErrorMessage.reason.";
  }
}

ChatErrorMessage::ChatErrorMessage()
{
  m_type = MessageEnum::CHATERRORMESSAGE;
}

