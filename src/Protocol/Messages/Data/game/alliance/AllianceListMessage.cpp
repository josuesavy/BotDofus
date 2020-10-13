#include "AllianceListMessage.h"

void AllianceListMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceListMessage(output);
}

void AllianceListMessage::serializeAs_AllianceListMessage(Writer *output)
{
  output->writeShort((short)this->alliances.size());
  for(uint _i1 = 0; _i1 < this->alliances.size(); _i1++)
  {
    qSharedPointerCast<AllianceFactSheetInformations>(this->alliances[_i1])->serializeAs_AllianceFactSheetInformations(output);
  }
}

void AllianceListMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceListMessage(input);
}

void AllianceListMessage::deserializeAs_AllianceListMessage(Reader *input)
{
  QSharedPointer<AllianceFactSheetInformations> _item1 ;
  uint _alliancesLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _alliancesLen; _i1++)
  {
    _item1 = QSharedPointer<AllianceFactSheetInformations>(new AllianceFactSheetInformations() );
    _item1->deserialize(input);
    this->alliances.append(_item1);
  }
}

void AllianceListMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceListMessage(tree);
}

void AllianceListMessage::deserializeAsyncAs_AllianceListMessage(FuncTree tree)
{
  this->_alliancestree = tree.addChild(std::bind(&AllianceListMessage::_alliancestreeFunc, this, std::placeholders::_1));
}

void AllianceListMessage::_alliancestreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_alliancestree.addChild(std::bind(&AllianceListMessage::_alliancesFunc, this, std::placeholders::_1));
  }
}

void AllianceListMessage::_alliancesFunc(Reader *input)
{
  QSharedPointer<AllianceFactSheetInformations> _item = QSharedPointer<AllianceFactSheetInformations>(new AllianceFactSheetInformations() );
  _item->deserialize(input);
  this->alliances.append(_item);
}

AllianceListMessage::AllianceListMessage()
{
  m_type = MessageEnum::ALLIANCELISTMESSAGE;
}

