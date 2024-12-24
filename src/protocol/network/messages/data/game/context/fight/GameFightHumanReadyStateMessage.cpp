#include "GameFightHumanReadyStateMessage.h"

void GameFightHumanReadyStateMessage::serialize(Writer *output)
{
  this->serializeAs_GameFightHumanReadyStateMessage(output);
}

void GameFightHumanReadyStateMessage::serializeAs_GameFightHumanReadyStateMessage(Writer *output)
{
  if(this->characterId < 0 || this->characterId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameFightHumanReadyStateMessage -"<<"Forbidden value (" << this->characterId << ") on element characterId.";
  }
  output->writeVarLong((double)this->characterId);
  output->writeBool(this->isReady);
}

void GameFightHumanReadyStateMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameFightHumanReadyStateMessage(input);
}

void GameFightHumanReadyStateMessage::deserializeAs_GameFightHumanReadyStateMessage(Reader *input)
{
  this->_characterIdFunc(input);
  this->_isReadyFunc(input);
}

void GameFightHumanReadyStateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameFightHumanReadyStateMessage(tree);
}

void GameFightHumanReadyStateMessage::deserializeAsyncAs_GameFightHumanReadyStateMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GameFightHumanReadyStateMessage::_characterIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightHumanReadyStateMessage::_isReadyFunc, this, std::placeholders::_1));
}

void GameFightHumanReadyStateMessage::_characterIdFunc(Reader *input)
{
  this->characterId = input->readVarUhLong();
  if(this->characterId < 0 || this->characterId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameFightHumanReadyStateMessage -"<<"Forbidden value (" << this->characterId << ") on element of GameFightHumanReadyStateMessage.characterId.";
  }
}

void GameFightHumanReadyStateMessage::_isReadyFunc(Reader *input)
{
  this->isReady = input->readBool();
}

GameFightHumanReadyStateMessage::GameFightHumanReadyStateMessage()
{
  m_type = MessageEnum::GAMEFIGHTHUMANREADYSTATEMESSAGE;
}

