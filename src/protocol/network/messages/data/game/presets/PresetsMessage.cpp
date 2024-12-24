#include "PresetsMessage.h"

void PresetsMessage::serialize(Writer *output)
{
  this->serializeAs_PresetsMessage(output);
}

void PresetsMessage::serializeAs_PresetsMessage(Writer *output)
{
  output->writeShort((short)this->presets.size());
  for(uint _i1 = 0; _i1 < this->presets.size(); _i1++)
  {
    output->writeShort((short)qSharedPointerCast<Preset>(this->presets[_i1])->getTypes().last());
    qSharedPointerCast<Preset>(this->presets[_i1])->serialize(output);
  }
}

void PresetsMessage::deserialize(Reader *input)
{
  this->deserializeAs_PresetsMessage(input);
}

void PresetsMessage::deserializeAs_PresetsMessage(Reader *input)
{
  uint _id1 = 0;
  QSharedPointer<Preset> _item1 ;
  uint _presetsLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _presetsLen; _i1++)
  {
    _id1 = uint(input->readUShort());
    _item1 = qSharedPointerCast<Preset>(ClassManagerSingleton::get()->getClass(_id1));
    _item1->deserialize(input);
    this->presets.append(_item1);
  }
}

void PresetsMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PresetsMessage(tree);
}

void PresetsMessage::deserializeAsyncAs_PresetsMessage(FuncTree tree)
{
  this->_presetstree = tree.addChild(std::bind(&PresetsMessage::_presetstreeFunc, this, std::placeholders::_1));
}

void PresetsMessage::_presetstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_presetstree.addChild(std::bind(&PresetsMessage::_presetsFunc, this, std::placeholders::_1));
  }
}

void PresetsMessage::_presetsFunc(Reader *input)
{
  uint _id = uint(input->readUShort());
  QSharedPointer<Preset> _item = qSharedPointerCast<Preset>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->presets.append(_item);
}

PresetsMessage::PresetsMessage()
{
  m_type = MessageEnum::PRESETSMESSAGE;
}

