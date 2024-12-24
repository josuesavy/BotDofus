#include "GuildPaddockActivity.h"

void GuildPaddockActivity::serialize(Writer *output)
{
  this->serializeAs_GuildPaddockActivity(output);
}

void GuildPaddockActivity::serializeAs_GuildPaddockActivity(Writer *output)
{
  GuildLogbookEntryBasicInformation::serializeAs_GuildLogbookEntryBasicInformation(output);
  if(this->playerId < 0 || this->playerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GuildPaddockActivity -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  output->writeVarLong((double)this->playerId);
  output->writeUTF(this->playerName);
  this->paddockCoordinates->serializeAs_MapCoordinatesExtended(output);
  if(this->farmId < 0 || this->farmId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GuildPaddockActivity -"<<"Forbidden value (" << this->farmId << ") on element farmId.";
  }
  output->writeDouble(this->farmId);
  output->writeByte(this->paddockEventType);
}

void GuildPaddockActivity::deserialize(Reader *input)
{
  this->deserializeAs_GuildPaddockActivity(input);
}

void GuildPaddockActivity::deserializeAs_GuildPaddockActivity(Reader *input)
{
  GuildLogbookEntryBasicInformation::deserialize(input);
  this->_playerIdFunc(input);
  this->_playerNameFunc(input);
  this->paddockCoordinates = QSharedPointer<MapCoordinatesExtended>(new MapCoordinatesExtended() );
  this->paddockCoordinates->deserialize(input);
  this->_farmIdFunc(input);
  this->_paddockEventTypeFunc(input);
}

void GuildPaddockActivity::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildPaddockActivity(tree);
}

void GuildPaddockActivity::deserializeAsyncAs_GuildPaddockActivity(FuncTree tree)
{
  GuildLogbookEntryBasicInformation::deserializeAsync(tree);
  tree.addChild(std::bind(&GuildPaddockActivity::_playerIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildPaddockActivity::_playerNameFunc, this, std::placeholders::_1));
  this->_paddockCoordinatestree = tree.addChild(std::bind(&GuildPaddockActivity::_paddockCoordinatestreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildPaddockActivity::_farmIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildPaddockActivity::_paddockEventTypeFunc, this, std::placeholders::_1));
}

void GuildPaddockActivity::_playerIdFunc(Reader *input)
{
  this->playerId = input->readVarUhLong();
  if(this->playerId < 0 || this->playerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GuildPaddockActivity -"<<"Forbidden value (" << this->playerId << ") on element of GuildPaddockActivity.playerId.";
  }
}

void GuildPaddockActivity::_playerNameFunc(Reader *input)
{
  this->playerName = input->readUTF();
}

void GuildPaddockActivity::_paddockCoordinatestreeFunc(Reader *input)
{
  this->paddockCoordinates = QSharedPointer<MapCoordinatesExtended>(new MapCoordinatesExtended() );
  this->paddockCoordinates->deserializeAsync(this->_paddockCoordinatestree);
}

void GuildPaddockActivity::_farmIdFunc(Reader *input)
{
  this->farmId = input->readDouble();
  if(this->farmId < 0 || this->farmId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GuildPaddockActivity -"<<"Forbidden value (" << this->farmId << ") on element of GuildPaddockActivity.farmId.";
  }
}

void GuildPaddockActivity::_paddockEventTypeFunc(Reader *input)
{
  this->paddockEventType = input->readByte();
  if(this->paddockEventType < 0)
  {
    qDebug()<<"ERREUR - GuildPaddockActivity -"<<"Forbidden value (" << this->paddockEventType << ") on element of GuildPaddockActivity.paddockEventType.";
  }
}

GuildPaddockActivity::GuildPaddockActivity()
{
  m_types<<ClassEnum::GUILDPADDOCKACTIVITY;
}

bool GuildPaddockActivity::operator==(const GuildPaddockActivity &compared)
{
  if(playerId == compared.playerId)
  if(playerName == compared.playerName)
  if(paddockCoordinates == compared.paddockCoordinates)
  if(farmId == compared.farmId)
  if(paddockEventType == compared.paddockEventType)
  if(_paddockCoordinatestree == compared._paddockCoordinatestree)
  return true;
  
  return false;
}

