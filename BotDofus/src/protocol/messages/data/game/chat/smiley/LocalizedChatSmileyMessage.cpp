#include "LocalizedChatSmileyMessage.h"

void LocalizedChatSmileyMessage::serialize(Writer *output)
{
  this->serializeAs_LocalizedChatSmileyMessage(output);
}

void LocalizedChatSmileyMessage::serializeAs_LocalizedChatSmileyMessage(Writer *output)
{
  ChatSmileyMessage::serializeAs_ChatSmileyMessage(output);
  if(this->cellId < 0 || this->cellId > 559)
  {
    qDebug()<<"ERREUR - LocalizedChatSmileyMessage -"<<"Forbidden value (" << this->cellId << ") on element cellId.";
  }
  output->writeVarShort((int)this->cellId);
}

void LocalizedChatSmileyMessage::deserialize(Reader *input)
{
  this->deserializeAs_LocalizedChatSmileyMessage(input);
}

void LocalizedChatSmileyMessage::deserializeAs_LocalizedChatSmileyMessage(Reader *input)
{
  ChatSmileyMessage::deserialize(input);
  this->_cellIdFunc(input);
}

void LocalizedChatSmileyMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_LocalizedChatSmileyMessage(tree);
}

void LocalizedChatSmileyMessage::deserializeAsyncAs_LocalizedChatSmileyMessage(FuncTree tree)
{
  ChatSmileyMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&LocalizedChatSmileyMessage::_cellIdFunc, this, std::placeholders::_1));
}

void LocalizedChatSmileyMessage::_cellIdFunc(Reader *input)
{
  this->cellId = input->readVarUhShort();
  if(this->cellId < 0 || this->cellId > 559)
  {
    qDebug()<<"ERREUR - LocalizedChatSmileyMessage -"<<"Forbidden value (" << this->cellId << ") on element of LocalizedChatSmileyMessage.cellId.";
  }
}

LocalizedChatSmileyMessage::LocalizedChatSmileyMessage()
{
  m_type = MessageEnum::LOCALIZEDCHATSMILEYMESSAGE;
}

