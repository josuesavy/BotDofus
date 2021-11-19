#include "ChatSmileyExtraPackListMessage.h"

void ChatSmileyExtraPackListMessage::serialize(Writer *output)
{
  this->serializeAs_ChatSmileyExtraPackListMessage(output);
}

void ChatSmileyExtraPackListMessage::serializeAs_ChatSmileyExtraPackListMessage(Writer *output)
{
  output->writeShort((short)this->packIds.size());
  for(uint _i1 = 0; _i1 < this->packIds.size(); _i1++)
  {
    if(this->packIds[_i1] < 0)
    {
      qDebug()<<"ERREUR - ChatSmileyExtraPackListMessage -"<<"Forbidden value (" << this->packIds[_i1] << ") on element 1 (starting at 1) of packIds.";
    }
    output->writeByte(this->packIds[_i1]);
  }
}

void ChatSmileyExtraPackListMessage::deserialize(Reader *input)
{
  this->deserializeAs_ChatSmileyExtraPackListMessage(input);
}

void ChatSmileyExtraPackListMessage::deserializeAs_ChatSmileyExtraPackListMessage(Reader *input)
{
  uint _val1 = 0;
  uint _packIdsLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _packIdsLen; _i1++)
  {
    _val1 = input->readByte();
    if(_val1 < 0)
    {
      qDebug()<<"ERREUR - ChatSmileyExtraPackListMessage -"<<"Forbidden value (" << _val1 << ") on elements of packIds.";
    }
    this->packIds.append(_val1);
  }
}

void ChatSmileyExtraPackListMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ChatSmileyExtraPackListMessage(tree);
}

void ChatSmileyExtraPackListMessage::deserializeAsyncAs_ChatSmileyExtraPackListMessage(FuncTree tree)
{
  this->_packIdstree = tree.addChild(std::bind(&ChatSmileyExtraPackListMessage::_packIdstreeFunc, this, std::placeholders::_1));
}

void ChatSmileyExtraPackListMessage::_packIdstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_packIdstree.addChild(std::bind(&ChatSmileyExtraPackListMessage::_packIdsFunc, this, std::placeholders::_1));
  }
}

void ChatSmileyExtraPackListMessage::_packIdsFunc(Reader *input)
{
  uint _val = input->readByte();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - ChatSmileyExtraPackListMessage -"<<"Forbidden value (" << _val << ") on elements of packIds.";
  }
  this->packIds.append(_val);
}

ChatSmileyExtraPackListMessage::ChatSmileyExtraPackListMessage()
{
  m_type = MessageEnum::CHATSMILEYEXTRAPACKLISTMESSAGE;
}

