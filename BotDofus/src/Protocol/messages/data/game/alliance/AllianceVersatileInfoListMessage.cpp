#include "AllianceVersatileInfoListMessage.h"

void AllianceVersatileInfoListMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceVersatileInfoListMessage(output);
}

void AllianceVersatileInfoListMessage::serializeAs_AllianceVersatileInfoListMessage(Writer *output)
{
  output->writeShort((short)this->alliances.size());
  for(uint _i1 = 0; _i1 < this->alliances.size(); _i1++)
  {
    (this->alliances[_i1]).serializeAs_AllianceVersatileInformations(output);
  }
}

void AllianceVersatileInfoListMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceVersatileInfoListMessage(input);
}

void AllianceVersatileInfoListMessage::deserializeAs_AllianceVersatileInfoListMessage(Reader *input)
{
  AllianceVersatileInformations _item1 ;
  uint _alliancesLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _alliancesLen; _i1++)
  {
    _item1 = AllianceVersatileInformations();
    _item1.deserialize(input);
    this->alliances.append(_item1);
  }
}

void AllianceVersatileInfoListMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceVersatileInfoListMessage(tree);
}

void AllianceVersatileInfoListMessage::deserializeAsyncAs_AllianceVersatileInfoListMessage(FuncTree tree)
{
  this->_alliancestree = tree.addChild(std::bind(&AllianceVersatileInfoListMessage::_alliancestreeFunc, this, std::placeholders::_1));
}

void AllianceVersatileInfoListMessage::_alliancestreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_alliancestree.addChild(std::bind(&AllianceVersatileInfoListMessage::_alliancesFunc, this, std::placeholders::_1));
  }
}

void AllianceVersatileInfoListMessage::_alliancesFunc(Reader *input)
{
  AllianceVersatileInformations _item = AllianceVersatileInformations();
  _item.deserialize(input);
  this->alliances.append(_item);
}

AllianceVersatileInfoListMessage::AllianceVersatileInfoListMessage()
{
  m_type = MessageEnum::ALLIANCEVERSATILEINFOLISTMESSAGE;
}

