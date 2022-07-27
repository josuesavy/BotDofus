#include "GuildApplicationReceivedMessage.h"

void GuildApplicationReceivedMessage::serialize(Writer *output)
{
  this->serializeAs_GuildApplicationReceivedMessage(output);
}

void GuildApplicationReceivedMessage::serializeAs_GuildApplicationReceivedMessage(Writer *output)
{
  output->writeUTF(this->playerName);
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildApplicationReceivedMessage -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  output->writeVarLong((double)this->playerId);
}

void GuildApplicationReceivedMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildApplicationReceivedMessage(input);
}

void GuildApplicationReceivedMessage::deserializeAs_GuildApplicationReceivedMessage(Reader *input)
{
  this->_playerNameFunc(input);
  this->_playerIdFunc(input);
}

void GuildApplicationReceivedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildApplicationReceivedMessage(tree);
}

void GuildApplicationReceivedMessage::deserializeAsyncAs_GuildApplicationReceivedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GuildApplicationReceivedMessage::_playerNameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildApplicationReceivedMessage::_playerIdFunc, this, std::placeholders::_1));
}

void GuildApplicationReceivedMessage::_playerNameFunc(Reader *input)
{
  this->playerName = input->readUTF();
}

void GuildApplicationReceivedMessage::_playerIdFunc(Reader *input)
{
  this->playerId = input->readVarUhLong();
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildApplicationReceivedMessage -"<<"Forbidden value (" << this->playerId << ") on element of GuildApplicationReceivedMessage.playerId.";
  }
}

GuildApplicationReceivedMessage::GuildApplicationReceivedMessage()
{
  m_type = MessageEnum::GUILDAPPLICATIONRECEIVEDMESSAGE;
}

