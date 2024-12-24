#include "GameActionItemConsumedMessage.h"

void GameActionItemConsumedMessage::serialize(Writer *output)
{
  this->serializeAs_GameActionItemConsumedMessage(output);
}

void GameActionItemConsumedMessage::serializeAs_GameActionItemConsumedMessage(Writer *output)
{
  uint _box0 = 0;
  _box0 = BooleanByteWrapper::setFlag(_box0, 0, this->success);
  _box0 = BooleanByteWrapper::setFlag(_box0, 1, this->automaticAction);
  output->writeByte(_box0);
  if(this->actionId < 0)
  {
    qDebug()<<"ERREUR - GameActionItemConsumedMessage -"<<"Forbidden value (" << this->actionId << ") on element actionId.";
  }
  output->writeInt((int)this->actionId);
}

void GameActionItemConsumedMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameActionItemConsumedMessage(input);
}

void GameActionItemConsumedMessage::deserializeAs_GameActionItemConsumedMessage(Reader *input)
{
  this->deserializeByteBoxes(input);
  this->_actionIdFunc(input);
}

void GameActionItemConsumedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameActionItemConsumedMessage(tree);
}

void GameActionItemConsumedMessage::deserializeAsyncAs_GameActionItemConsumedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GameActionItemConsumedMessage::deserializeByteBoxes, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameActionItemConsumedMessage::_actionIdFunc, this, std::placeholders::_1));
}

void GameActionItemConsumedMessage::deserializeByteBoxes(Reader *input)
{
  uint _box0 = uint(input->readByte());
  this->success = BooleanByteWrapper::getFlag(_box0, 0);
  this->automaticAction = BooleanByteWrapper::getFlag(_box0, 1);
}

void GameActionItemConsumedMessage::_actionIdFunc(Reader *input)
{
  this->actionId = input->readInt();
  if(this->actionId < 0)
  {
    qDebug()<<"ERREUR - GameActionItemConsumedMessage -"<<"Forbidden value (" << this->actionId << ") on element of GameActionItemConsumedMessage.actionId.";
  }
}

GameActionItemConsumedMessage::GameActionItemConsumedMessage()
{
  m_type = MessageEnum::GAMEACTIONITEMCONSUMEDMESSAGE;
}

