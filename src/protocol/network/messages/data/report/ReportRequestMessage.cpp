#include "ReportRequestMessage.h"

void ReportRequestMessage::serialize(Writer *output)
{
  this->serializeAs_ReportRequestMessage(output);
}

void ReportRequestMessage::serializeAs_ReportRequestMessage(Writer *output)
{
  if(this->targetId < -9007199254740992 || this->targetId > 9007199254740992)
  {
    qDebug()<<"ERREUR - ReportRequestMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  output->writeDouble(this->targetId);
  output->writeShort((short)this->categories.size());
  for(uint _i2 = 0; _i2 < this->categories.size(); _i2++)
  {
    output->writeByte(this->categories[_i2]);
  }
  output->writeUTF(this->description);
}

void ReportRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_ReportRequestMessage(input);
}

void ReportRequestMessage::deserializeAs_ReportRequestMessage(Reader *input)
{
  uint _val2 = 0;
  this->_targetIdFunc(input);
  uint _categoriesLen = uint(input->readUShort());
  for(uint _i2 = 0; _i2 < _categoriesLen; _i2++)
  {
    _val2 = uint(input->readByte());
    if(_val2 < 0)
    {
      qDebug()<<"ERREUR - ReportRequestMessage -"<<"Forbidden value (" << _val2 << ") on elements of categories.";
    }
    this->categories.append(_val2);
  }
  this->_descriptionFunc(input);
}

void ReportRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ReportRequestMessage(tree);
}

void ReportRequestMessage::deserializeAsyncAs_ReportRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ReportRequestMessage::_targetIdFunc, this, std::placeholders::_1));
  this->_categoriestree = tree.addChild(std::bind(&ReportRequestMessage::_categoriestreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ReportRequestMessage::_descriptionFunc, this, std::placeholders::_1));
}

void ReportRequestMessage::_targetIdFunc(Reader *input)
{
  this->targetId = input->readDouble();
  if(this->targetId < -9007199254740992 || this->targetId > 9007199254740992)
  {
    qDebug()<<"ERREUR - ReportRequestMessage -"<<"Forbidden value (" << this->targetId << ") on element of ReportRequestMessage.targetId.";
  }
}

void ReportRequestMessage::_categoriestreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_categoriestree.addChild(std::bind(&ReportRequestMessage::_categoriesFunc, this, std::placeholders::_1));
  }
}

void ReportRequestMessage::_categoriesFunc(Reader *input)
{
  uint _val = uint(input->readByte());
  if(_val < 0)
  {
    qDebug()<<"ERREUR - ReportRequestMessage -"<<"Forbidden value (" << _val << ") on elements of categories.";
  }
  this->categories.append(_val);
}

void ReportRequestMessage::_descriptionFunc(Reader *input)
{
  this->description = input->readUTF();
}

ReportRequestMessage::ReportRequestMessage()
{
  m_type = MessageEnum::REPORTREQUESTMESSAGE;
}

