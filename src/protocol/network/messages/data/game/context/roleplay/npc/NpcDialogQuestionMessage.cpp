#include "NpcDialogQuestionMessage.h"

void NpcDialogQuestionMessage::serialize(Writer *output)
{
  this->serializeAs_NpcDialogQuestionMessage(output);
}

void NpcDialogQuestionMessage::serializeAs_NpcDialogQuestionMessage(Writer *output)
{
  if(this->messageId < 0)
  {
    qDebug()<<"ERREUR - NpcDialogQuestionMessage -"<<"Forbidden value (" << this->messageId << ") on element messageId.";
  }
  output->writeVarInt((int)this->messageId);
  output->writeShort((short)this->dialogParams.size());
  for(uint _i2 = 0; _i2 < this->dialogParams.size(); _i2++)
  {
    output->writeUTF(this->dialogParams[_i2]);
  }
  output->writeShort((short)this->visibleReplies.size());
  for(uint _i3 = 0; _i3 < this->visibleReplies.size(); _i3++)
  {
    if(this->visibleReplies[_i3] < 0)
    {
      qDebug()<<"ERREUR - NpcDialogQuestionMessage -"<<"Forbidden value (" << this->visibleReplies[_i3] << ") on element 3 (starting at 1) of visibleReplies.";
    }
    output->writeVarInt((int)this->visibleReplies[_i3]);
  }
}

void NpcDialogQuestionMessage::deserialize(Reader *input)
{
  this->deserializeAs_NpcDialogQuestionMessage(input);
}

void NpcDialogQuestionMessage::deserializeAs_NpcDialogQuestionMessage(Reader *input)
{
  QString _val2 ;
  uint _val3 = 0;
  this->_messageIdFunc(input);
  uint _dialogParamsLen = uint(input->readUShort());
  for(uint _i2 = 0; _i2 < _dialogParamsLen; _i2++)
  {
    _val2 = String(input->readUTF());
    this->dialogParams.append(_val2);
  }
  uint _visibleRepliesLen = uint(input->readUShort());
  for(uint _i3 = 0; _i3 < _visibleRepliesLen; _i3++)
  {
    _val3 = input->readVarUhInt();
    if(_val3 < 0)
    {
      qDebug()<<"ERREUR - NpcDialogQuestionMessage -"<<"Forbidden value (" << _val3 << ") on elements of visibleReplies.";
    }
    this->visibleReplies.append(_val3);
  }
}

void NpcDialogQuestionMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_NpcDialogQuestionMessage(tree);
}

void NpcDialogQuestionMessage::deserializeAsyncAs_NpcDialogQuestionMessage(FuncTree tree)
{
  tree.addChild(std::bind(&NpcDialogQuestionMessage::_messageIdFunc, this, std::placeholders::_1));
  this->_dialogParamstree = tree.addChild(std::bind(&NpcDialogQuestionMessage::_dialogParamstreeFunc, this, std::placeholders::_1));
  this->_visibleRepliestree = tree.addChild(std::bind(&NpcDialogQuestionMessage::_visibleRepliestreeFunc, this, std::placeholders::_1));
}

void NpcDialogQuestionMessage::_messageIdFunc(Reader *input)
{
  this->messageId = input->readVarUhInt();
  if(this->messageId < 0)
  {
    qDebug()<<"ERREUR - NpcDialogQuestionMessage -"<<"Forbidden value (" << this->messageId << ") on element of NpcDialogQuestionMessage.messageId.";
  }
}

void NpcDialogQuestionMessage::_dialogParamstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_dialogParamstree.addChild(std::bind(&NpcDialogQuestionMessage::_dialogParamsFunc, this, std::placeholders::_1));
  }
}

void NpcDialogQuestionMessage::_dialogParamsFunc(Reader *input)
{
  QString _val = String(input->readUTF());
  this->dialogParams.append(_val);
}

void NpcDialogQuestionMessage::_visibleRepliestreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_visibleRepliestree.addChild(std::bind(&NpcDialogQuestionMessage::_visibleRepliesFunc, this, std::placeholders::_1));
  }
}

void NpcDialogQuestionMessage::_visibleRepliesFunc(Reader *input)
{
  uint _val = input->readVarUhInt();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - NpcDialogQuestionMessage -"<<"Forbidden value (" << _val << ") on elements of visibleReplies.";
  }
  this->visibleReplies.append(_val);
}

NpcDialogQuestionMessage::NpcDialogQuestionMessage()
{
  m_type = MessageEnum::NPCDIALOGQUESTIONMESSAGE;
}

