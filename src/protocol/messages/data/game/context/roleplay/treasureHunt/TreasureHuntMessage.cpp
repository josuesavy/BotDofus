#include "TreasureHuntMessage.h"

void TreasureHuntMessage::serialize(Writer *output)
{
  this->serializeAs_TreasureHuntMessage(output);
}

void TreasureHuntMessage::serializeAs_TreasureHuntMessage(Writer *output)
{
  output->writeByte(this->questType);
  if(this->startMapId < 0 || this->startMapId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - TreasureHuntMessage -"<<"Forbidden value (" << this->startMapId << ") on element startMapId.";
  }
  output->writeDouble(this->startMapId);
  output->writeShort((short)this->knownStepsList.size());
  for(uint _i3 = 0; _i3 < this->knownStepsList.size(); _i3++)
  {
    output->writeShort((short)qSharedPointerCast<TreasureHuntStep>(this->knownStepsList[_i3])->getTypes().last());
    qSharedPointerCast<TreasureHuntStep>(this->knownStepsList[_i3])->serialize(output);
  }
  if(this->totalStepCount < 0)
  {
    qDebug()<<"ERREUR - TreasureHuntMessage -"<<"Forbidden value (" << this->totalStepCount << ") on element totalStepCount.";
  }
  output->writeByte(this->totalStepCount);
  if(this->checkPointCurrent < 0)
  {
    qDebug()<<"ERREUR - TreasureHuntMessage -"<<"Forbidden value (" << this->checkPointCurrent << ") on element checkPointCurrent.";
  }
  output->writeVarInt((int)this->checkPointCurrent);
  if(this->checkPointTotal < 0)
  {
    qDebug()<<"ERREUR - TreasureHuntMessage -"<<"Forbidden value (" << this->checkPointTotal << ") on element checkPointTotal.";
  }
  output->writeVarInt((int)this->checkPointTotal);
  output->writeInt((int)this->availableRetryCount);
  output->writeShort((short)this->flags.size());
  for(uint _i8 = 0; _i8 < this->flags.size(); _i8++)
  {
    (this->flags[_i8]).serializeAs_TreasureHuntFlag(output);
  }
}

void TreasureHuntMessage::deserialize(Reader *input)
{
  this->deserializeAs_TreasureHuntMessage(input);
}

void TreasureHuntMessage::deserializeAs_TreasureHuntMessage(Reader *input)
{
  uint _id3 = 0;
  QSharedPointer<TreasureHuntStep> _item3 ;
  TreasureHuntFlag _item8 ;
  this->_questTypeFunc(input);
  this->_startMapIdFunc(input);
  uint _knownStepsListLen = input->readUShort();
  for(uint _i3 = 0; _i3 < _knownStepsListLen; _i3++)
  {
    _id3 = input->readUShort();
    _item3 = qSharedPointerCast<TreasureHuntStep>(ClassManagerSingleton::get()->getClass(_id3));
    _item3->deserialize(input);
    this->knownStepsList.append(_item3);
  }
  this->_totalStepCountFunc(input);
  this->_checkPointCurrentFunc(input);
  this->_checkPointTotalFunc(input);
  this->_availableRetryCountFunc(input);
  uint _flagsLen = input->readUShort();
  for(uint _i8 = 0; _i8 < _flagsLen; _i8++)
  {
    _item8 = TreasureHuntFlag();
    _item8.deserialize(input);
    this->flags.append(_item8);
  }
}

void TreasureHuntMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TreasureHuntMessage(tree);
}

void TreasureHuntMessage::deserializeAsyncAs_TreasureHuntMessage(FuncTree tree)
{
  tree.addChild(std::bind(&TreasureHuntMessage::_questTypeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TreasureHuntMessage::_startMapIdFunc, this, std::placeholders::_1));
  this->_knownStepsListtree = tree.addChild(std::bind(&TreasureHuntMessage::_knownStepsListtreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TreasureHuntMessage::_totalStepCountFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TreasureHuntMessage::_checkPointCurrentFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TreasureHuntMessage::_checkPointTotalFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TreasureHuntMessage::_availableRetryCountFunc, this, std::placeholders::_1));
  this->_flagstree = tree.addChild(std::bind(&TreasureHuntMessage::_flagstreeFunc, this, std::placeholders::_1));
}

void TreasureHuntMessage::_questTypeFunc(Reader *input)
{
  this->questType = input->readByte();
  if(this->questType < 0)
  {
    qDebug()<<"ERREUR - TreasureHuntMessage -"<<"Forbidden value (" << this->questType << ") on element of TreasureHuntMessage.questType.";
  }
}

void TreasureHuntMessage::_startMapIdFunc(Reader *input)
{
  this->startMapId = input->readDouble();
  if(this->startMapId < 0 || this->startMapId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - TreasureHuntMessage -"<<"Forbidden value (" << this->startMapId << ") on element of TreasureHuntMessage.startMapId.";
  }
}

void TreasureHuntMessage::_knownStepsListtreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_knownStepsListtree.addChild(std::bind(&TreasureHuntMessage::_knownStepsListFunc, this, std::placeholders::_1));
  }
}

void TreasureHuntMessage::_knownStepsListFunc(Reader *input)
{
  uint _id = input->readUShort();
  QSharedPointer<TreasureHuntStep> _item = qSharedPointerCast<TreasureHuntStep>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->knownStepsList.append(_item);
}

void TreasureHuntMessage::_totalStepCountFunc(Reader *input)
{
  this->totalStepCount = input->readByte();
  if(this->totalStepCount < 0)
  {
    qDebug()<<"ERREUR - TreasureHuntMessage -"<<"Forbidden value (" << this->totalStepCount << ") on element of TreasureHuntMessage.totalStepCount.";
  }
}

void TreasureHuntMessage::_checkPointCurrentFunc(Reader *input)
{
  this->checkPointCurrent = input->readVarUhInt();
  if(this->checkPointCurrent < 0)
  {
    qDebug()<<"ERREUR - TreasureHuntMessage -"<<"Forbidden value (" << this->checkPointCurrent << ") on element of TreasureHuntMessage.checkPointCurrent.";
  }
}

void TreasureHuntMessage::_checkPointTotalFunc(Reader *input)
{
  this->checkPointTotal = input->readVarUhInt();
  if(this->checkPointTotal < 0)
  {
    qDebug()<<"ERREUR - TreasureHuntMessage -"<<"Forbidden value (" << this->checkPointTotal << ") on element of TreasureHuntMessage.checkPointTotal.";
  }
}

void TreasureHuntMessage::_availableRetryCountFunc(Reader *input)
{
  this->availableRetryCount = input->readInt();
}

void TreasureHuntMessage::_flagstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_flagstree.addChild(std::bind(&TreasureHuntMessage::_flagsFunc, this, std::placeholders::_1));
  }
}

void TreasureHuntMessage::_flagsFunc(Reader *input)
{
  TreasureHuntFlag _item = TreasureHuntFlag();
  _item.deserialize(input);
  this->flags.append(_item);
}

TreasureHuntMessage::TreasureHuntMessage()
{
  m_type = MessageEnum::TREASUREHUNTMESSAGE;
}

