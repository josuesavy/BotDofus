#include "ObjectAveragePricesMessage.h"

void ObjectAveragePricesMessage::serialize(Writer *output)
{
  this->serializeAs_ObjectAveragePricesMessage(output);
}

void ObjectAveragePricesMessage::serializeAs_ObjectAveragePricesMessage(Writer *output)
{
  output->writeShort((short)this->ids.size());
  for(uint _i1 = 0; _i1 < this->ids.size(); _i1++)
  {
    if(this->ids[_i1] < 0)
    {
      qDebug()<<"ERREUR - ObjectAveragePricesMessage -"<<"Forbidden value (" << this->ids[_i1] << ") on element 1 (starting at 1) of ids.";
    }
    output->writeVarShort((int)this->ids[_i1]);
  }
  output->writeShort((short)this->avgPrices.size());
  for(uint _i2 = 0; _i2 < this->avgPrices.size(); _i2++)
  {
    if(this->avgPrices[_i2] < 0 || this->avgPrices[_i2] > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - ObjectAveragePricesMessage -"<<"Forbidden value (" << this->avgPrices[_i2] << ") on element 2 (starting at 1) of avgPrices.";
    }
    output->writeVarLong((double)this->avgPrices[_i2]);
  }
}

void ObjectAveragePricesMessage::deserialize(Reader *input)
{
  this->deserializeAs_ObjectAveragePricesMessage(input);
}

void ObjectAveragePricesMessage::deserializeAs_ObjectAveragePricesMessage(Reader *input)
{
  uint _val1 = 0;
  auto _val2 = NULL;
  uint _idsLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _idsLen; _i1++)
  {
    _val1 = input->readVarUhShort();
    if(_val1 < 0)
    {
      qDebug()<<"ERREUR - ObjectAveragePricesMessage -"<<"Forbidden value (" << _val1 << ") on elements of ids.";
    }
    this->ids.append(_val1);
  }
  uint _avgPricesLen = input->readUShort();
  for(uint _i2 = 0; _i2 < _avgPricesLen; _i2++)
  {
    _val2 = input->readVarUhLong();
    if(_val2 < 0 || _val2 > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - ObjectAveragePricesMessage -"<<"Forbidden value (" << _val2 << ") on elements of avgPrices.";
    }
    this->avgPrices.append(_val2);
  }
}

void ObjectAveragePricesMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ObjectAveragePricesMessage(tree);
}

void ObjectAveragePricesMessage::deserializeAsyncAs_ObjectAveragePricesMessage(FuncTree tree)
{
  this->_idstree = tree.addChild(std::bind(&ObjectAveragePricesMessage::_idstreeFunc, this, std::placeholders::_1));
  this->_avgPricestree = tree.addChild(std::bind(&ObjectAveragePricesMessage::_avgPricestreeFunc, this, std::placeholders::_1));
}

void ObjectAveragePricesMessage::_idstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_idstree.addChild(std::bind(&ObjectAveragePricesMessage::_idsFunc, this, std::placeholders::_1));
  }
}

void ObjectAveragePricesMessage::_idsFunc(Reader *input)
{
  uint _val = input->readVarUhShort();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - ObjectAveragePricesMessage -"<<"Forbidden value (" << _val << ") on elements of ids.";
  }
  this->ids.append(_val);
}

void ObjectAveragePricesMessage::_avgPricestreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_avgPricestree.addChild(std::bind(&ObjectAveragePricesMessage::_avgPricesFunc, this, std::placeholders::_1));
  }
}

void ObjectAveragePricesMessage::_avgPricesFunc(Reader *input)
{
  double _val = input->readVarUhLong();
  if(_val < 0 || _val > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ObjectAveragePricesMessage -"<<"Forbidden value (" << _val << ") on elements of avgPrices.";
  }
  this->avgPrices.append(_val);
}

ObjectAveragePricesMessage::ObjectAveragePricesMessage()
{
  m_type = MessageEnum::OBJECTAVERAGEPRICESMESSAGE;
}

