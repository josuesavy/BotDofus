#include "GameContextCreateMessage.h"

void GameContextCreateMessage::serialize(Writer *output)
{
  this->serializeAs_GameContextCreateMessage(output);
}

void GameContextCreateMessage::serializeAs_GameContextCreateMessage(Writer *output)
{
  output->writeByte(this->context);
}

void GameContextCreateMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameContextCreateMessage(input);
}

void GameContextCreateMessage::deserializeAs_GameContextCreateMessage(Reader *input)
{
  this->_contextFunc(input);
}

void GameContextCreateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameContextCreateMessage(tree);
}

void GameContextCreateMessage::deserializeAsyncAs_GameContextCreateMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GameContextCreateMessage::_contextFunc, this, std::placeholders::_1));
}

void GameContextCreateMessage::_contextFunc(Reader *input)
{
  this->context = input->readByte();
  if(this->context < 0)
  {
    qDebug()<<"ERREUR - GameContextCreateMessage -"<<"Forbidden value (" << this->context << ") on element of GameContextCreateMessage.context.";
  }
}

GameContextCreateMessage::GameContextCreateMessage()
{
  m_type = MessageEnum::GAMECONTEXTCREATEMESSAGE;
}

