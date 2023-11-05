#include "PrismsListMessage.h"

void PrismsListMessage::serialize(Writer *output)
{
  this->serializeAs_PrismsListMessage(output);
}

void PrismsListMessage::serializeAs_PrismsListMessage(Writer *output)
{
  output->writeShort((short)this->prisms.size());
  for(uint _i1 = 0; _i1 < this->prisms.size(); _i1++)
  {
    output->writeShort((short)qSharedPointerCast<PrismGeolocalizedInformation>(this->prisms[_i1])->getTypes().last());
    qSharedPointerCast<PrismGeolocalizedInformation>(this->prisms[_i1])->serialize(output);
  }
}

void PrismsListMessage::deserialize(Reader *input)
{
  this->deserializeAs_PrismsListMessage(input);
}

void PrismsListMessage::deserializeAs_PrismsListMessage(Reader *input)
{
  uint _id1 = 0;
  QSharedPointer<PrismGeolocalizedInformation> _item1 ;
  uint _prismsLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _prismsLen; _i1++)
  {
    _id1 = uint(input->readUShort());
    _item1 = qSharedPointerCast<PrismGeolocalizedInformation>(ClassManagerSingleton::get()->getClass(_id1));
    _item1->deserialize(input);
    this->prisms.append(_item1);
  }
}

void PrismsListMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PrismsListMessage(tree);
}

void PrismsListMessage::deserializeAsyncAs_PrismsListMessage(FuncTree tree)
{
  this->_prismstree = tree.addChild(std::bind(&PrismsListMessage::_prismstreeFunc, this, std::placeholders::_1));
}

void PrismsListMessage::_prismstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_prismstree.addChild(std::bind(&PrismsListMessage::_prismsFunc, this, std::placeholders::_1));
  }
}

void PrismsListMessage::_prismsFunc(Reader *input)
{
  uint _id = uint(input->readUShort());
  QSharedPointer<PrismGeolocalizedInformation> _item = qSharedPointerCast<PrismGeolocalizedInformation>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->prisms.append(_item);
}

PrismsListMessage::PrismsListMessage()
{
  m_type = MessageEnum::PRISMSLISTMESSAGE;
}

