#include "DebtsUpdateMessage.h"

void DebtsUpdateMessage::serialize(Writer *output)
{
  this->serializeAs_DebtsUpdateMessage(output);
}

void DebtsUpdateMessage::serializeAs_DebtsUpdateMessage(Writer *output)
{
  output->writeByte(this->action);
  output->writeShort((short)this->debts.size());
  for(uint _i2 = 0; _i2 < this->debts.size(); _i2++)
  {
    output->writeShort((short)qSharedPointerCast<DebtInformation>(this->debts[_i2])->getTypes().last());
    qSharedPointerCast<DebtInformation>(this->debts[_i2])->serialize(output);
  }
}

void DebtsUpdateMessage::deserialize(Reader *input)
{
  this->deserializeAs_DebtsUpdateMessage(input);
}

void DebtsUpdateMessage::deserializeAs_DebtsUpdateMessage(Reader *input)
{
  uint _id2 = 0;
  QSharedPointer<DebtInformation> _item2 ;
  this->_actionFunc(input);
  uint _debtsLen = input->readUShort();
  for(uint _i2 = 0; _i2 < _debtsLen; _i2++)
  {
    _id2 = input->readUShort();
    _item2 = qSharedPointerCast<DebtInformation>(ClassManagerSingleton::get()->getClass(_id2));
    _item2->deserialize(input);
    this->debts.append(_item2);
  }
}

void DebtsUpdateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_DebtsUpdateMessage(tree);
}

void DebtsUpdateMessage::deserializeAsyncAs_DebtsUpdateMessage(FuncTree tree)
{
  tree.addChild(std::bind(&DebtsUpdateMessage::_actionFunc, this, std::placeholders::_1));
  this->_debtstree = tree.addChild(std::bind(&DebtsUpdateMessage::_debtstreeFunc, this, std::placeholders::_1));
}

void DebtsUpdateMessage::_actionFunc(Reader *input)
{
  this->action = input->readByte();
  if(this->action < 0)
  {
    qDebug()<<"ERREUR - DebtsUpdateMessage -"<<"Forbidden value (" << this->action << ") on element of DebtsUpdateMessage.action.";
  }
}

void DebtsUpdateMessage::_debtstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_debtstree.addChild(std::bind(&DebtsUpdateMessage::_debtsFunc, this, std::placeholders::_1));
  }
}

void DebtsUpdateMessage::_debtsFunc(Reader *input)
{
  uint _id = input->readUShort();
  QSharedPointer<DebtInformation> _item = qSharedPointerCast<DebtInformation>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->debts.append(_item);
}

DebtsUpdateMessage::DebtsUpdateMessage()
{
  m_type = MessageEnum::DEBTSUPDATEMESSAGE;
}

