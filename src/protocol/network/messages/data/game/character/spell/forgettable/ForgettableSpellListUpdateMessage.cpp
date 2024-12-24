#include "ForgettableSpellListUpdateMessage.h"

void ForgettableSpellListUpdateMessage::serialize(Writer *output)
{
  this->serializeAs_ForgettableSpellListUpdateMessage(output);
}

void ForgettableSpellListUpdateMessage::serializeAs_ForgettableSpellListUpdateMessage(Writer *output)
{
  output->writeByte(this->action);
  output->writeShort((short)this->spells.size());
  for(uint _i2 = 0; _i2 < this->spells.size(); _i2++)
  {
    (this->spells[_i2]).serializeAs_ForgettableSpellItem(output);
  }
}

void ForgettableSpellListUpdateMessage::deserialize(Reader *input)
{
  this->deserializeAs_ForgettableSpellListUpdateMessage(input);
}

void ForgettableSpellListUpdateMessage::deserializeAs_ForgettableSpellListUpdateMessage(Reader *input)
{
  ForgettableSpellItem _item2 ;
  this->_actionFunc(input);
  uint _spellsLen = uint(input->readUShort());
  for(uint _i2 = 0; _i2 < _spellsLen; _i2++)
  {
    _item2 = ForgettableSpellItem();
    _item2.deserialize(input);
    this->spells.append(_item2);
  }
}

void ForgettableSpellListUpdateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ForgettableSpellListUpdateMessage(tree);
}

void ForgettableSpellListUpdateMessage::deserializeAsyncAs_ForgettableSpellListUpdateMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ForgettableSpellListUpdateMessage::_actionFunc, this, std::placeholders::_1));
  this->_spellstree = tree.addChild(std::bind(&ForgettableSpellListUpdateMessage::_spellstreeFunc, this, std::placeholders::_1));
}

void ForgettableSpellListUpdateMessage::_actionFunc(Reader *input)
{
  this->action = input->readByte();
  if(this->action < 0)
  {
    qDebug()<<"ERREUR - ForgettableSpellListUpdateMessage -"<<"Forbidden value (" << this->action << ") on element of ForgettableSpellListUpdateMessage.action.";
  }
}

void ForgettableSpellListUpdateMessage::_spellstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_spellstree.addChild(std::bind(&ForgettableSpellListUpdateMessage::_spellsFunc, this, std::placeholders::_1));
  }
}

void ForgettableSpellListUpdateMessage::_spellsFunc(Reader *input)
{
  ForgettableSpellItem _item = ForgettableSpellItem();
  _item.deserialize(input);
  this->spells.append(_item);
}

ForgettableSpellListUpdateMessage::ForgettableSpellListUpdateMessage()
{
  m_type = MessageEnum::FORGETTABLESPELLLISTUPDATEMESSAGE;
}

