#include "GameContextRemoveElementWithEventMessage.h"

void GameContextRemoveElementWithEventMessage::serialize(Writer *output)
{
  this->serializeAs_GameContextRemoveElementWithEventMessage(output);
}

void GameContextRemoveElementWithEventMessage::serializeAs_GameContextRemoveElementWithEventMessage(Writer *output)
{
  GameContextRemoveElementMessage::serializeAs_GameContextRemoveElementMessage(output);
  if(this->elementEventId < 0)
  {
    qDebug()<<"ERREUR - GameContextRemoveElementWithEventMessage -"<<"Forbidden value (" << this->elementEventId << ") on element elementEventId.";
  }
  output->writeByte(this->elementEventId);
}

void GameContextRemoveElementWithEventMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameContextRemoveElementWithEventMessage(input);
}

void GameContextRemoveElementWithEventMessage::deserializeAs_GameContextRemoveElementWithEventMessage(Reader *input)
{
  GameContextRemoveElementMessage::deserialize(input);
  this->_elementEventIdFunc(input);
}

void GameContextRemoveElementWithEventMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameContextRemoveElementWithEventMessage(tree);
}

void GameContextRemoveElementWithEventMessage::deserializeAsyncAs_GameContextRemoveElementWithEventMessage(FuncTree tree)
{
  GameContextRemoveElementMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&GameContextRemoveElementWithEventMessage::_elementEventIdFunc, this, std::placeholders::_1));
}

void GameContextRemoveElementWithEventMessage::_elementEventIdFunc(Reader *input)
{
  this->elementEventId = input->readByte();
  if(this->elementEventId < 0)
  {
    qDebug()<<"ERREUR - GameContextRemoveElementWithEventMessage -"<<"Forbidden value (" << this->elementEventId << ") on element of GameContextRemoveElementWithEventMessage.elementEventId.";
  }
}

GameContextRemoveElementWithEventMessage::GameContextRemoveElementWithEventMessage()
{
  m_type = MessageEnum::GAMECONTEXTREMOVEELEMENTWITHEVENTMESSAGE;
}

