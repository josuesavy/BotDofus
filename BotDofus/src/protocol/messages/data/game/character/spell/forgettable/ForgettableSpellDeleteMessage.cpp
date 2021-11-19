#include "ForgettableSpellDeleteMessage.h"

void ForgettableSpellDeleteMessage::serialize(Writer *output)
{
  this->serializeAs_ForgettableSpellDeleteMessage(output);
}

void ForgettableSpellDeleteMessage::serializeAs_ForgettableSpellDeleteMessage(Writer *output)
{
  output->writeByte(this->reason);
  output->writeShort((short)this->spells.size());
  for(uint _i2 = 0; _i2 < this->spells.size(); _i2++)
  {
    if(this->spells[_i2] < 0)
    {
      qDebug()<<"ERREUR - ForgettableSpellDeleteMessage -"<<"Forbidden value (" << this->spells[_i2] << ") on element 2 (starting at 1) of spells.";
    }
    output->writeInt((int)this->spells[_i2]);
  }
}

void ForgettableSpellDeleteMessage::deserialize(Reader *input)
{
  this->deserializeAs_ForgettableSpellDeleteMessage(input);
}

void ForgettableSpellDeleteMessage::deserializeAs_ForgettableSpellDeleteMessage(Reader *input)
{
  uint _val2 = 0;
  this->_reasonFunc(input);
  uint _spellsLen = input->readUShort();
  for(uint _i2 = 0; _i2 < _spellsLen; _i2++)
  {
    _val2 = input->readInt();
    if(_val2 < 0)
    {
      qDebug()<<"ERREUR - ForgettableSpellDeleteMessage -"<<"Forbidden value (" << _val2 << ") on elements of spells.";
    }
    this->spells.append(_val2);
  }
}

void ForgettableSpellDeleteMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ForgettableSpellDeleteMessage(tree);
}

void ForgettableSpellDeleteMessage::deserializeAsyncAs_ForgettableSpellDeleteMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ForgettableSpellDeleteMessage::_reasonFunc, this, std::placeholders::_1));
  this->_spellstree = tree.addChild(std::bind(&ForgettableSpellDeleteMessage::_spellstreeFunc, this, std::placeholders::_1));
}

void ForgettableSpellDeleteMessage::_reasonFunc(Reader *input)
{
  this->reason = input->readByte();
  if(this->reason < 0)
  {
    qDebug()<<"ERREUR - ForgettableSpellDeleteMessage -"<<"Forbidden value (" << this->reason << ") on element of ForgettableSpellDeleteMessage.reason.";
  }
}

void ForgettableSpellDeleteMessage::_spellstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_spellstree.addChild(std::bind(&ForgettableSpellDeleteMessage::_spellsFunc, this, std::placeholders::_1));
  }
}

void ForgettableSpellDeleteMessage::_spellsFunc(Reader *input)
{
  uint _val = input->readInt();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - ForgettableSpellDeleteMessage -"<<"Forbidden value (" << _val << ") on elements of spells.";
  }
  this->spells.append(_val);
}

ForgettableSpellDeleteMessage::ForgettableSpellDeleteMessage()
{
  m_type = MessageEnum::FORGETTABLESPELLDELETEMESSAGE;
}

