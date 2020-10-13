#include "NpcDialogReplyMessage.h"

void NpcDialogReplyMessage::serialize(Writer *output)
{
  this->serializeAs_NpcDialogReplyMessage(output);
}

void NpcDialogReplyMessage::serializeAs_NpcDialogReplyMessage(Writer *output)
{
  if(this->replyId < 0)
  {
    qDebug()<<"ERREUR - NpcDialogReplyMessage -"<<"Forbidden value (" << this->replyId << ") on element replyId.";
  }
  output->writeVarInt((int)this->replyId);
}

void NpcDialogReplyMessage::deserialize(Reader *input)
{
  this->deserializeAs_NpcDialogReplyMessage(input);
}

void NpcDialogReplyMessage::deserializeAs_NpcDialogReplyMessage(Reader *input)
{
  this->_replyIdFunc(input);
}

void NpcDialogReplyMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_NpcDialogReplyMessage(tree);
}

void NpcDialogReplyMessage::deserializeAsyncAs_NpcDialogReplyMessage(FuncTree tree)
{
  tree.addChild(std::bind(&NpcDialogReplyMessage::_replyIdFunc, this, std::placeholders::_1));
}

void NpcDialogReplyMessage::_replyIdFunc(Reader *input)
{
  this->replyId = input->readVarUhInt();
  if(this->replyId < 0)
  {
    qDebug()<<"ERREUR - NpcDialogReplyMessage -"<<"Forbidden value (" << this->replyId << ") on element of NpcDialogReplyMessage.replyId.";
  }
}

NpcDialogReplyMessage::NpcDialogReplyMessage()
{
  m_type = MessageEnum::NPCDIALOGREPLYMESSAGE;
}

