#include "GuildPlayerFlowActivity.h"

void GuildPlayerFlowActivity::serialize(Writer *output)
{
  this->serializeAs_GuildPlayerFlowActivity(output);
}

void GuildPlayerFlowActivity::serializeAs_GuildPlayerFlowActivity(Writer *output)
{
  GuildLogbookEntryBasicInformation::serializeAs_GuildLogbookEntryBasicInformation(output);
  if(this->playerId < 0 || this->playerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GuildPlayerFlowActivity -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  output->writeVarLong((double)this->playerId);
  output->writeUTF(this->playerName);
  output->writeByte(this->playerFlowEventType);
}

void GuildPlayerFlowActivity::deserialize(Reader *input)
{
  this->deserializeAs_GuildPlayerFlowActivity(input);
}

void GuildPlayerFlowActivity::deserializeAs_GuildPlayerFlowActivity(Reader *input)
{
  GuildLogbookEntryBasicInformation::deserialize(input);
  this->_playerIdFunc(input);
  this->_playerNameFunc(input);
  this->_playerFlowEventTypeFunc(input);
}

void GuildPlayerFlowActivity::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildPlayerFlowActivity(tree);
}

void GuildPlayerFlowActivity::deserializeAsyncAs_GuildPlayerFlowActivity(FuncTree tree)
{
  GuildLogbookEntryBasicInformation::deserializeAsync(tree);
  tree.addChild(std::bind(&GuildPlayerFlowActivity::_playerIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildPlayerFlowActivity::_playerNameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildPlayerFlowActivity::_playerFlowEventTypeFunc, this, std::placeholders::_1));
}

void GuildPlayerFlowActivity::_playerIdFunc(Reader *input)
{
  this->playerId = input->readVarUhLong();
  if(this->playerId < 0 || this->playerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GuildPlayerFlowActivity -"<<"Forbidden value (" << this->playerId << ") on element of GuildPlayerFlowActivity.playerId.";
  }
}

void GuildPlayerFlowActivity::_playerNameFunc(Reader *input)
{
  this->playerName = input->readUTF();
}

void GuildPlayerFlowActivity::_playerFlowEventTypeFunc(Reader *input)
{
  this->playerFlowEventType = input->readByte();
  if(this->playerFlowEventType < 0)
  {
    qDebug()<<"ERREUR - GuildPlayerFlowActivity -"<<"Forbidden value (" << this->playerFlowEventType << ") on element of GuildPlayerFlowActivity.playerFlowEventType.";
  }
}

GuildPlayerFlowActivity::GuildPlayerFlowActivity()
{
  m_types<<ClassEnum::GUILDPLAYERFLOWACTIVITY;
}

bool GuildPlayerFlowActivity::operator==(const GuildPlayerFlowActivity &compared)
{
  if(playerId == compared.playerId)
  if(playerName == compared.playerName)
  if(playerFlowEventType == compared.playerFlowEventType)
  return true;
  
  return false;
}

