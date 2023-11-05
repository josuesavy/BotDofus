#include "AllianceInsiderInfoMessage.h"

void AllianceInsiderInfoMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceInsiderInfoMessage(output);
}

void AllianceInsiderInfoMessage::serializeAs_AllianceInsiderInfoMessage(Writer *output)
{
  this->allianceInfos->serializeAs_AllianceFactSheetInformation(output);
  output->writeShort((short)this->members.size());
  for(uint _i2 = 0; _i2 < this->members.size(); _i2++)
  {
    qSharedPointerCast<AllianceMemberInfo>(this->members[_i2])->serializeAs_AllianceMemberInfo(output);
  }
  output->writeShort((short)this->prisms.size());
  for(uint _i3 = 0; _i3 < this->prisms.size(); _i3++)
  {
    output->writeShort((short)qSharedPointerCast<PrismGeolocalizedInformation>(this->prisms[_i3])->getTypes().last());
    qSharedPointerCast<PrismGeolocalizedInformation>(this->prisms[_i3])->serialize(output);
  }
  output->writeShort((short)this->taxCollectors.size());
  for(uint _i4 = 0; _i4 < this->taxCollectors.size(); _i4++)
  {
    qSharedPointerCast<TaxCollectorInformations>(this->taxCollectors[_i4])->serializeAs_TaxCollectorInformations(output);
  }
}

void AllianceInsiderInfoMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceInsiderInfoMessage(input);
}

void AllianceInsiderInfoMessage::deserializeAs_AllianceInsiderInfoMessage(Reader *input)
{
  QSharedPointer<AllianceMemberInfo> _item2 ;
  uint _id3 = 0;
  QSharedPointer<PrismGeolocalizedInformation> _item3 ;
  QSharedPointer<TaxCollectorInformations> _item4 ;
  this->allianceInfos = QSharedPointer<AllianceFactSheetInformation>(new AllianceFactSheetInformation() );
  this->allianceInfos->deserialize(input);
  uint _membersLen = uint(input->readUShort());
  for(uint _i2 = 0; _i2 < _membersLen; _i2++)
  {
    _item2 = QSharedPointer<AllianceMemberInfo>(new AllianceMemberInfo() );
    _item2->deserialize(input);
    this->members.append(_item2);
  }
  uint _prismsLen = uint(input->readUShort());
  for(uint _i3 = 0; _i3 < _prismsLen; _i3++)
  {
    _id3 = uint(input->readUShort());
    _item3 = qSharedPointerCast<PrismGeolocalizedInformation>(ClassManagerSingleton::get()->getClass(_id3));
    _item3->deserialize(input);
    this->prisms.append(_item3);
  }
  uint _taxCollectorsLen = uint(input->readUShort());
  for(uint _i4 = 0; _i4 < _taxCollectorsLen; _i4++)
  {
    _item4 = QSharedPointer<TaxCollectorInformations>(new TaxCollectorInformations() );
    _item4->deserialize(input);
    this->taxCollectors.append(_item4);
  }
}

void AllianceInsiderInfoMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceInsiderInfoMessage(tree);
}

void AllianceInsiderInfoMessage::deserializeAsyncAs_AllianceInsiderInfoMessage(FuncTree tree)
{
  this->_allianceInfostree = tree.addChild(std::bind(&AllianceInsiderInfoMessage::_allianceInfostreeFunc, this, std::placeholders::_1));
  this->_memberstree = tree.addChild(std::bind(&AllianceInsiderInfoMessage::_memberstreeFunc, this, std::placeholders::_1));
  this->_prismstree = tree.addChild(std::bind(&AllianceInsiderInfoMessage::_prismstreeFunc, this, std::placeholders::_1));
  this->_taxCollectorstree = tree.addChild(std::bind(&AllianceInsiderInfoMessage::_taxCollectorstreeFunc, this, std::placeholders::_1));
}

void AllianceInsiderInfoMessage::_allianceInfostreeFunc(Reader *input)
{
  this->allianceInfos = QSharedPointer<AllianceFactSheetInformation>(new AllianceFactSheetInformation() );
  this->allianceInfos->deserializeAsync(this->_allianceInfostree);
}

void AllianceInsiderInfoMessage::_memberstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_memberstree.addChild(std::bind(&AllianceInsiderInfoMessage::_membersFunc, this, std::placeholders::_1));
  }
}

void AllianceInsiderInfoMessage::_membersFunc(Reader *input)
{
  QSharedPointer<AllianceMemberInfo> _item = QSharedPointer<AllianceMemberInfo>(new AllianceMemberInfo() );
  _item->deserialize(input);
  this->members.append(_item);
}

void AllianceInsiderInfoMessage::_prismstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_prismstree.addChild(std::bind(&AllianceInsiderInfoMessage::_prismsFunc, this, std::placeholders::_1));
  }
}

void AllianceInsiderInfoMessage::_prismsFunc(Reader *input)
{
  uint _id = uint(input->readUShort());
  QSharedPointer<PrismGeolocalizedInformation> _item = qSharedPointerCast<PrismGeolocalizedInformation>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->prisms.append(_item);
}

void AllianceInsiderInfoMessage::_taxCollectorstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_taxCollectorstree.addChild(std::bind(&AllianceInsiderInfoMessage::_taxCollectorsFunc, this, std::placeholders::_1));
  }
}

void AllianceInsiderInfoMessage::_taxCollectorsFunc(Reader *input)
{
  QSharedPointer<TaxCollectorInformations> _item = QSharedPointer<TaxCollectorInformations>(new TaxCollectorInformations() );
  _item->deserialize(input);
  this->taxCollectors.append(_item);
}

AllianceInsiderInfoMessage::AllianceInsiderInfoMessage()
{
  m_type = MessageEnum::ALLIANCEINSIDERINFOMESSAGE;
}

