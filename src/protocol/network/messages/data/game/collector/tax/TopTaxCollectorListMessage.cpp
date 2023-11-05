#include "TopTaxCollectorListMessage.h"

void TopTaxCollectorListMessage::serialize(Writer *output)
{
  this->serializeAs_TopTaxCollectorListMessage(output);
}

void TopTaxCollectorListMessage::serializeAs_TopTaxCollectorListMessage(Writer *output)
{
  output->writeShort((short)this->dungeonTaxCollectorsInformation.size());
  for(uint _i1 = 0; _i1 < this->dungeonTaxCollectorsInformation.size(); _i1++)
  {
    output->writeShort((short)qSharedPointerCast<TaxCollectorInformations>(this->dungeonTaxCollectorsInformation[_i1])->getTypes().last());
    qSharedPointerCast<TaxCollectorInformations>(this->dungeonTaxCollectorsInformation[_i1])->serialize(output);
  }
  output->writeShort((short)this->worldTaxCollectorsInformation.size());
  for(uint _i2 = 0; _i2 < this->worldTaxCollectorsInformation.size(); _i2++)
  {
    output->writeShort((short)qSharedPointerCast<TaxCollectorInformations>(this->worldTaxCollectorsInformation[_i2])->getTypes().last());
    qSharedPointerCast<TaxCollectorInformations>(this->worldTaxCollectorsInformation[_i2])->serialize(output);
  }
}

void TopTaxCollectorListMessage::deserialize(Reader *input)
{
  this->deserializeAs_TopTaxCollectorListMessage(input);
}

void TopTaxCollectorListMessage::deserializeAs_TopTaxCollectorListMessage(Reader *input)
{
  uint _id1 = 0;
  QSharedPointer<TaxCollectorInformations> _item1 ;
  uint _id2 = 0;
  QSharedPointer<TaxCollectorInformations> _item2 ;
  uint _dungeonTaxCollectorsInformationLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _dungeonTaxCollectorsInformationLen; _i1++)
  {
    _id1 = uint(input->readUShort());
    _item1 = qSharedPointerCast<TaxCollectorInformations>(ClassManagerSingleton::get()->getClass(_id1));
    _item1->deserialize(input);
    this->dungeonTaxCollectorsInformation.append(_item1);
  }
  uint _worldTaxCollectorsInformationLen = uint(input->readUShort());
  for(uint _i2 = 0; _i2 < _worldTaxCollectorsInformationLen; _i2++)
  {
    _id2 = uint(input->readUShort());
    _item2 = qSharedPointerCast<TaxCollectorInformations>(ClassManagerSingleton::get()->getClass(_id2));
    _item2->deserialize(input);
    this->worldTaxCollectorsInformation.append(_item2);
  }
}

void TopTaxCollectorListMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TopTaxCollectorListMessage(tree);
}

void TopTaxCollectorListMessage::deserializeAsyncAs_TopTaxCollectorListMessage(FuncTree tree)
{
  this->_dungeonTaxCollectorsInformationtree = tree.addChild(std::bind(&TopTaxCollectorListMessage::_dungeonTaxCollectorsInformationtreeFunc, this, std::placeholders::_1));
  this->_worldTaxCollectorsInformationtree = tree.addChild(std::bind(&TopTaxCollectorListMessage::_worldTaxCollectorsInformationtreeFunc, this, std::placeholders::_1));
}

void TopTaxCollectorListMessage::_dungeonTaxCollectorsInformationtreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_dungeonTaxCollectorsInformationtree.addChild(std::bind(&TopTaxCollectorListMessage::_dungeonTaxCollectorsInformationFunc, this, std::placeholders::_1));
  }
}

void TopTaxCollectorListMessage::_dungeonTaxCollectorsInformationFunc(Reader *input)
{
  uint _id = uint(input->readUShort());
  QSharedPointer<TaxCollectorInformations> _item = qSharedPointerCast<TaxCollectorInformations>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->dungeonTaxCollectorsInformation.append(_item);
}

void TopTaxCollectorListMessage::_worldTaxCollectorsInformationtreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_worldTaxCollectorsInformationtree.addChild(std::bind(&TopTaxCollectorListMessage::_worldTaxCollectorsInformationFunc, this, std::placeholders::_1));
  }
}

void TopTaxCollectorListMessage::_worldTaxCollectorsInformationFunc(Reader *input)
{
  uint _id = uint(input->readUShort());
  QSharedPointer<TaxCollectorInformations> _item = qSharedPointerCast<TaxCollectorInformations>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->worldTaxCollectorsInformation.append(_item);
}

TopTaxCollectorListMessage::TopTaxCollectorListMessage()
{
  m_type = MessageEnum::TOPTAXCOLLECTORLISTMESSAGE;
}

