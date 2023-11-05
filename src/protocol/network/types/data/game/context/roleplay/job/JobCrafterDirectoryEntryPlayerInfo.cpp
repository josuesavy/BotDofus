#include "JobCrafterDirectoryEntryPlayerInfo.h"

void JobCrafterDirectoryEntryPlayerInfo::serialize(Writer *output)
{
  this->serializeAs_JobCrafterDirectoryEntryPlayerInfo(output);
}

void JobCrafterDirectoryEntryPlayerInfo::serializeAs_JobCrafterDirectoryEntryPlayerInfo(Writer *output)
{
  if(this->playerId < 0 || this->playerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - JobCrafterDirectoryEntryPlayerInfo -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  output->writeVarLong((double)this->playerId);
  output->writeUTF(this->playerName);
  output->writeByte(this->alignmentSide);
  output->writeByte(this->breed);
  output->writeBool(this->sex);
  output->writeBool(this->isInWorkshop);
  if(this->worldX < -255 || this->worldX > 255)
  {
    qDebug()<<"ERREUR - JobCrafterDirectoryEntryPlayerInfo -"<<"Forbidden value (" << this->worldX << ") on element worldX.";
  }
  output->writeShort((short)this->worldX);
  if(this->worldY < -255 || this->worldY > 255)
  {
    qDebug()<<"ERREUR - JobCrafterDirectoryEntryPlayerInfo -"<<"Forbidden value (" << this->worldY << ") on element worldY.";
  }
  output->writeShort((short)this->worldY);
  if(this->mapId < 0 || this->mapId > 9007199254740992)
  {
    qDebug()<<"ERREUR - JobCrafterDirectoryEntryPlayerInfo -"<<"Forbidden value (" << this->mapId << ") on element mapId.";
  }
  output->writeDouble(this->mapId);
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - JobCrafterDirectoryEntryPlayerInfo -"<<"Forbidden value (" << this->subAreaId << ") on element subAreaId.";
  }
  output->writeVarShort((int)this->subAreaId);
  output->writeBool(this->canCraftLegendary);
  output->writeShort((short)this->status->getTypes().last());
  this->status->serialize(output);
}

void JobCrafterDirectoryEntryPlayerInfo::deserialize(Reader *input)
{
  this->deserializeAs_JobCrafterDirectoryEntryPlayerInfo(input);
}

void JobCrafterDirectoryEntryPlayerInfo::deserializeAs_JobCrafterDirectoryEntryPlayerInfo(Reader *input)
{
  this->_playerIdFunc(input);
  this->_playerNameFunc(input);
  this->_alignmentSideFunc(input);
  this->_breedFunc(input);
  this->_sexFunc(input);
  this->_isInWorkshopFunc(input);
  this->_worldXFunc(input);
  this->_worldYFunc(input);
  this->_mapIdFunc(input);
  this->_subAreaIdFunc(input);
  this->_canCraftLegendaryFunc(input);
  uint _id12 = uint(input->readUShort());
  this->status = qSharedPointerCast<PlayerStatus>(ClassManagerSingleton::get()->getClass(_id12));
  this->status->deserialize(input);
}

void JobCrafterDirectoryEntryPlayerInfo::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_JobCrafterDirectoryEntryPlayerInfo(tree);
}

void JobCrafterDirectoryEntryPlayerInfo::deserializeAsyncAs_JobCrafterDirectoryEntryPlayerInfo(FuncTree tree)
{
  tree.addChild(std::bind(&JobCrafterDirectoryEntryPlayerInfo::_playerIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&JobCrafterDirectoryEntryPlayerInfo::_playerNameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&JobCrafterDirectoryEntryPlayerInfo::_alignmentSideFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&JobCrafterDirectoryEntryPlayerInfo::_breedFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&JobCrafterDirectoryEntryPlayerInfo::_sexFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&JobCrafterDirectoryEntryPlayerInfo::_isInWorkshopFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&JobCrafterDirectoryEntryPlayerInfo::_worldXFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&JobCrafterDirectoryEntryPlayerInfo::_worldYFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&JobCrafterDirectoryEntryPlayerInfo::_mapIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&JobCrafterDirectoryEntryPlayerInfo::_subAreaIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&JobCrafterDirectoryEntryPlayerInfo::_canCraftLegendaryFunc, this, std::placeholders::_1));
  this->_statustree = tree.addChild(std::bind(&JobCrafterDirectoryEntryPlayerInfo::_statustreeFunc, this, std::placeholders::_1));
}

void JobCrafterDirectoryEntryPlayerInfo::_playerIdFunc(Reader *input)
{
  this->playerId = input->readVarUhLong();
  if(this->playerId < 0 || this->playerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - JobCrafterDirectoryEntryPlayerInfo -"<<"Forbidden value (" << this->playerId << ") on element of JobCrafterDirectoryEntryPlayerInfo.playerId.";
  }
}

void JobCrafterDirectoryEntryPlayerInfo::_playerNameFunc(Reader *input)
{
  this->playerName = input->readUTF();
}

void JobCrafterDirectoryEntryPlayerInfo::_alignmentSideFunc(Reader *input)
{
  this->alignmentSide = input->readByte();
}

void JobCrafterDirectoryEntryPlayerInfo::_breedFunc(Reader *input)
{
  this->breed = input->readByte();
  if(this->breed < (int)PlayableBreedEnum::FECA || this->breed > (int)PlayableBreedEnum::FORGELANCE)
  {
    qDebug()<<"ERREUR - JobCrafterDirectoryEntryPlayerInfo -"<<"Forbidden value (" << this->breed << ") on element of JobCrafterDirectoryEntryPlayerInfo.breed.";
  }
}

void JobCrafterDirectoryEntryPlayerInfo::_sexFunc(Reader *input)
{
  this->sex = input->readBool();
}

void JobCrafterDirectoryEntryPlayerInfo::_isInWorkshopFunc(Reader *input)
{
  this->isInWorkshop = input->readBool();
}

void JobCrafterDirectoryEntryPlayerInfo::_worldXFunc(Reader *input)
{
  this->worldX = input->readShort();
  if(this->worldX < -255 || this->worldX > 255)
  {
    qDebug()<<"ERREUR - JobCrafterDirectoryEntryPlayerInfo -"<<"Forbidden value (" << this->worldX << ") on element of JobCrafterDirectoryEntryPlayerInfo.worldX.";
  }
}

void JobCrafterDirectoryEntryPlayerInfo::_worldYFunc(Reader *input)
{
  this->worldY = input->readShort();
  if(this->worldY < -255 || this->worldY > 255)
  {
    qDebug()<<"ERREUR - JobCrafterDirectoryEntryPlayerInfo -"<<"Forbidden value (" << this->worldY << ") on element of JobCrafterDirectoryEntryPlayerInfo.worldY.";
  }
}

void JobCrafterDirectoryEntryPlayerInfo::_mapIdFunc(Reader *input)
{
  this->mapId = input->readDouble();
  if(this->mapId < 0 || this->mapId > 9007199254740992)
  {
    qDebug()<<"ERREUR - JobCrafterDirectoryEntryPlayerInfo -"<<"Forbidden value (" << this->mapId << ") on element of JobCrafterDirectoryEntryPlayerInfo.mapId.";
  }
}

void JobCrafterDirectoryEntryPlayerInfo::_subAreaIdFunc(Reader *input)
{
  this->subAreaId = input->readVarUhShort();
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - JobCrafterDirectoryEntryPlayerInfo -"<<"Forbidden value (" << this->subAreaId << ") on element of JobCrafterDirectoryEntryPlayerInfo.subAreaId.";
  }
}

void JobCrafterDirectoryEntryPlayerInfo::_canCraftLegendaryFunc(Reader *input)
{
  this->canCraftLegendary = input->readBool();
}

void JobCrafterDirectoryEntryPlayerInfo::_statustreeFunc(Reader *input)
{
  uint _id = uint(input->readUShort());
  this->status = qSharedPointerCast<PlayerStatus>(ClassManagerSingleton::get()->getClass(_id));
  this->status->deserializeAsync(this->_statustree);
}

JobCrafterDirectoryEntryPlayerInfo::JobCrafterDirectoryEntryPlayerInfo()
{
  m_types<<ClassEnum::JOBCRAFTERDIRECTORYENTRYPLAYERINFO;
}

bool JobCrafterDirectoryEntryPlayerInfo::operator==(const JobCrafterDirectoryEntryPlayerInfo &compared)
{
  if(playerId == compared.playerId)
  if(playerName == compared.playerName)
  if(alignmentSide == compared.alignmentSide)
  if(breed == compared.breed)
  if(sex == compared.sex)
  if(isInWorkshop == compared.isInWorkshop)
  if(worldX == compared.worldX)
  if(worldY == compared.worldY)
  if(mapId == compared.mapId)
  if(subAreaId == compared.subAreaId)
  if(canCraftLegendary == compared.canCraftLegendary)
  if(status == compared.status)
  if(_statustree == compared._statustree)
  return true;
  
  return false;
}

