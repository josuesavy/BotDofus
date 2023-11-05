#include "PaddockContentInformations.h"

void PaddockContentInformations::serialize(Writer *output)
{
  this->serializeAs_PaddockContentInformations(output);
}

void PaddockContentInformations::serializeAs_PaddockContentInformations(Writer *output)
{
  PaddockInformations::serializeAs_PaddockInformations(output);
  if(this->paddockId < 0 || this->paddockId > 9007199254740992)
  {
    qDebug()<<"ERREUR - PaddockContentInformations -"<<"Forbidden value (" << this->paddockId << ") on element paddockId.";
  }
  output->writeDouble(this->paddockId);
  if(this->worldX < -255 || this->worldX > 255)
  {
    qDebug()<<"ERREUR - PaddockContentInformations -"<<"Forbidden value (" << this->worldX << ") on element worldX.";
  }
  output->writeShort((short)this->worldX);
  if(this->worldY < -255 || this->worldY > 255)
  {
    qDebug()<<"ERREUR - PaddockContentInformations -"<<"Forbidden value (" << this->worldY << ") on element worldY.";
  }
  output->writeShort((short)this->worldY);
  if(this->mapId < 0 || this->mapId > 9007199254740992)
  {
    qDebug()<<"ERREUR - PaddockContentInformations -"<<"Forbidden value (" << this->mapId << ") on element mapId.";
  }
  output->writeDouble(this->mapId);
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - PaddockContentInformations -"<<"Forbidden value (" << this->subAreaId << ") on element subAreaId.";
  }
  output->writeVarShort((int)this->subAreaId);
  output->writeBool(this->abandonned);
  output->writeShort((short)this->mountsInformations.size());
  for(uint _i7 = 0; _i7 < this->mountsInformations.size(); _i7++)
  {
    (this->mountsInformations[_i7] as com.ankamagames.dofus.network.types.game.paddock.MountInformationsForPaddock).serializeAs_MountInformationsForPaddock(output);
  }
}

void PaddockContentInformations::deserialize(Reader *input)
{
  this->deserializeAs_PaddockContentInformations(input);
}

void PaddockContentInformations::deserializeAs_PaddockContentInformations(Reader *input)
{
  com.ankamagames.dofus.network.types.game.paddock.MountInformationsForPaddock _item7 ;
  PaddockInformations::deserialize(input);
  this->_paddockIdFunc(input);
  this->_worldXFunc(input);
  this->_worldYFunc(input);
  this->_mapIdFunc(input);
  this->_subAreaIdFunc(input);
  this->_abandonnedFunc(input);
  uint _mountsInformationsLen = uint(input->readUShort());
  for(uint _i7 = 0; _i7 < _mountsInformationsLen; _i7++)
  {
    _item7 = new com.ankamagames.dofus.network.types.game.paddock.MountInformationsForPaddock();
    _item7.deserialize(input);
    this->mountsInformations.append(_item7);
  }
}

void PaddockContentInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PaddockContentInformations(tree);
}

void PaddockContentInformations::deserializeAsyncAs_PaddockContentInformations(FuncTree tree)
{
  PaddockInformations::deserializeAsync(tree);
  tree.addChild(std::bind(&PaddockContentInformations::_paddockIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PaddockContentInformations::_worldXFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PaddockContentInformations::_worldYFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PaddockContentInformations::_mapIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PaddockContentInformations::_subAreaIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PaddockContentInformations::_abandonnedFunc, this, std::placeholders::_1));
  this->_mountsInformationstree = tree.addChild(std::bind(&PaddockContentInformations::_mountsInformationstreeFunc, this, std::placeholders::_1));
}

void PaddockContentInformations::_paddockIdFunc(Reader *input)
{
  this->paddockId = input->readDouble();
  if(this->paddockId < 0 || this->paddockId > 9007199254740992)
  {
    qDebug()<<"ERREUR - PaddockContentInformations -"<<"Forbidden value (" << this->paddockId << ") on element of PaddockContentInformations.paddockId.";
  }
}

void PaddockContentInformations::_worldXFunc(Reader *input)
{
  this->worldX = input->readShort();
  if(this->worldX < -255 || this->worldX > 255)
  {
    qDebug()<<"ERREUR - PaddockContentInformations -"<<"Forbidden value (" << this->worldX << ") on element of PaddockContentInformations.worldX.";
  }
}

void PaddockContentInformations::_worldYFunc(Reader *input)
{
  this->worldY = input->readShort();
  if(this->worldY < -255 || this->worldY > 255)
  {
    qDebug()<<"ERREUR - PaddockContentInformations -"<<"Forbidden value (" << this->worldY << ") on element of PaddockContentInformations.worldY.";
  }
}

void PaddockContentInformations::_mapIdFunc(Reader *input)
{
  this->mapId = input->readDouble();
  if(this->mapId < 0 || this->mapId > 9007199254740992)
  {
    qDebug()<<"ERREUR - PaddockContentInformations -"<<"Forbidden value (" << this->mapId << ") on element of PaddockContentInformations.mapId.";
  }
}

void PaddockContentInformations::_subAreaIdFunc(Reader *input)
{
  this->subAreaId = input->readVarUhShort();
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - PaddockContentInformations -"<<"Forbidden value (" << this->subAreaId << ") on element of PaddockContentInformations.subAreaId.";
  }
}

void PaddockContentInformations::_abandonnedFunc(Reader *input)
{
  this->abandonned = input->readBool();
}

void PaddockContentInformations::_mountsInformationstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_mountsInformationstree.addChild(std::bind(&PaddockContentInformations::_mountsInformationsFunc, this, std::placeholders::_1));
  }
}

void PaddockContentInformations::_mountsInformationsFunc(Reader *input)
{
   _item = new com.ankamagames.dofus.network.types.game.paddock.MountInformationsForPaddock();
  _item.deserialize(input);
  this->mountsInformations.append(_item);
}

PaddockContentInformations::PaddockContentInformations()
{
  m_types<<ClassEnum::PADDOCKCONTENTINFORMATIONS;
}

bool PaddockContentInformations::operator==(const PaddockContentInformations &compared)
{
  if(paddockId == compared.paddockId)
  if(worldX == compared.worldX)
  if(worldY == compared.worldY)
  if(mapId == compared.mapId)
  if(subAreaId == compared.subAreaId)
  if(abandonned == compared.abandonned)
  if(mountsInformations == compared.mountsInformations)
  if(_mountsInformationstree == compared._mountsInformationstree)
  return true;
  
  return false;
}

