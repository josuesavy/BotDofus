#include "GuildLogbookChestActivity.h"

void GuildLogbookChestActivity::serialize(Writer *output)
{
  this->serializeAs_GuildLogbookChestActivity(output);
}

void GuildLogbookChestActivity::serializeAs_GuildLogbookChestActivity(Writer *output)
{
  GuildLogbookEntryBasicInformation::serializeAs_GuildLogbookEntryBasicInformation(output);
  if(this->playerId < 0 || this->playerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GuildLogbookChestActivity -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  output->writeVarLong((double)this->playerId);
  output->writeUTF(this->playerName);
  output->writeByte(this->eventType);
  if(this->quantity < 0)
  {
    qDebug()<<"ERREUR - GuildLogbookChestActivity -"<<"Forbidden value (" << this->quantity << ") on element quantity.";
  }
  output->writeInt((int)this->quantity);
  this->object->serializeAs_ObjectItemNotInContainer(output);
  if(this->sourceTabId < 0)
  {
    qDebug()<<"ERREUR - GuildLogbookChestActivity -"<<"Forbidden value (" << this->sourceTabId << ") on element sourceTabId.";
  }
  output->writeInt((int)this->sourceTabId);
  if(this->destinationTabId < 0)
  {
    qDebug()<<"ERREUR - GuildLogbookChestActivity -"<<"Forbidden value (" << this->destinationTabId << ") on element destinationTabId.";
  }
  output->writeInt((int)this->destinationTabId);
}

void GuildLogbookChestActivity::deserialize(Reader *input)
{
  this->deserializeAs_GuildLogbookChestActivity(input);
}

void GuildLogbookChestActivity::deserializeAs_GuildLogbookChestActivity(Reader *input)
{
  GuildLogbookEntryBasicInformation::deserialize(input);
  this->_playerIdFunc(input);
  this->_playerNameFunc(input);
  this->_eventTypeFunc(input);
  this->_quantityFunc(input);
  this->object = QSharedPointer<ObjectItemNotInContainer>(new ObjectItemNotInContainer() );
  this->object->deserialize(input);
  this->_sourceTabIdFunc(input);
  this->_destinationTabIdFunc(input);
}

void GuildLogbookChestActivity::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildLogbookChestActivity(tree);
}

void GuildLogbookChestActivity::deserializeAsyncAs_GuildLogbookChestActivity(FuncTree tree)
{
  GuildLogbookEntryBasicInformation::deserializeAsync(tree);
  tree.addChild(std::bind(&GuildLogbookChestActivity::_playerIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildLogbookChestActivity::_playerNameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildLogbookChestActivity::_eventTypeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildLogbookChestActivity::_quantityFunc, this, std::placeholders::_1));
  this->_objecttree = tree.addChild(std::bind(&GuildLogbookChestActivity::_objecttreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildLogbookChestActivity::_sourceTabIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildLogbookChestActivity::_destinationTabIdFunc, this, std::placeholders::_1));
}

void GuildLogbookChestActivity::_playerIdFunc(Reader *input)
{
  this->playerId = input->readVarUhLong();
  if(this->playerId < 0 || this->playerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GuildLogbookChestActivity -"<<"Forbidden value (" << this->playerId << ") on element of GuildLogbookChestActivity.playerId.";
  }
}

void GuildLogbookChestActivity::_playerNameFunc(Reader *input)
{
  this->playerName = input->readUTF();
}

void GuildLogbookChestActivity::_eventTypeFunc(Reader *input)
{
  this->eventType = input->readByte();
  if(this->eventType < 0)
  {
    qDebug()<<"ERREUR - GuildLogbookChestActivity -"<<"Forbidden value (" << this->eventType << ") on element of GuildLogbookChestActivity.eventType.";
  }
}

void GuildLogbookChestActivity::_quantityFunc(Reader *input)
{
  this->quantity = input->readInt();
  if(this->quantity < 0)
  {
    qDebug()<<"ERREUR - GuildLogbookChestActivity -"<<"Forbidden value (" << this->quantity << ") on element of GuildLogbookChestActivity.quantity.";
  }
}

void GuildLogbookChestActivity::_objecttreeFunc(Reader *input)
{
  this->object = QSharedPointer<ObjectItemNotInContainer>(new ObjectItemNotInContainer() );
  this->object->deserializeAsync(this->_objecttree);
}

void GuildLogbookChestActivity::_sourceTabIdFunc(Reader *input)
{
  this->sourceTabId = input->readInt();
  if(this->sourceTabId < 0)
  {
    qDebug()<<"ERREUR - GuildLogbookChestActivity -"<<"Forbidden value (" << this->sourceTabId << ") on element of GuildLogbookChestActivity.sourceTabId.";
  }
}

void GuildLogbookChestActivity::_destinationTabIdFunc(Reader *input)
{
  this->destinationTabId = input->readInt();
  if(this->destinationTabId < 0)
  {
    qDebug()<<"ERREUR - GuildLogbookChestActivity -"<<"Forbidden value (" << this->destinationTabId << ") on element of GuildLogbookChestActivity.destinationTabId.";
  }
}

GuildLogbookChestActivity::GuildLogbookChestActivity()
{
  m_types<<ClassEnum::GUILDLOGBOOKCHESTACTIVITY;
}

bool GuildLogbookChestActivity::operator==(const GuildLogbookChestActivity &compared)
{
  if(playerId == compared.playerId)
  if(playerName == compared.playerName)
  if(eventType == compared.eventType)
  if(quantity == compared.quantity)
  if(object == compared.object)
  if(sourceTabId == compared.sourceTabId)
  if(destinationTabId == compared.destinationTabId)
  if(_objecttree == compared._objecttree)
  return true;
  
  return false;
}

