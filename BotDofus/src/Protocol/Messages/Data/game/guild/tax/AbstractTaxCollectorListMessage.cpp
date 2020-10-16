#include "AbstractTaxCollectorListMessage.h"

void AbstractTaxCollectorListMessage::serialize(Writer *output)
{
  this->serializeAs_AbstractTaxCollectorListMessage(output);
}

void AbstractTaxCollectorListMessage::serializeAs_AbstractTaxCollectorListMessage(Writer *output)
{
  output->writeShort((short)this->informations.size());
  for(uint _i1 = 0; _i1 < this->informations.size(); _i1++)
  {
    output->writeShort((short)qSharedPointerCast<TaxCollectorInformations>(this->informations[_i1])->getTypes().last());
    qSharedPointerCast<TaxCollectorInformations>(this->informations[_i1])->serialize(output);
  }
}

void AbstractTaxCollectorListMessage::deserialize(Reader *input)
{
  this->deserializeAs_AbstractTaxCollectorListMessage(input);
}

void AbstractTaxCollectorListMessage::deserializeAs_AbstractTaxCollectorListMessage(Reader *input)
{
  uint _id1 = 0;
  QSharedPointer<TaxCollectorInformations> _item1 ;
  uint _informationsLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _informationsLen; _i1++)
  {
    _id1 = input->readUShort();
    _item1 = qSharedPointerCast<TaxCollectorInformations>(ClassManagerSingleton::get()->getClass(_id1));
    _item1->deserialize(input);
    this->informations.append(_item1);
  }
}

void AbstractTaxCollectorListMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AbstractTaxCollectorListMessage(tree);
}

void AbstractTaxCollectorListMessage::deserializeAsyncAs_AbstractTaxCollectorListMessage(FuncTree tree)
{
  this->_informationstree = tree.addChild(std::bind(&AbstractTaxCollectorListMessage::_informationstreeFunc, this, std::placeholders::_1));
}

void AbstractTaxCollectorListMessage::_informationstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_informationstree.addChild(std::bind(&AbstractTaxCollectorListMessage::_informationsFunc, this, std::placeholders::_1));
  }
}

void AbstractTaxCollectorListMessage::_informationsFunc(Reader *input)
{
  uint _id = input->readUShort();
  QSharedPointer<TaxCollectorInformations> _item = qSharedPointerCast<TaxCollectorInformations>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->informations.append(_item);
}

AbstractTaxCollectorListMessage::AbstractTaxCollectorListMessage()
{
  m_type = MessageEnum::ABSTRACTTAXCOLLECTORLISTMESSAGE;
}

