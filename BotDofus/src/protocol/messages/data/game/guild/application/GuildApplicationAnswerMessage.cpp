#include "GuildApplicationAnswerMessage.h"

void GuildApplicationAnswerMessage::serialize(Writer *output)
{
  this->serializeAs_GuildApplicationAnswerMessage(output);
}

void GuildApplicationAnswerMessage::serializeAs_GuildApplicationAnswerMessage(Writer *output)
{
  output->writeBool(this->accepted);
  if(this->playerId < 0)
  {
    qDebug()<<"ERREUR - GuildApplicationAnswerMessage -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  output->writeVarInt((int)this->playerId);
}

void GuildApplicationAnswerMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildApplicationAnswerMessage(input);
}

void GuildApplicationAnswerMessage::deserializeAs_GuildApplicationAnswerMessage(Reader *input)
{
  this->_acceptedFunc(input);
  this->_playerIdFunc(input);
}

void GuildApplicationAnswerMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildApplicationAnswerMessage(tree);
}

void GuildApplicationAnswerMessage::deserializeAsyncAs_GuildApplicationAnswerMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GuildApplicationAnswerMessage::_acceptedFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildApplicationAnswerMessage::_playerIdFunc, this, std::placeholders::_1));
}

void GuildApplicationAnswerMessage::_acceptedFunc(Reader *input)
{
  this->accepted = input->readBool();
}

void GuildApplicationAnswerMessage::_playerIdFunc(Reader *input)
{
  this->playerId = input->readVarUhInt();
  if(this->playerId < 0)
  {
    qDebug()<<"ERREUR - GuildApplicationAnswerMessage -"<<"Forbidden value (" << this->playerId << ") on element of GuildApplicationAnswerMessage.playerId.";
  }
}

GuildApplicationAnswerMessage::GuildApplicationAnswerMessage()
{
  m_type = MessageEnum::GUILDAPPLICATIONANSWERMESSAGE;
}

