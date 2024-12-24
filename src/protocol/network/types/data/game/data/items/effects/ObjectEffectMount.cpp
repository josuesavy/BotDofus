#include "ObjectEffectMount.h"

void ObjectEffectMount::serialize(Writer *output)
{
  this->serializeAs_ObjectEffectMount(output);
}

void ObjectEffectMount::serializeAs_ObjectEffectMount(Writer *output)
{
  ObjectEffect::serializeAs_ObjectEffect(output);
  uint _box0 = 0;
  _box0 = BooleanByteWrapper::setFlag(_box0, 0, this->sex);
  _box0 = BooleanByteWrapper::setFlag(_box0, 1, this->isRideable);
  _box0 = BooleanByteWrapper::setFlag(_box0, 2, this->isFeconded);
  _box0 = BooleanByteWrapper::setFlag(_box0, 3, this->isFecondationReady);
  output->writeByte(_box0);
  if(this->id < 0 || this->id > 9007199254740992)
  {
    qDebug()<<"ERREUR - ObjectEffectMount -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  output->writeVarLong((double)this->id);
  if(this->expirationDate < 0 || this->expirationDate > 9007199254740992)
  {
    qDebug()<<"ERREUR - ObjectEffectMount -"<<"Forbidden value (" << this->expirationDate << ") on element expirationDate.";
  }
  output->writeVarLong((double)this->expirationDate);
  if(this->model < 0)
  {
    qDebug()<<"ERREUR - ObjectEffectMount -"<<"Forbidden value (" << this->model << ") on element model.";
  }
  output->writeVarInt((int)this->model);
  output->writeUTF(this->name);
  output->writeUTF(this->owner);
  if(this->level < 0)
  {
    qDebug()<<"ERREUR - ObjectEffectMount -"<<"Forbidden value (" << this->level << ") on element level.";
  }
  output->writeByte(this->level);
  output->writeVarInt((int)this->reproductionCount);
  if(this->reproductionCountMax < 0)
  {
    qDebug()<<"ERREUR - ObjectEffectMount -"<<"Forbidden value (" << this->reproductionCountMax << ") on element reproductionCountMax.";
  }
  output->writeVarInt((int)this->reproductionCountMax);
  output->writeShort((short)this->effects.size());
  for(uint _i13 = 0; _i13 < this->effects.size(); _i13++)
  {
    qSharedPointerCast<ObjectEffectInteger>(this->effects[_i13])->serializeAs_ObjectEffectInteger(output);
  }
  output->writeShort((short)this->capacities.size());
  for(uint _i14 = 0; _i14 < this->capacities.size(); _i14++)
  {
    if(this->capacities[_i14] < 0)
    {
      qDebug()<<"ERREUR - ObjectEffectMount -"<<"Forbidden value (" << this->capacities[_i14] << ") on element 14 (starting at 1) of capacities.";
    }
    output->writeVarInt((int)this->capacities[_i14]);
  }
}

void ObjectEffectMount::deserialize(Reader *input)
{
  this->deserializeAs_ObjectEffectMount(input);
}

void ObjectEffectMount::deserializeAs_ObjectEffectMount(Reader *input)
{
  QSharedPointer<ObjectEffectInteger> _item13 ;
  uint _val14 = 0;
  ObjectEffect::deserialize(input);
  this->deserializeByteBoxes(input);
  this->_idFunc(input);
  this->_expirationDateFunc(input);
  this->_modelFunc(input);
  this->_nameFunc(input);
  this->_ownerFunc(input);
  this->_levelFunc(input);
  this->_reproductionCountFunc(input);
  this->_reproductionCountMaxFunc(input);
  uint _effectsLen = uint(input->readUShort());
  for(uint _i13 = 0; _i13 < _effectsLen; _i13++)
  {
    _item13 = QSharedPointer<ObjectEffectInteger>(new ObjectEffectInteger() );
    _item13->deserialize(input);
    this->effects.append(_item13);
  }
  uint _capacitiesLen = uint(input->readUShort());
  for(uint _i14 = 0; _i14 < _capacitiesLen; _i14++)
  {
    _val14 = input->readVarUhInt();
    if(_val14 < 0)
    {
      qDebug()<<"ERREUR - ObjectEffectMount -"<<"Forbidden value (" << _val14 << ") on elements of capacities.";
    }
    this->capacities.append(_val14);
  }
}

void ObjectEffectMount::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ObjectEffectMount(tree);
}

void ObjectEffectMount::deserializeAsyncAs_ObjectEffectMount(FuncTree tree)
{
  ObjectEffect::deserializeAsync(tree);
  tree.addChild(std::bind(&ObjectEffectMount::deserializeByteBoxes, this, std::placeholders::_1));
  tree.addChild(std::bind(&ObjectEffectMount::_idFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ObjectEffectMount::_expirationDateFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ObjectEffectMount::_modelFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ObjectEffectMount::_nameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ObjectEffectMount::_ownerFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ObjectEffectMount::_levelFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ObjectEffectMount::_reproductionCountFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ObjectEffectMount::_reproductionCountMaxFunc, this, std::placeholders::_1));
  this->_effectstree = tree.addChild(std::bind(&ObjectEffectMount::_effectstreeFunc, this, std::placeholders::_1));
  this->_capacitiestree = tree.addChild(std::bind(&ObjectEffectMount::_capacitiestreeFunc, this, std::placeholders::_1));
}

void ObjectEffectMount::deserializeByteBoxes(Reader *input)
{
  uint _box0 = uint(input->readByte());
  this->sex = BooleanByteWrapper::getFlag(_box0, 0);
  this->isRideable = BooleanByteWrapper::getFlag(_box0, 1);
  this->isFeconded = BooleanByteWrapper::getFlag(_box0, 2);
  this->isFecondationReady = BooleanByteWrapper::getFlag(_box0, 3);
}

void ObjectEffectMount::_idFunc(Reader *input)
{
  this->id = input->readVarUhLong();
  if(this->id < 0 || this->id > 9007199254740992)
  {
    qDebug()<<"ERREUR - ObjectEffectMount -"<<"Forbidden value (" << this->id << ") on element of ObjectEffectMount.id.";
  }
}

void ObjectEffectMount::_expirationDateFunc(Reader *input)
{
  this->expirationDate = input->readVarUhLong();
  if(this->expirationDate < 0 || this->expirationDate > 9007199254740992)
  {
    qDebug()<<"ERREUR - ObjectEffectMount -"<<"Forbidden value (" << this->expirationDate << ") on element of ObjectEffectMount.expirationDate.";
  }
}

void ObjectEffectMount::_modelFunc(Reader *input)
{
  this->model = input->readVarUhInt();
  if(this->model < 0)
  {
    qDebug()<<"ERREUR - ObjectEffectMount -"<<"Forbidden value (" << this->model << ") on element of ObjectEffectMount.model.";
  }
}

void ObjectEffectMount::_nameFunc(Reader *input)
{
  this->name = input->readUTF();
}

void ObjectEffectMount::_ownerFunc(Reader *input)
{
  this->owner = input->readUTF();
}

void ObjectEffectMount::_levelFunc(Reader *input)
{
  this->level = input->readByte();
  if(this->level < 0)
  {
    qDebug()<<"ERREUR - ObjectEffectMount -"<<"Forbidden value (" << this->level << ") on element of ObjectEffectMount.level.";
  }
}

void ObjectEffectMount::_reproductionCountFunc(Reader *input)
{
  this->reproductionCount = input->readVarInt();
}

void ObjectEffectMount::_reproductionCountMaxFunc(Reader *input)
{
  this->reproductionCountMax = input->readVarUhInt();
  if(this->reproductionCountMax < 0)
  {
    qDebug()<<"ERREUR - ObjectEffectMount -"<<"Forbidden value (" << this->reproductionCountMax << ") on element of ObjectEffectMount.reproductionCountMax.";
  }
}

void ObjectEffectMount::_effectstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_effectstree.addChild(std::bind(&ObjectEffectMount::_effectsFunc, this, std::placeholders::_1));
  }
}

void ObjectEffectMount::_effectsFunc(Reader *input)
{
  QSharedPointer<ObjectEffectInteger> _item = QSharedPointer<ObjectEffectInteger>(new ObjectEffectInteger() );
  _item->deserialize(input);
  this->effects.append(_item);
}

void ObjectEffectMount::_capacitiestreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_capacitiestree.addChild(std::bind(&ObjectEffectMount::_capacitiesFunc, this, std::placeholders::_1));
  }
}

void ObjectEffectMount::_capacitiesFunc(Reader *input)
{
  uint _val = input->readVarUhInt();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - ObjectEffectMount -"<<"Forbidden value (" << _val << ") on elements of capacities.";
  }
  this->capacities.append(_val);
}

ObjectEffectMount::ObjectEffectMount()
{
  m_types<<ClassEnum::OBJECTEFFECTMOUNT;
}

bool ObjectEffectMount::operator==(const ObjectEffectMount &compared)
{
  if(id == compared.id)
  if(expirationDate == compared.expirationDate)
  if(model == compared.model)
  if(name == compared.name)
  if(owner == compared.owner)
  if(level == compared.level)
  if(sex == compared.sex)
  if(isRideable == compared.isRideable)
  if(isFeconded == compared.isFeconded)
  if(isFecondationReady == compared.isFecondationReady)
  if(reproductionCount == compared.reproductionCount)
  if(reproductionCountMax == compared.reproductionCountMax)
  if(effects == compared.effects)
  if(capacities == compared.capacities)
  if(_effectstree == compared._effectstree)
  if(_capacitiestree == compared._capacitiestree)
  return true;
  
  return false;
}

