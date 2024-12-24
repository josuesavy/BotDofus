#include "TaxCollectorPresetsMessage.h"

void TaxCollectorPresetsMessage::serialize(Writer *output)
{
  this->serializeAs_TaxCollectorPresetsMessage(output);
}

void TaxCollectorPresetsMessage::serializeAs_TaxCollectorPresetsMessage(Writer *output)
{
  output->writeShort((short)this->presets.size());
  for(uint _i1 = 0; _i1 < this->presets.size(); _i1++)
  {
    qSharedPointerCast<TaxCollectorPreset>(this->presets[_i1])->serializeAs_TaxCollectorPreset(output);
  }
}

void TaxCollectorPresetsMessage::deserialize(Reader *input)
{
  this->deserializeAs_TaxCollectorPresetsMessage(input);
}

void TaxCollectorPresetsMessage::deserializeAs_TaxCollectorPresetsMessage(Reader *input)
{
  QSharedPointer<TaxCollectorPreset> _item1 ;
  uint _presetsLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _presetsLen; _i1++)
  {
    _item1 = QSharedPointer<TaxCollectorPreset>(new TaxCollectorPreset() );
    _item1->deserialize(input);
    this->presets.append(_item1);
  }
}

void TaxCollectorPresetsMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TaxCollectorPresetsMessage(tree);
}

void TaxCollectorPresetsMessage::deserializeAsyncAs_TaxCollectorPresetsMessage(FuncTree tree)
{
  this->_presetstree = tree.addChild(std::bind(&TaxCollectorPresetsMessage::_presetstreeFunc, this, std::placeholders::_1));
}

void TaxCollectorPresetsMessage::_presetstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_presetstree.addChild(std::bind(&TaxCollectorPresetsMessage::_presetsFunc, this, std::placeholders::_1));
  }
}

void TaxCollectorPresetsMessage::_presetsFunc(Reader *input)
{
  QSharedPointer<TaxCollectorPreset> _item = QSharedPointer<TaxCollectorPreset>(new TaxCollectorPreset() );
  _item->deserialize(input);
  this->presets.append(_item);
}

TaxCollectorPresetsMessage::TaxCollectorPresetsMessage()
{
  m_type = MessageEnum::TAXCOLLECTORPRESETSMESSAGE;
}

