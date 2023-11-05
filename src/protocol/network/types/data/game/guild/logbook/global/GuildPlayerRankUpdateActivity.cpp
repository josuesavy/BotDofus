#include "GuildPlayerRankUpdateActivity.h"

void GuildPlayerRankUpdateActivity::serialize(Writer *output)
{
  this->serializeAs_GuildPlayerRankUpdateActivity(output);
}

void GuildPlayerRankUpdateActivity::serializeAs_GuildPlayerRankUpdateActivity(Writer *output)
{
  GuildLogbookEntryBasicInformation::serializeAs_GuildLogbookEntryBasicInformation(output);
  this->guildRankMinimalInfos.serializeAs_RankMinimalInformation(output);
  if(this->sourcePlayerId < 0 || this->sourcePlayerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GuildPlayerRankUpdateActivity -"<<"Forbidden value (" << this->sourcePlayerId << ") on element sourcePlayerId.";
  }
  output->writeVarLong((double)this->sourcePlayerId);
  if(this->targetPlayerId < 0 || this->targetPlayerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GuildPlayerRankUpdateActivity -"<<"Forbidden value (" << this->targetPlayerId << ") on element targetPlayerId.";
  }
  output->writeVarLong((double)this->targetPlayerId);
  output->writeUTF(this->sourcePlayerName);
  output->writeUTF(this->targetPlayerName);
}

void GuildPlayerRankUpdateActivity::deserialize(Reader *input)
{
  this->deserializeAs_GuildPlayerRankUpdateActivity(input);
}

void GuildPlayerRankUpdateActivity::deserializeAs_GuildPlayerRankUpdateActivity(Reader *input)
{
  GuildLogbookEntryBasicInformation::deserialize(input);
  this->guildRankMinimalInfos = RankMinimalInformation();
  this->guildRankMinimalInfos.deserialize(input);
  this->_sourcePlayerIdFunc(input);
  this->_targetPlayerIdFunc(input);
  this->_sourcePlayerNameFunc(input);
  this->_targetPlayerNameFunc(input);
}

void GuildPlayerRankUpdateActivity::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildPlayerRankUpdateActivity(tree);
}

void GuildPlayerRankUpdateActivity::deserializeAsyncAs_GuildPlayerRankUpdateActivity(FuncTree tree)
{
  GuildLogbookEntryBasicInformation::deserializeAsync(tree);
  this->_guildRankMinimalInfostree = tree.addChild(std::bind(&GuildPlayerRankUpdateActivity::_guildRankMinimalInfostreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildPlayerRankUpdateActivity::_sourcePlayerIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildPlayerRankUpdateActivity::_targetPlayerIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildPlayerRankUpdateActivity::_sourcePlayerNameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildPlayerRankUpdateActivity::_targetPlayerNameFunc, this, std::placeholders::_1));
}

void GuildPlayerRankUpdateActivity::_guildRankMinimalInfostreeFunc(Reader *input)
{
  this->guildRankMinimalInfos = RankMinimalInformation();
  this->guildRankMinimalInfos.deserializeAsync(this->_guildRankMinimalInfostree);
}

void GuildPlayerRankUpdateActivity::_sourcePlayerIdFunc(Reader *input)
{
  this->sourcePlayerId = input->readVarUhLong();
  if(this->sourcePlayerId < 0 || this->sourcePlayerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GuildPlayerRankUpdateActivity -"<<"Forbidden value (" << this->sourcePlayerId << ") on element of GuildPlayerRankUpdateActivity.sourcePlayerId.";
  }
}

void GuildPlayerRankUpdateActivity::_targetPlayerIdFunc(Reader *input)
{
  this->targetPlayerId = input->readVarUhLong();
  if(this->targetPlayerId < 0 || this->targetPlayerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GuildPlayerRankUpdateActivity -"<<"Forbidden value (" << this->targetPlayerId << ") on element of GuildPlayerRankUpdateActivity.targetPlayerId.";
  }
}

void GuildPlayerRankUpdateActivity::_sourcePlayerNameFunc(Reader *input)
{
  this->sourcePlayerName = input->readUTF();
}

void GuildPlayerRankUpdateActivity::_targetPlayerNameFunc(Reader *input)
{
  this->targetPlayerName = input->readUTF();
}

GuildPlayerRankUpdateActivity::GuildPlayerRankUpdateActivity()
{
  m_types<<ClassEnum::GUILDPLAYERRANKUPDATEACTIVITY;
}

bool GuildPlayerRankUpdateActivity::operator==(const GuildPlayerRankUpdateActivity &compared)
{
  if(guildRankMinimalInfos == compared.guildRankMinimalInfos)
  if(sourcePlayerId == compared.sourcePlayerId)
  if(targetPlayerId == compared.targetPlayerId)
  if(sourcePlayerName == compared.sourcePlayerName)
  if(targetPlayerName == compared.targetPlayerName)
  if(_guildRankMinimalInfostree == compared._guildRankMinimalInfostree)
  return true;
  
  return false;
}

