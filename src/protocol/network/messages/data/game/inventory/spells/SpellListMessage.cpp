#include "SpellListMessage.h"

void SpellListMessage::serialize(Writer *output)
{
  this->serializeAs_SpellListMessage(output);
}

void SpellListMessage::serializeAs_SpellListMessage(Writer *output)
{
  output->writeBool(this->spellPrevisualization);
  output->writeShort((short)this->spells.size());
  for(uint _i2 = 0; _i2 < this->spells.size(); _i2++)
  {
    (this->spells[_i2]).serializeAs_SpellItem(output);
  }
}

void SpellListMessage::deserialize(Reader *input)
{
  this->deserializeAs_SpellListMessage(input);
}

void SpellListMessage::deserializeAs_SpellListMessage(Reader *input)
{
  SpellItem _item2 ;
  this->_spellPrevisualizationFunc(input);
  uint _spellsLen = uint(input->readUShort());
  for(uint _i2 = 0; _i2 < _spellsLen; _i2++)
  {
    _item2 = SpellItem();
    _item2.deserialize(input);
    this->spells.append(_item2);
  }
}

void SpellListMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_SpellListMessage(tree);
}

void SpellListMessage::deserializeAsyncAs_SpellListMessage(FuncTree tree)
{
  tree.addChild(std::bind(&SpellListMessage::_spellPrevisualizationFunc, this, std::placeholders::_1));
  this->_spellstree = tree.addChild(std::bind(&SpellListMessage::_spellstreeFunc, this, std::placeholders::_1));
}

void SpellListMessage::_spellPrevisualizationFunc(Reader *input)
{
  this->spellPrevisualization = input->readBool();
}

void SpellListMessage::_spellstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_spellstree.addChild(std::bind(&SpellListMessage::_spellsFunc, this, std::placeholders::_1));
  }
}

void SpellListMessage::_spellsFunc(Reader *input)
{
  SpellItem _item = SpellItem();
  _item.deserialize(input);
  this->spells.append(_item);
}

SpellListMessage::SpellListMessage()
{
  m_type = MessageEnum::SPELLLISTMESSAGE;
}

