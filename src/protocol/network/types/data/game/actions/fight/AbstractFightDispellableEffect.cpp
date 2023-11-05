#include "AbstractFightDispellableEffect.h"

void AbstractFightDispellableEffect::serialize(Writer *output)
{
  this->serializeAs_AbstractFightDispellableEffect(output);
}

void AbstractFightDispellableEffect::serializeAs_AbstractFightDispellableEffect(Writer *output)
{
  if(this->uid < 0)
  {
    qDebug()<<"ERREUR - AbstractFightDispellableEffect -"<<"Forbidden value (" << this->uid << ") on element uid.";
  }
  output->writeVarInt((int)this->uid);
  if(this->targetId < -9007199254740992 || this->targetId > 9007199254740992)
  {
    qDebug()<<"ERREUR - AbstractFightDispellableEffect -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  output->writeDouble(this->targetId);
  output->writeShort((short)this->turnDuration);
  output->writeByte(this->dispelable);
  if(this->spellId < 0)
  {
    qDebug()<<"ERREUR - AbstractFightDispellableEffect -"<<"Forbidden value (" << this->spellId << ") on element spellId.";
  }
  output->writeVarShort((int)this->spellId);
  if(this->effectId < 0)
  {
    qDebug()<<"ERREUR - AbstractFightDispellableEffect -"<<"Forbidden value (" << this->effectId << ") on element effectId.";
  }
  output->writeVarInt((int)this->effectId);
  if(this->parentBoostUid < 0)
  {
    qDebug()<<"ERREUR - AbstractFightDispellableEffect -"<<"Forbidden value (" << this->parentBoostUid << ") on element parentBoostUid.";
  }
  output->writeVarInt((int)this->parentBoostUid);
}

void AbstractFightDispellableEffect::deserialize(Reader *input)
{
  this->deserializeAs_AbstractFightDispellableEffect(input);
}

void AbstractFightDispellableEffect::deserializeAs_AbstractFightDispellableEffect(Reader *input)
{
  this->_uidFunc(input);
  this->_targetIdFunc(input);
  this->_turnDurationFunc(input);
  this->_dispelableFunc(input);
  this->_spellIdFunc(input);
  this->_effectIdFunc(input);
  this->_parentBoostUidFunc(input);
}

void AbstractFightDispellableEffect::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AbstractFightDispellableEffect(tree);
}

void AbstractFightDispellableEffect::deserializeAsyncAs_AbstractFightDispellableEffect(FuncTree tree)
{
  tree.addChild(std::bind(&AbstractFightDispellableEffect::_uidFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AbstractFightDispellableEffect::_targetIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AbstractFightDispellableEffect::_turnDurationFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AbstractFightDispellableEffect::_dispelableFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AbstractFightDispellableEffect::_spellIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AbstractFightDispellableEffect::_effectIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AbstractFightDispellableEffect::_parentBoostUidFunc, this, std::placeholders::_1));
}

void AbstractFightDispellableEffect::_uidFunc(Reader *input)
{
  this->uid = input->readVarUhInt();
  if(this->uid < 0)
  {
    qDebug()<<"ERREUR - AbstractFightDispellableEffect -"<<"Forbidden value (" << this->uid << ") on element of AbstractFightDispellableEffect.uid.";
  }
}

void AbstractFightDispellableEffect::_targetIdFunc(Reader *input)
{
  this->targetId = input->readDouble();
  if(this->targetId < -9007199254740992 || this->targetId > 9007199254740992)
  {
    qDebug()<<"ERREUR - AbstractFightDispellableEffect -"<<"Forbidden value (" << this->targetId << ") on element of AbstractFightDispellableEffect.targetId.";
  }
}

void AbstractFightDispellableEffect::_turnDurationFunc(Reader *input)
{
  this->turnDuration = input->readShort();
}

void AbstractFightDispellableEffect::_dispelableFunc(Reader *input)
{
  this->dispelable = input->readByte();
  if(this->dispelable < 0)
  {
    qDebug()<<"ERREUR - AbstractFightDispellableEffect -"<<"Forbidden value (" << this->dispelable << ") on element of AbstractFightDispellableEffect.dispelable.";
  }
}

void AbstractFightDispellableEffect::_spellIdFunc(Reader *input)
{
  this->spellId = input->readVarUhShort();
  if(this->spellId < 0)
  {
    qDebug()<<"ERREUR - AbstractFightDispellableEffect -"<<"Forbidden value (" << this->spellId << ") on element of AbstractFightDispellableEffect.spellId.";
  }
}

void AbstractFightDispellableEffect::_effectIdFunc(Reader *input)
{
  this->effectId = input->readVarUhInt();
  if(this->effectId < 0)
  {
    qDebug()<<"ERREUR - AbstractFightDispellableEffect -"<<"Forbidden value (" << this->effectId << ") on element of AbstractFightDispellableEffect.effectId.";
  }
}

void AbstractFightDispellableEffect::_parentBoostUidFunc(Reader *input)
{
  this->parentBoostUid = input->readVarUhInt();
  if(this->parentBoostUid < 0)
  {
    qDebug()<<"ERREUR - AbstractFightDispellableEffect -"<<"Forbidden value (" << this->parentBoostUid << ") on element of AbstractFightDispellableEffect.parentBoostUid.";
  }
}

AbstractFightDispellableEffect::AbstractFightDispellableEffect()
{
  m_types<<ClassEnum::ABSTRACTFIGHTDISPELLABLEEFFECT;
}

bool AbstractFightDispellableEffect::operator==(const AbstractFightDispellableEffect &compared)
{
  if(uid == compared.uid)
  if(targetId == compared.targetId)
  if(turnDuration == compared.turnDuration)
  if(dispelable == compared.dispelable)
  if(spellId == compared.spellId)
  if(effectId == compared.effectId)
  if(parentBoostUid == compared.parentBoostUid)
  return true;
  
  return false;
}

