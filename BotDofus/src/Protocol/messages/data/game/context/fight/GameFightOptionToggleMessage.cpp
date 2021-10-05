#include "GameFightOptionToggleMessage.h"

void GameFightOptionToggleMessage::serialize(Writer *output)
{
  this->serializeAs_GameFightOptionToggleMessage(output);
}

void GameFightOptionToggleMessage::serializeAs_GameFightOptionToggleMessage(Writer *output)
{
  output->writeByte(this->option);
}

void GameFightOptionToggleMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameFightOptionToggleMessage(input);
}

void GameFightOptionToggleMessage::deserializeAs_GameFightOptionToggleMessage(Reader *input)
{
  this->_optionFunc(input);
}

void GameFightOptionToggleMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameFightOptionToggleMessage(tree);
}

void GameFightOptionToggleMessage::deserializeAsyncAs_GameFightOptionToggleMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GameFightOptionToggleMessage::_optionFunc, this, std::placeholders::_1));
}

void GameFightOptionToggleMessage::_optionFunc(Reader *input)
{
  this->option = input->readByte();
  if(this->option < 0)
  {
    qDebug()<<"ERREUR - GameFightOptionToggleMessage -"<<"Forbidden value (" << this->option << ") on element of GameFightOptionToggleMessage.option.";
  }
}

GameFightOptionToggleMessage::GameFightOptionToggleMessage()
{
  m_type = MessageEnum::GAMEFIGHTOPTIONTOGGLEMESSAGE;
}

