#include "GameContextRemoveElementMessage.h"

void GameContextRemoveElementMessage::serialize(Writer *output)
{
  this->serializeAs_GameContextRemoveElementMessage(output);
}

void GameContextRemoveElementMessage::serializeAs_GameContextRemoveElementMessage(Writer *output)
{
  if(this->id < -9.007199254740992E15 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameContextRemoveElementMessage -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  output->writeDouble(this->id);
}

void GameContextRemoveElementMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameContextRemoveElementMessage(input);
}

void GameContextRemoveElementMessage::deserializeAs_GameContextRemoveElementMessage(Reader *input)
{
  this->_idFunc(input);
}

void GameContextRemoveElementMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameContextRemoveElementMessage(tree);
}

void GameContextRemoveElementMessage::deserializeAsyncAs_GameContextRemoveElementMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GameContextRemoveElementMessage::_idFunc, this, std::placeholders::_1));
}

void GameContextRemoveElementMessage::_idFunc(Reader *input)
{
  this->id = input->readDouble();
  if(this->id < -9.007199254740992E15 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameContextRemoveElementMessage -"<<"Forbidden value (" << this->id << ") on element of GameContextRemoveElementMessage.id.";
  }
}

GameContextRemoveElementMessage::GameContextRemoveElementMessage()
{
  m_type = MessageEnum::GAMECONTEXTREMOVEELEMENTMESSAGE;
}

