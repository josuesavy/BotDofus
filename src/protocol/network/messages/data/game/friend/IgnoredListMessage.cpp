#include "IgnoredListMessage.h"

void IgnoredListMessage::serialize(Writer *output)
{
  this->serializeAs_IgnoredListMessage(output);
}

void IgnoredListMessage::serializeAs_IgnoredListMessage(Writer *output)
{
  output->writeShort((short)this->ignoredList.size());
  for(uint _i1 = 0; _i1 < this->ignoredList.size(); _i1++)
  {
    output->writeShort((short)qSharedPointerCast<IgnoredInformations>(this->ignoredList[_i1])->getTypes().last());
    qSharedPointerCast<IgnoredInformations>(this->ignoredList[_i1])->serialize(output);
  }
}

void IgnoredListMessage::deserialize(Reader *input)
{
  this->deserializeAs_IgnoredListMessage(input);
}

void IgnoredListMessage::deserializeAs_IgnoredListMessage(Reader *input)
{
  uint _id1 = 0;
  QSharedPointer<IgnoredInformations> _item1 ;
  uint _ignoredListLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _ignoredListLen; _i1++)
  {
    _id1 = uint(input->readUShort());
    _item1 = qSharedPointerCast<IgnoredInformations>(ClassManagerSingleton::get()->getClass(_id1));
    _item1->deserialize(input);
    this->ignoredList.append(_item1);
  }
}

void IgnoredListMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_IgnoredListMessage(tree);
}

void IgnoredListMessage::deserializeAsyncAs_IgnoredListMessage(FuncTree tree)
{
  this->_ignoredListtree = tree.addChild(std::bind(&IgnoredListMessage::_ignoredListtreeFunc, this, std::placeholders::_1));
}

void IgnoredListMessage::_ignoredListtreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_ignoredListtree.addChild(std::bind(&IgnoredListMessage::_ignoredListFunc, this, std::placeholders::_1));
  }
}

void IgnoredListMessage::_ignoredListFunc(Reader *input)
{
  uint _id = uint(input->readUShort());
  QSharedPointer<IgnoredInformations> _item = qSharedPointerCast<IgnoredInformations>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->ignoredList.append(_item);
}

IgnoredListMessage::IgnoredListMessage()
{
  m_type = MessageEnum::IGNOREDLISTMESSAGE;
}

