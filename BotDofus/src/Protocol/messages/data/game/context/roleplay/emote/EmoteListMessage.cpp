#include "EmoteListMessage.h"

void EmoteListMessage::serialize(Writer *output)
{
  this->serializeAs_EmoteListMessage(output);
}

void EmoteListMessage::serializeAs_EmoteListMessage(Writer *output)
{
  output->writeShort((short)this->emoteIds.size());
  for(uint _i1 = 0; _i1 < this->emoteIds.size(); _i1++)
  {
    if(this->emoteIds[_i1] < 0 || this->emoteIds[_i1] > 255)
    {
      qDebug()<<"ERREUR - EmoteListMessage -"<<"Forbidden value (" << this->emoteIds[_i1] << ") on element 1 (starting at 1) of emoteIds.";
    }
    output->writeByte(this->emoteIds[_i1]);
  }
}

void EmoteListMessage::deserialize(Reader *input)
{
  this->deserializeAs_EmoteListMessage(input);
}

void EmoteListMessage::deserializeAs_EmoteListMessage(Reader *input)
{
  uint _val1 = 0;
  uint _emoteIdsLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _emoteIdsLen; _i1++)
  {
    _val1 = input->readUByte();
    if(_val1 < 0 || _val1 > 255)
    {
      qDebug()<<"ERREUR - EmoteListMessage -"<<"Forbidden value (" << _val1 << ") on elements of emoteIds.";
    }
    this->emoteIds.append(_val1);
  }
}

void EmoteListMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_EmoteListMessage(tree);
}

void EmoteListMessage::deserializeAsyncAs_EmoteListMessage(FuncTree tree)
{
  this->_emoteIdstree = tree.addChild(std::bind(&EmoteListMessage::_emoteIdstreeFunc, this, std::placeholders::_1));
}

void EmoteListMessage::_emoteIdstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_emoteIdstree.addChild(std::bind(&EmoteListMessage::_emoteIdsFunc, this, std::placeholders::_1));
  }
}

void EmoteListMessage::_emoteIdsFunc(Reader *input)
{
  uint _val = input->readUByte();
  if(_val < 0 || _val > 255)
  {
    qDebug()<<"ERREUR - EmoteListMessage -"<<"Forbidden value (" << _val << ") on elements of emoteIds.";
  }
  this->emoteIds.append(_val);
}

EmoteListMessage::EmoteListMessage()
{
  m_type = MessageEnum::EMOTELISTMESSAGE;
}

