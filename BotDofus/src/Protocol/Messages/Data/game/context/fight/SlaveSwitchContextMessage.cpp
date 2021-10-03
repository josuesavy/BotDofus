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
  if(this->slaveTurn < 0)
  {
    qDebug()<<"ERREUR - SlaveSwitchContextMessage -"<<"Forbidden value (" << this->slaveTurn << ") on element slaveTurn.";
  }
  output->writeVarShort((int)this->slaveTurn);
  output->writeShort((short)this->slaveSpells.size());
  for(uint _i4 = 0; _i4 < this->slaveSpells.size(); _i4++)
  {
    (this->slaveSpells[_i4]).serializeAs_SpellItem(output);
  }
  this->slaveStats->serializeAs_CharacterCharacteristicsInformations(output);
  output->writeShort((short)this->shortcuts.size());
  for(uint _i6 = 0; _i6 < this->shortcuts.size(); _i6++)
  {
    output->writeShort((short)qSharedPointerCast<Shortcut>(this->shortcuts[_i6])->getTypes().last());
    qSharedPointerCast<Shortcut>(this->shortcuts[_i6])->serialize(output);
  }
}

void SlaveSwitchContextMessage::deserialize(Reader *input)
{
  this->deserializeAs_SlaveSwitchContextMessage(input);
}

void SlaveSwitchContextMessage::deserializeAs_SlaveSwitchContextMessage(Reader *input)
{
  SpellItem _item4 ;
  uint _id6 = 0;
  QSharedPointer<Shortcut> _item6 ;
  this->_masterIdFunc(input);
  this->_slaveIdFunc(input);
  this->_slaveTurnFunc(input);
  uint _slaveSpellsLen = input->readUShort();
  for(uint _i4 = 0; _i4 < _slaveSpellsLen; _i4++)
  {
    _item4 = SpellItem();
    _item4.deserialize(input);
    this->slaveSpells.append(_item4);
  }
  this->slaveStats = QSharedPointer<CharacterCharacteristicsInformations>(new CharacterCharacteristicsInformations() );
  this->slaveStats->deserialize(input);
  uint _shortcutsLen = input->readUShort();
  for(uint _i6 = 0; _i6 < _shortcutsLen; _i6++)
  {
    _id6 = input->readUShort();
    _item6 = qSharedPointerCast<Shortcut>(ClassManagerSingleton::get()->getClass(_id6));
    _item6->deserialize(input);
    this->shortcuts.append(_item6);
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
  tree.addChild(std::bind(&SlaveSwitchContextMessage::_slaveTurnFunc, this, std::placeholders::_1));
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

void SlaveSwitchContextMessage::_slaveTurnFunc(Reader *input)
{
  this->slaveTurn = input->readVarUhShort();
  if(this->slaveTurn < 0)
  {
    qDebug()<<"ERREUR - SlaveSwitchContextMessage -"<<"Forbidden value (" << this->slaveTurn << ") on element of SlaveSwitchContextMessage.slaveTurn.";
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
  this->slaveStats = QSharedPointer<CharacterCharacteristicsInformations>(new CharacterCharacteristicsInformations() );
  this->slaveStats->deserializeAsync(this->_slaveStatstree);
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

