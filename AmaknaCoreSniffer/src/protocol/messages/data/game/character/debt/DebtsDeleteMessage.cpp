#include "DebtsDeleteMessage.h"

void DebtsDeleteMessage::serialize(Writer *output)
{
  this->serializeAs_DebtsDeleteMessage(output);
}

void DebtsDeleteMessage::serializeAs_DebtsDeleteMessage(Writer *output)
{
  output->writeByte(this->reason);
  output->writeShort((short)this->debts.size());
  for(uint _i2 = 0; _i2 < this->debts.size(); _i2++)
  {
    if(this->debts[_i2] < 0 || this->debts[_i2] > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - DebtsDeleteMessage -"<<"Forbidden value (" << this->debts[_i2] << ") on element 2 (starting at 1) of debts.";
    }
    output->writeDouble(this->debts[_i2]);
  }
}

void DebtsDeleteMessage::deserialize(Reader *input)
{
  this->deserializeAs_DebtsDeleteMessage(input);
}

void DebtsDeleteMessage::deserializeAs_DebtsDeleteMessage(Reader *input)
{
  auto _val2 = NULL;
  this->_reasonFunc(input);
  uint _debtsLen = input->readUShort();
  for(uint _i2 = 0; _i2 < _debtsLen; _i2++)
  {
    _val2 = input->readDouble();
    if(_val2 < 0 || _val2 > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - DebtsDeleteMessage -"<<"Forbidden value (" << _val2 << ") on elements of debts.";
    }
    this->debts.append(_val2);
  }
}

void DebtsDeleteMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_DebtsDeleteMessage(tree);
}

void DebtsDeleteMessage::deserializeAsyncAs_DebtsDeleteMessage(FuncTree tree)
{
  tree.addChild(std::bind(&DebtsDeleteMessage::_reasonFunc, this, std::placeholders::_1));
  this->_debtstree = tree.addChild(std::bind(&DebtsDeleteMessage::_debtstreeFunc, this, std::placeholders::_1));
}

void DebtsDeleteMessage::_reasonFunc(Reader *input)
{
  this->reason = input->readByte();
  if(this->reason < 0)
  {
    qDebug()<<"ERREUR - DebtsDeleteMessage -"<<"Forbidden value (" << this->reason << ") on element of DebtsDeleteMessage.reason.";
  }
}

void DebtsDeleteMessage::_debtstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_debtstree.addChild(std::bind(&DebtsDeleteMessage::_debtsFunc, this, std::placeholders::_1));
  }
}

void DebtsDeleteMessage::_debtsFunc(Reader *input)
{
  double _val = input->readDouble();
  if(_val < 0 || _val > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - DebtsDeleteMessage -"<<"Forbidden value (" << _val << ") on elements of debts.";
  }
  this->debts.append(_val);
}

DebtsDeleteMessage::DebtsDeleteMessage()
{
  m_type = MessageEnum::DEBTSDELETEMESSAGE;
}

