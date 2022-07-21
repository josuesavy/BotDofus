#include "MountClientData.h"

void MountClientData::serialize(Writer *output)
{
  this->serializeAs_MountClientData(output);
}

void MountClientData::serializeAs_MountClientData(Writer *output)
{
  uint _box0 = 0;
  _box0 = BooleanByteWrapper::setFlag(_box0, 0, this->sex);
  _box0 = BooleanByteWrapper::setFlag(_box0, 1, this->isRideable);
  _box0 = BooleanByteWrapper::setFlag(_box0, 2, this->isWild);
  _box0 = BooleanByteWrapper::setFlag(_box0, 3, this->isFecondationReady);
  _box0 = BooleanByteWrapper::setFlag(_box0, 4, this->useHarnessColors);
  output->writeByte(_box0);
  if(this->id < -9.007199254740992E15 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  output->writeDouble(this->id);
  if(this->model < 0)
  {
    qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->model << ") on element model.";
  }
  output->writeVarInt((int)this->model);
  output->writeShort((short)this->ancestor.size());
  for(uint _i3 = 0; _i3 < this->ancestor.size(); _i3++)
  {
    if(this->ancestor[_i3] < 0)
    {
      qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->ancestor[_i3] << ") on element 3 (starting at 1) of ancestor.";
    }
    output->writeInt((int)this->ancestor[_i3]);
  }
  output->writeShort((short)this->behaviors.size());
  for(uint _i4 = 0; _i4 < this->behaviors.size(); _i4++)
  {
    if(this->behaviors[_i4] < 0)
    {
      qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->behaviors[_i4] << ") on element 4 (starting at 1) of behaviors.";
    }
    output->writeInt((int)this->behaviors[_i4]);
  }
  output->writeUTF(this->name);
  if(this->ownerId < 0)
  {
    qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->ownerId << ") on element ownerId.";
  }
  output->writeInt((int)this->ownerId);
  if(this->experience < 0 || this->experience > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->experience << ") on element experience.";
  }
  output->writeVarLong((double)this->experience);
  if(this->experienceForLevel < 0 || this->experienceForLevel > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->experienceForLevel << ") on element experienceForLevel.";
  }
  output->writeVarLong((double)this->experienceForLevel);
  if(this->experienceForNextLevel < -9.007199254740992E15 || this->experienceForNextLevel > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->experienceForNextLevel << ") on element experienceForNextLevel.";
  }
  output->writeDouble(this->experienceForNextLevel);
  if(this->level < 0)
  {
    qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->level << ") on element level.";
  }
  output->writeByte(this->level);
  if(this->maxPods < 0)
  {
    qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->maxPods << ") on element maxPods.";
  }
  output->writeVarInt((int)this->maxPods);
  if(this->stamina < 0)
  {
    qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->stamina << ") on element stamina.";
  }
  output->writeVarInt((int)this->stamina);
  if(this->staminaMax < 0)
  {
    qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->staminaMax << ") on element staminaMax.";
  }
  output->writeVarInt((int)this->staminaMax);
  if(this->maturity < 0)
  {
    qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->maturity << ") on element maturity.";
  }
  output->writeVarInt((int)this->maturity);
  if(this->maturityForAdult < 0)
  {
    qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->maturityForAdult << ") on element maturityForAdult.";
  }
  output->writeVarInt((int)this->maturityForAdult);
  if(this->energy < 0)
  {
    qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->energy << ") on element energy.";
  }
  output->writeVarInt((int)this->energy);
  if(this->energyMax < 0)
  {
    qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->energyMax << ") on element energyMax.";
  }
  output->writeVarInt((int)this->energyMax);
  output->writeInt((int)this->serenity);
  output->writeInt((int)this->aggressivityMax);
  if(this->serenityMax < 0)
  {
    qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->serenityMax << ") on element serenityMax.";
  }
  output->writeVarInt((int)this->serenityMax);
  if(this->love < 0)
  {
    qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->love << ") on element love.";
  }
  output->writeVarInt((int)this->love);
  if(this->loveMax < 0)
  {
    qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->loveMax << ") on element loveMax.";
  }
  output->writeVarInt((int)this->loveMax);
  output->writeInt((int)this->fecondationTime);
  if(this->boostLimiter < 0)
  {
    qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->boostLimiter << ") on element boostLimiter.";
  }
  output->writeInt((int)this->boostLimiter);
  if(this->boostMax < -9.007199254740992E15 || this->boostMax > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->boostMax << ") on element boostMax.";
  }
  output->writeDouble(this->boostMax);
  output->writeInt((int)this->reproductionCount);
  if(this->reproductionCountMax < 0)
  {
    qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->reproductionCountMax << ") on element reproductionCountMax.";
  }
  output->writeVarInt((int)this->reproductionCountMax);
  if(this->harnessGID < 0)
  {
    qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->harnessGID << ") on element harnessGID.";
  }
  output->writeVarInt((int)this->harnessGID);
  output->writeShort((short)this->effectList.size());
  for(uint _i34 = 0; _i34 < this->effectList.size(); _i34++)
  {
    qSharedPointerCast<ObjectEffectInteger>(this->effectList[_i34])->serializeAs_ObjectEffectInteger(output);
  }
}

void MountClientData::deserialize(Reader *input)
{
  this->deserializeAs_MountClientData(input);
}

void MountClientData::deserializeAs_MountClientData(Reader *input)
{
  uint _val3 = 0;
  uint _val4 = 0;
  QSharedPointer<ObjectEffectInteger> _item34 ;
  this->deserializeByteBoxes(input);
  this->_idFunc(input);
  this->_modelFunc(input);
  uint _ancestorLen = input->readUShort();
  for(uint _i3 = 0; _i3 < _ancestorLen; _i3++)
  {
    _val3 = input->readInt();
    if(_val3 < 0)
    {
      qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << _val3 << ") on elements of ancestor.";
    }
    this->ancestor.append(_val3);
  }
  uint _behaviorsLen = input->readUShort();
  for(uint _i4 = 0; _i4 < _behaviorsLen; _i4++)
  {
    _val4 = input->readInt();
    if(_val4 < 0)
    {
      qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << _val4 << ") on elements of behaviors.";
    }
    this->behaviors.append(_val4);
  }
  this->_nameFunc(input);
  this->_ownerIdFunc(input);
  this->_experienceFunc(input);
  this->_experienceForLevelFunc(input);
  this->_experienceForNextLevelFunc(input);
  this->_levelFunc(input);
  this->_maxPodsFunc(input);
  this->_staminaFunc(input);
  this->_staminaMaxFunc(input);
  this->_maturityFunc(input);
  this->_maturityForAdultFunc(input);
  this->_energyFunc(input);
  this->_energyMaxFunc(input);
  this->_serenityFunc(input);
  this->_aggressivityMaxFunc(input);
  this->_serenityMaxFunc(input);
  this->_loveFunc(input);
  this->_loveMaxFunc(input);
  this->_fecondationTimeFunc(input);
  this->_boostLimiterFunc(input);
  this->_boostMaxFunc(input);
  this->_reproductionCountFunc(input);
  this->_reproductionCountMaxFunc(input);
  this->_harnessGIDFunc(input);
  uint _effectListLen = input->readUShort();
  for(uint _i34 = 0; _i34 < _effectListLen; _i34++)
  {
    _item34 = QSharedPointer<ObjectEffectInteger>(new ObjectEffectInteger() );
    _item34->deserialize(input);
    this->effectList.append(_item34);
  }
}

void MountClientData::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_MountClientData(tree);
}

void MountClientData::deserializeAsyncAs_MountClientData(FuncTree tree)
{
  tree.addChild(std::bind(&MountClientData::deserializeByteBoxes, this, std::placeholders::_1));
  tree.addChild(std::bind(&MountClientData::_idFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&MountClientData::_modelFunc, this, std::placeholders::_1));
  this->_ancestortree = tree.addChild(std::bind(&MountClientData::_ancestortreeFunc, this, std::placeholders::_1));
  this->_behaviorstree = tree.addChild(std::bind(&MountClientData::_behaviorstreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&MountClientData::_nameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&MountClientData::_ownerIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&MountClientData::_experienceFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&MountClientData::_experienceForLevelFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&MountClientData::_experienceForNextLevelFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&MountClientData::_levelFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&MountClientData::_maxPodsFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&MountClientData::_staminaFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&MountClientData::_staminaMaxFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&MountClientData::_maturityFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&MountClientData::_maturityForAdultFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&MountClientData::_energyFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&MountClientData::_energyMaxFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&MountClientData::_serenityFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&MountClientData::_aggressivityMaxFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&MountClientData::_serenityMaxFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&MountClientData::_loveFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&MountClientData::_loveMaxFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&MountClientData::_fecondationTimeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&MountClientData::_boostLimiterFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&MountClientData::_boostMaxFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&MountClientData::_reproductionCountFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&MountClientData::_reproductionCountMaxFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&MountClientData::_harnessGIDFunc, this, std::placeholders::_1));
  this->_effectListtree = tree.addChild(std::bind(&MountClientData::_effectListtreeFunc, this, std::placeholders::_1));
}

void MountClientData::deserializeByteBoxes(Reader *input)
{
  uint _box0 = input->readByte();
  this->sex = BooleanByteWrapper::getFlag(_box0, 0);
  this->isRideable = BooleanByteWrapper::getFlag(_box0, 1);
  this->isWild = BooleanByteWrapper::getFlag(_box0, 2);
  this->isFecondationReady = BooleanByteWrapper::getFlag(_box0, 3);
  this->useHarnessColors = BooleanByteWrapper::getFlag(_box0, 4);
}

void MountClientData::_idFunc(Reader *input)
{
  this->id = input->readDouble();
  if(this->id < -9.007199254740992E15 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->id << ") on element of MountClientData.id.";
  }
}

void MountClientData::_modelFunc(Reader *input)
{
  this->model = input->readVarUhInt();
  if(this->model < 0)
  {
    qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->model << ") on element of MountClientData.model.";
  }
}

void MountClientData::_ancestortreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_ancestortree.addChild(std::bind(&MountClientData::_ancestorFunc, this, std::placeholders::_1));
  }
}

void MountClientData::_ancestorFunc(Reader *input)
{
  uint _val = input->readInt();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << _val << ") on elements of ancestor.";
  }
  this->ancestor.append(_val);
}

void MountClientData::_behaviorstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_behaviorstree.addChild(std::bind(&MountClientData::_behaviorsFunc, this, std::placeholders::_1));
  }
}

void MountClientData::_behaviorsFunc(Reader *input)
{
  uint _val = input->readInt();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << _val << ") on elements of behaviors.";
  }
  this->behaviors.append(_val);
}

void MountClientData::_nameFunc(Reader *input)
{
  this->name = input->readUTF();
}

void MountClientData::_ownerIdFunc(Reader *input)
{
  this->ownerId = input->readInt();
  if(this->ownerId < 0)
  {
    qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->ownerId << ") on element of MountClientData.ownerId.";
  }
}

void MountClientData::_experienceFunc(Reader *input)
{
  this->experience = input->readVarUhLong();
  if(this->experience < 0 || this->experience > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->experience << ") on element of MountClientData.experience.";
  }
}

void MountClientData::_experienceForLevelFunc(Reader *input)
{
  this->experienceForLevel = input->readVarUhLong();
  if(this->experienceForLevel < 0 || this->experienceForLevel > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->experienceForLevel << ") on element of MountClientData.experienceForLevel.";
  }
}

void MountClientData::_experienceForNextLevelFunc(Reader *input)
{
  this->experienceForNextLevel = input->readDouble();
  if(this->experienceForNextLevel < -9.007199254740992E15 || this->experienceForNextLevel > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->experienceForNextLevel << ") on element of MountClientData.experienceForNextLevel.";
  }
}

void MountClientData::_levelFunc(Reader *input)
{
  this->level = input->readByte();
  if(this->level < 0)
  {
    qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->level << ") on element of MountClientData.level.";
  }
}

void MountClientData::_maxPodsFunc(Reader *input)
{
  this->maxPods = input->readVarUhInt();
  if(this->maxPods < 0)
  {
    qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->maxPods << ") on element of MountClientData.maxPods.";
  }
}

void MountClientData::_staminaFunc(Reader *input)
{
  this->stamina = input->readVarUhInt();
  if(this->stamina < 0)
  {
    qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->stamina << ") on element of MountClientData.stamina.";
  }
}

void MountClientData::_staminaMaxFunc(Reader *input)
{
  this->staminaMax = input->readVarUhInt();
  if(this->staminaMax < 0)
  {
    qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->staminaMax << ") on element of MountClientData.staminaMax.";
  }
}

void MountClientData::_maturityFunc(Reader *input)
{
  this->maturity = input->readVarUhInt();
  if(this->maturity < 0)
  {
    qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->maturity << ") on element of MountClientData.maturity.";
  }
}

void MountClientData::_maturityForAdultFunc(Reader *input)
{
  this->maturityForAdult = input->readVarUhInt();
  if(this->maturityForAdult < 0)
  {
    qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->maturityForAdult << ") on element of MountClientData.maturityForAdult.";
  }
}

void MountClientData::_energyFunc(Reader *input)
{
  this->energy = input->readVarUhInt();
  if(this->energy < 0)
  {
    qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->energy << ") on element of MountClientData.energy.";
  }
}

void MountClientData::_energyMaxFunc(Reader *input)
{
  this->energyMax = input->readVarUhInt();
  if(this->energyMax < 0)
  {
    qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->energyMax << ") on element of MountClientData.energyMax.";
  }
}

void MountClientData::_serenityFunc(Reader *input)
{
  this->serenity = input->readInt();
}

void MountClientData::_aggressivityMaxFunc(Reader *input)
{
  this->aggressivityMax = input->readInt();
}

void MountClientData::_serenityMaxFunc(Reader *input)
{
  this->serenityMax = input->readVarUhInt();
  if(this->serenityMax < 0)
  {
    qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->serenityMax << ") on element of MountClientData.serenityMax.";
  }
}

void MountClientData::_loveFunc(Reader *input)
{
  this->love = input->readVarUhInt();
  if(this->love < 0)
  {
    qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->love << ") on element of MountClientData.love.";
  }
}

void MountClientData::_loveMaxFunc(Reader *input)
{
  this->loveMax = input->readVarUhInt();
  if(this->loveMax < 0)
  {
    qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->loveMax << ") on element of MountClientData.loveMax.";
  }
}

void MountClientData::_fecondationTimeFunc(Reader *input)
{
  this->fecondationTime = input->readInt();
}

void MountClientData::_boostLimiterFunc(Reader *input)
{
  this->boostLimiter = input->readInt();
  if(this->boostLimiter < 0)
  {
    qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->boostLimiter << ") on element of MountClientData.boostLimiter.";
  }
}

void MountClientData::_boostMaxFunc(Reader *input)
{
  this->boostMax = input->readDouble();
  if(this->boostMax < -9.007199254740992E15 || this->boostMax > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->boostMax << ") on element of MountClientData.boostMax.";
  }
}

void MountClientData::_reproductionCountFunc(Reader *input)
{
  this->reproductionCount = input->readInt();
}

void MountClientData::_reproductionCountMaxFunc(Reader *input)
{
  this->reproductionCountMax = input->readVarUhInt();
  if(this->reproductionCountMax < 0)
  {
    qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->reproductionCountMax << ") on element of MountClientData.reproductionCountMax.";
  }
}

void MountClientData::_harnessGIDFunc(Reader *input)
{
  this->harnessGID = input->readVarUhInt();
  if(this->harnessGID < 0)
  {
    qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->harnessGID << ") on element of MountClientData.harnessGID.";
  }
}

void MountClientData::_effectListtreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_effectListtree.addChild(std::bind(&MountClientData::_effectListFunc, this, std::placeholders::_1));
  }
}

void MountClientData::_effectListFunc(Reader *input)
{
  QSharedPointer<ObjectEffectInteger> _item = QSharedPointer<ObjectEffectInteger>(new ObjectEffectInteger() );
  _item->deserialize(input);
  this->effectList.append(_item);
}

MountClientData::MountClientData()
{
  m_types<<ClassEnum::MOUNTCLIENTDATA;
}

bool MountClientData::operator==(const MountClientData &compared)
{
  if(id == compared.id)
  if(model == compared.model)
  if(ancestor == compared.ancestor)
  if(behaviors == compared.behaviors)
  if(name == compared.name)
  if(sex == compared.sex)
  if(ownerId == compared.ownerId)
  if(experience == compared.experience)
  if(experienceForLevel == compared.experienceForLevel)
  if(experienceForNextLevel == compared.experienceForNextLevel)
  if(level == compared.level)
  if(isRideable == compared.isRideable)
  if(maxPods == compared.maxPods)
  if(isWild == compared.isWild)
  if(stamina == compared.stamina)
  if(staminaMax == compared.staminaMax)
  if(maturity == compared.maturity)
  if(maturityForAdult == compared.maturityForAdult)
  if(energy == compared.energy)
  if(energyMax == compared.energyMax)
  if(serenity == compared.serenity)
  if(aggressivityMax == compared.aggressivityMax)
  if(serenityMax == compared.serenityMax)
  if(love == compared.love)
  if(loveMax == compared.loveMax)
  if(fecondationTime == compared.fecondationTime)
  if(isFecondationReady == compared.isFecondationReady)
  if(boostLimiter == compared.boostLimiter)
  if(boostMax == compared.boostMax)
  if(reproductionCount == compared.reproductionCount)
  if(reproductionCountMax == compared.reproductionCountMax)
  if(harnessGID == compared.harnessGID)
  if(useHarnessColors == compared.useHarnessColors)
  if(effectList == compared.effectList)
  if(_ancestortree == compared._ancestortree)
  if(_behaviorstree == compared._behaviorstree)
  if(_effectListtree == compared._effectListtree)
  return true;
  
  return false;
}

