#include "TextInformationMessage.h"

void TextInformationMessage::serialize(Writer *output)
{
  this->serializeAs_TextInformationMessage(output);
}

void TextInformationMessage::serializeAs_TextInformationMessage(Writer *output)
{
  output->writeByte(this->msgType);
  if(this->msgId < 0)
  {
    qDebug()<<"ERREUR - TextInformationMessage -"<<"Forbidden value (" << this->msgId << ") on element msgId.";
  }
  output->writeVarShort((int)this->msgId);
  output->writeShort((short)this->parameters.size());
  for(uint _i3 = 0; _i3 < this->parameters.size(); _i3++)
  {
    output->writeUTF(this->parameters[_i3]);
  }
}

void TextInformationMessage::deserialize(Reader *input)
{
  this->deserializeAs_TextInformationMessage(input);
}

void TextInformationMessage::deserializeAs_TextInformationMessage(Reader *input)
{
  QString _val3 ;
  this->_msgTypeFunc(input);
  this->_msgIdFunc(input);
  uint _parametersLen = uint(input->readUShort());
  for(uint _i3 = 0; _i3 < _parametersLen; _i3++)
  {
    _val3 = String(input->readUTF());
    this->parameters.append(_val3);
  }
}

void TextInformationMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TextInformationMessage(tree);
}

void TextInformationMessage::deserializeAsyncAs_TextInformationMessage(FuncTree tree)
{
  tree.addChild(std::bind(&TextInformationMessage::_msgTypeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TextInformationMessage::_msgIdFunc, this, std::placeholders::_1));
  this->_parameterstree = tree.addChild(std::bind(&TextInformationMessage::_parameterstreeFunc, this, std::placeholders::_1));
}

void TextInformationMessage::_msgTypeFunc(Reader *input)
{
  this->msgType = input->readByte();
  if(this->msgType < 0)
  {
    qDebug()<<"ERREUR - TextInformationMessage -"<<"Forbidden value (" << this->msgType << ") on element of TextInformationMessage.msgType.";
  }
}

void TextInformationMessage::_msgIdFunc(Reader *input)
{
  this->msgId = input->readVarUhShort();
  if(this->msgId < 0)
  {
    qDebug()<<"ERREUR - TextInformationMessage -"<<"Forbidden value (" << this->msgId << ") on element of TextInformationMessage.msgId.";
  }
}

void TextInformationMessage::_parameterstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_parameterstree.addChild(std::bind(&TextInformationMessage::_parametersFunc, this, std::placeholders::_1));
  }
}

void TextInformationMessage::_parametersFunc(Reader *input)
{
  QString _val = String(input->readUTF());
  this->parameters.append(_val);
}

TextInformationMessage::TextInformationMessage()
{
  m_type = MessageEnum::TEXTINFORMATIONMESSAGE;
}

