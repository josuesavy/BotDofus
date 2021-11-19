#include "ChatSmileyRequestMessage.h"

void ChatSmileyRequestMessage::serialize(Writer *output)
{
  this->serializeAs_ChatSmileyRequestMessage(output);
}

void ChatSmileyRequestMessage::serializeAs_ChatSmileyRequestMessage(Writer *output)
{
  if(this->smileyId < 0)
  {
    qDebug()<<"ERREUR - ChatSmileyRequestMessage -"<<"Forbidden value (" << this->smileyId << ") on element smileyId.";
  }
  output->writeVarShort((int)this->smileyId);
}

void ChatSmileyRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_ChatSmileyRequestMessage(input);
}

void ChatSmileyRequestMessage::deserializeAs_ChatSmileyRequestMessage(Reader *input)
{
  this->_smileyIdFunc(input);
}

void ChatSmileyRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ChatSmileyRequestMessage(tree);
}

void ChatSmileyRequestMessage::deserializeAsyncAs_ChatSmileyRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ChatSmileyRequestMessage::_smileyIdFunc, this, std::placeholders::_1));
}

void ChatSmileyRequestMessage::_smileyIdFunc(Reader *input)
{
  this->smileyId = input->readVarUhShort();
  if(this->smileyId < 0)
  {
    qDebug()<<"ERREUR - ChatSmileyRequestMessage -"<<"Forbidden value (" << this->smileyId << ") on element of ChatSmileyRequestMessage.smileyId.";
  }
}

ChatSmileyRequestMessage::ChatSmileyRequestMessage()
{
  m_type = MessageEnum::CHATSMILEYREQUESTMESSAGE;
}

