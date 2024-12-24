#include "GuildListApplicationModifiedMessage.h"

void GuildListApplicationModifiedMessage::serialize(Writer *output)
{
  this->serializeAs_GuildListApplicationModifiedMessage(output);
}

void GuildListApplicationModifiedMessage::serializeAs_GuildListApplicationModifiedMessage(Writer *output)
{
  this->apply->serializeAs_SocialApplicationInformation(output);
  output->writeByte(this->state);
  if(this->playerId < 0 || this->playerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GuildListApplicationModifiedMessage -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  output->writeVarLong((double)this->playerId);
}

void GuildListApplicationModifiedMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildListApplicationModifiedMessage(input);
}

void GuildListApplicationModifiedMessage::deserializeAs_GuildListApplicationModifiedMessage(Reader *input)
{
  this->apply = QSharedPointer<SocialApplicationInformation>(new SocialApplicationInformation() );
  this->apply->deserialize(input);
  this->_stateFunc(input);
  this->_playerIdFunc(input);
}

void GuildListApplicationModifiedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildListApplicationModifiedMessage(tree);
}

void GuildListApplicationModifiedMessage::deserializeAsyncAs_GuildListApplicationModifiedMessage(FuncTree tree)
{
  this->_applytree = tree.addChild(std::bind(&GuildListApplicationModifiedMessage::_applytreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildListApplicationModifiedMessage::_stateFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildListApplicationModifiedMessage::_playerIdFunc, this, std::placeholders::_1));
}

void GuildListApplicationModifiedMessage::_applytreeFunc(Reader *input)
{
  this->apply = QSharedPointer<SocialApplicationInformation>(new SocialApplicationInformation() );
  this->apply->deserializeAsync(this->_applytree);
}

void GuildListApplicationModifiedMessage::_stateFunc(Reader *input)
{
  this->state = input->readByte();
  if(this->state < 0)
  {
    qDebug()<<"ERREUR - GuildListApplicationModifiedMessage -"<<"Forbidden value (" << this->state << ") on element of GuildListApplicationModifiedMessage.state.";
  }
}

void GuildListApplicationModifiedMessage::_playerIdFunc(Reader *input)
{
  this->playerId = input->readVarUhLong();
  if(this->playerId < 0 || this->playerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GuildListApplicationModifiedMessage -"<<"Forbidden value (" << this->playerId << ") on element of GuildListApplicationModifiedMessage.playerId.";
  }
}

GuildListApplicationModifiedMessage::GuildListApplicationModifiedMessage()
{
  m_type = MessageEnum::GUILDLISTAPPLICATIONMODIFIEDMESSAGE;
}

