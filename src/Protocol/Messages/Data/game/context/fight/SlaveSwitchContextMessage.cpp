#include "SlaveSwitchContextMessage.h"

void SlaveSwitchContextMessage::serialize(Writer *output)
{
  this->serializeAs_SlaveSwitchContextMessage(output);
}

void SlaveSwitchContextMessage::serializeAs_SlaveSwitchContextMessage(Writer *output)
{
  if(this->masterId < -9.007199254740992E15 || this->masterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - SlaveSwitchContextMessage -"<<"Forbidden value (" << this->masterId << ") on element masterId.";
  }
  output->writeDouble(this->masterId);
  if(this->slaveId < -9.007199254740992E15 || this->slaveId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - SlaveSwitchContextMessage -"<<"Forbidden value (" << this->slaveId << ") on element slaveId.";
  }
  output->writeDouble(this->slaveId);
  output->writeShort((short)this->slaveSpells.size());
  for(uint _i3 = 0; _i3 < this->slaveSpells.size(); _i3++)
  {
    (this->slaveSpells[_i3]).serializeAs_SpellItem(output);
  }
  this->slaveStats.serializeAs_CharacterCharacteristicsInformations(output);
  output->writeShort((short)this->shortcuts.size());
  for(uint _i5 = 0; _i5 < this->shortcuts.size(); _i5++)
  {
    output->writeShort((short)qSharedPointerCast<Shortcut>(this->shortcuts[_i5])->getTypes().last());
    qSharedPointerCast<Shortcut>(this->shortcuts[_i5])->serialize(output);
  }
}

void SlaveSwitchContextMessage::deserialize(Reader *input)
{
  this->deserializeAs_SlaveSwitchContextMessage(input);
}

void SlaveSwitchContextMessage::deserializeAs_SlaveSwitchContextMessage(Reader *input)
{
  SpellItem _item3 ;
  uint _id5 = 0;
  QSharedPointer<Shortcut> _item5 ;
  this->_masterIdFunc(input);
  this->_slaveIdFunc(input);
  uint _slaveSpellsLen = input->readUShort();
  for(uint _i3 = 0; _i3 < _slaveSpellsLen; _i3++)
  {
    _item3 = SpellItem();
    _item3.deserialize(input);
    this->slaveSpells.append(_item3);
  }
  this->slaveStats = CharacterCharacteristicsInformations();
  this->slaveStats.deserialize(input);
  uint _shortcutsLen = input->readUShort();
  for(uint _i5 = 0; _i5 < _shortcutsLen; _i5++)
  {
    _id5 = input->readUShort();
    _item5 = qSharedPointerCast<Shortcut>(ClassManagerSingleton::get()->getClass(_id5));
    _item5->deserialize(input);
    this->shortcuts.append(_item5);
  }
}

void SlaveSwitchContextMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_SlaveSwitchContextMessage(tree);
}

void SlaveSwitchContextMessage::deserializeAsyncAs_SlaveSwitchContextMessage(FuncTree tree)
{
  tree.addChild(std::bind(&SlaveSwitchContextMessage::_masterIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&SlaveSwitchContextMessage::_slaveIdFunc, this, std::placeholders::_1));
  this->_slaveSpellstree = tree.addChild(std::bind(&SlaveSwitchContextMessage::_slaveSpellstreeFunc, this, std::placeholders::_1));
  this->_slaveStatstree = tree.addChild(std::bind(&SlaveSwitchContextMessage::_slaveStatstreeFunc, this, std::placeholders::_1));
  this->_shortcutstree = tree.addChild(std::bind(&SlaveSwitchContextMessage::_shortcutstreeFunc, this, std::placeholders::_1));
}

void SlaveSwitchContextMessage::_masterIdFunc(Reader *input)
{
  this->masterId = input->readDouble();
  if(this->masterId < -9.007199254740992E15 || this->masterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - SlaveSwitchContextMessage -"<<"Forbidden value (" << this->masterId << ") on element of SlaveSwitchContextMessage.masterId.";
  }
}

void SlaveSwitchContextMessage::_slaveIdFunc(Reader *input)
{
  this->slaveId = input->readDouble();
  if(this->slaveId < -9.007199254740992E15 || this->slaveId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - SlaveSwitchContextMessage -"<<"Forbidden value (" << this->slaveId << ") on element of SlaveSwitchContextMessage.slaveId.";
  }
}

void SlaveSwitchContextMessage::_slaveSpellstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_slaveSpellstree.addChild(std::bind(&SlaveSwitchContextMessage::_slaveSpellsFunc, this, std::placeholders::_1));
  }
}

void SlaveSwitchContextMessage::_slaveSpellsFunc(Reader *input)
{
  SpellItem _item = SpellItem();
  _item.deserialize(input);
  this->slaveSpells.append(_item);
}

void SlaveSwitchContextMessage::_slaveStatstreeFunc(Reader *input)
{
  this->slaveStats = CharacterCharacteristicsInformations();
  this->slaveStats.deserializeAsync(this->_slaveStatstree);
}

void SlaveSwitchContextMessage::_shortcutstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_shortcutstree.addChild(std::bind(&SlaveSwitchContextMessage::_shortcutsFunc, this, std::placeholders::_1));
  }
}

void SlaveSwitchContextMessage::_shortcutsFunc(Reader *input)
{
  uint _id = input->readUShort();
  QSharedPointer<Shortcut> _item = qSharedPointerCast<Shortcut>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->shortcuts.append(_item);
}

SlaveSwitchContextMessage::SlaveSwitchContextMessage()
{
  m_type = MessageEnum::SLAVESWITCHCONTEXTMESSAGE;
}

