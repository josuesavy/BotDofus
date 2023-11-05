#include "BasicStatWithDataMessage.h"

void BasicStatWithDataMessage::serialize(Writer *output)
{
  this->serializeAs_BasicStatWithDataMessage(output);
}

void BasicStatWithDataMessage::serializeAs_BasicStatWithDataMessage(Writer *output)
{
  BasicStatMessage::serializeAs_BasicStatMessage(output);
  output->writeShort((short)this->datas.size());
  for(uint _i1 = 0; _i1 < this->datas.size(); _i1++)
  {
    output->writeShort((short)qSharedPointerCast<StatisticData>(this->datas[_i1])->getTypes().last());
    qSharedPointerCast<StatisticData>(this->datas[_i1])->serialize(output);
  }
}

void BasicStatWithDataMessage::deserialize(Reader *input)
{
  this->deserializeAs_BasicStatWithDataMessage(input);
}

void BasicStatWithDataMessage::deserializeAs_BasicStatWithDataMessage(Reader *input)
{
  uint _id1 = 0;
  QSharedPointer<StatisticData> _item1 ;
  BasicStatMessage::deserialize(input);
  uint _datasLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _datasLen; _i1++)
  {
    _id1 = uint(input->readUShort());
    _item1 = qSharedPointerCast<StatisticData>(ClassManagerSingleton::get()->getClass(_id1));
    _item1->deserialize(input);
    this->datas.append(_item1);
  }
}

void BasicStatWithDataMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_BasicStatWithDataMessage(tree);
}

void BasicStatWithDataMessage::deserializeAsyncAs_BasicStatWithDataMessage(FuncTree tree)
{
  BasicStatMessage::deserializeAsync(tree);
  this->_datastree = tree.addChild(std::bind(&BasicStatWithDataMessage::_datastreeFunc, this, std::placeholders::_1));
}

void BasicStatWithDataMessage::_datastreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_datastree.addChild(std::bind(&BasicStatWithDataMessage::_datasFunc, this, std::placeholders::_1));
  }
}

void BasicStatWithDataMessage::_datasFunc(Reader *input)
{
  uint _id = uint(input->readUShort());
  QSharedPointer<StatisticData> _item = qSharedPointerCast<StatisticData>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->datas.append(_item);
}

BasicStatWithDataMessage::BasicStatWithDataMessage()
{
  m_type = MessageEnum::BASICSTATWITHDATAMESSAGE;
}

