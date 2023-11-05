#include "FriendOnlineInformations.h"

void FriendOnlineInformations::serialize(Writer *output)
{
  this->serializeAs_FriendOnlineInformations(output);
}

void FriendOnlineInformations::serializeAs_FriendOnlineInformations(Writer *output)
{
  FriendInformations::serializeAs_FriendInformations(output);
  uint _box0 = 0;
  _box0 = BooleanByteWrapper::setFlag(_box0, 0, this->sex);
  _box0 = BooleanByteWrapper::setFlag(_box0, 1, this->havenBagShared);
  output->writeByte(_box0);
  if(this->playerId < 0 || this->playerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - FriendOnlineInformations -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  output->writeVarLong((double)this->playerId);
  output->writeUTF(this->playerName);
  if(this->level < 0)
  {
    qDebug()<<"ERREUR - FriendOnlineInformations -"<<"Forbidden value (" << this->level << ") on element level.";
  }
  output->writeVarShort((int)this->level);
  output->writeByte(this->alignmentSide);
  output->writeByte(this->breed);
  this->guildInfo->serializeAs_GuildInformations(output);
  if(this->moodSmileyId < 0)
  {
    qDebug()<<"ERREUR - FriendOnlineInformations -"<<"Forbidden value (" << this->moodSmileyId << ") on element moodSmileyId.";
  }
  output->writeVarShort((int)this->moodSmileyId);
  output->writeShort((short)this->status->getTypes().last());
  this->status->serialize(output);
}

void FriendOnlineInformations::deserialize(Reader *input)
{
  this->deserializeAs_FriendOnlineInformations(input);
}

void FriendOnlineInformations::deserializeAs_FriendOnlineInformations(Reader *input)
{
  FriendInformations::deserialize(input);
  this->deserializeByteBoxes(input);
  this->_playerIdFunc(input);
  this->_playerNameFunc(input);
  this->_levelFunc(input);
  this->_alignmentSideFunc(input);
  this->_breedFunc(input);
  this->guildInfo = QSharedPointer<GuildInformations>(new GuildInformations() );
  this->guildInfo->deserialize(input);
  this->_moodSmileyIdFunc(input);
  uint _id9 = uint(input->readUShort());
  this->status = qSharedPointerCast<PlayerStatus>(ClassManagerSingleton::get()->getClass(_id9));
  this->status->deserialize(input);
}

void FriendOnlineInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_FriendOnlineInformations(tree);
}

void FriendOnlineInformations::deserializeAsyncAs_FriendOnlineInformations(FuncTree tree)
{
  FriendInformations::deserializeAsync(tree);
  tree.addChild(std::bind(&FriendOnlineInformations::deserializeByteBoxes, this, std::placeholders::_1));
  tree.addChild(std::bind(&FriendOnlineInformations::_playerIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&FriendOnlineInformations::_playerNameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&FriendOnlineInformations::_levelFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&FriendOnlineInformations::_alignmentSideFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&FriendOnlineInformations::_breedFunc, this, std::placeholders::_1));
  this->_guildInfotree = tree.addChild(std::bind(&FriendOnlineInformations::_guildInfotreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&FriendOnlineInformations::_moodSmileyIdFunc, this, std::placeholders::_1));
  this->_statustree = tree.addChild(std::bind(&FriendOnlineInformations::_statustreeFunc, this, std::placeholders::_1));
}

void FriendOnlineInformations::deserializeByteBoxes(Reader *input)
{
  uint _box0 = uint(input->readByte());
  this->sex = BooleanByteWrapper::getFlag(_box0, 0);
  this->havenBagShared = BooleanByteWrapper::getFlag(_box0, 1);
}

void FriendOnlineInformations::_playerIdFunc(Reader *input)
{
  this->playerId = input->readVarUhLong();
  if(this->playerId < 0 || this->playerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - FriendOnlineInformations -"<<"Forbidden value (" << this->playerId << ") on element of FriendOnlineInformations.playerId.";
  }
}

void FriendOnlineInformations::_playerNameFunc(Reader *input)
{
  this->playerName = input->readUTF();
}

void FriendOnlineInformations::_levelFunc(Reader *input)
{
  this->level = input->readVarUhShort();
  if(this->level < 0)
  {
    qDebug()<<"ERREUR - FriendOnlineInformations -"<<"Forbidden value (" << this->level << ") on element of FriendOnlineInformations.level.";
  }
}

void FriendOnlineInformations::_alignmentSideFunc(Reader *input)
{
  this->alignmentSide = input->readByte();
}

void FriendOnlineInformations::_breedFunc(Reader *input)
{
  this->breed = input->readByte();
  if(this->breed < (int)PlayableBreedEnum::FECA || this->breed > (int)PlayableBreedEnum::FORGELANCE)
  {
    qDebug()<<"ERREUR - FriendOnlineInformations -"<<"Forbidden value (" << this->breed << ") on element of FriendOnlineInformations.breed.";
  }
}

void FriendOnlineInformations::_guildInfotreeFunc(Reader *input)
{
  this->guildInfo = QSharedPointer<GuildInformations>(new GuildInformations() );
  this->guildInfo->deserializeAsync(this->_guildInfotree);
}

void FriendOnlineInformations::_moodSmileyIdFunc(Reader *input)
{
  this->moodSmileyId = input->readVarUhShort();
  if(this->moodSmileyId < 0)
  {
    qDebug()<<"ERREUR - FriendOnlineInformations -"<<"Forbidden value (" << this->moodSmileyId << ") on element of FriendOnlineInformations.moodSmileyId.";
  }
}

void FriendOnlineInformations::_statustreeFunc(Reader *input)
{
  uint _id = uint(input->readUShort());
  this->status = qSharedPointerCast<PlayerStatus>(ClassManagerSingleton::get()->getClass(_id));
  this->status->deserializeAsync(this->_statustree);
}

FriendOnlineInformations::FriendOnlineInformations()
{
  m_types<<ClassEnum::FRIENDONLINEINFORMATIONS;
}

bool FriendOnlineInformations::operator==(const FriendOnlineInformations &compared)
{
  if(playerId == compared.playerId)
  if(playerName == compared.playerName)
  if(level == compared.level)
  if(alignmentSide == compared.alignmentSide)
  if(breed == compared.breed)
  if(sex == compared.sex)
  if(guildInfo == compared.guildInfo)
  if(moodSmileyId == compared.moodSmileyId)
  if(status == compared.status)
  if(havenBagShared == compared.havenBagShared)
  if(_guildInfotree == compared._guildInfotree)
  if(_statustree == compared._statustree)
  return true;
  
  return false;
}

