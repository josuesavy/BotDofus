#include "TreasureHuntDigRequestAnswerFailedMessage.h"

void TreasureHuntDigRequestAnswerFailedMessage::serialize(Writer *output)
{
  this->serializeAs_TreasureHuntDigRequestAnswerFailedMessage(output);
}

void TreasureHuntDigRequestAnswerFailedMessage::serializeAs_TreasureHuntDigRequestAnswerFailedMessage(Writer *output)
{
  TreasureHuntDigRequestAnswerMessage::serializeAs_TreasureHuntDigRequestAnswerMessage(output);
  if(this->wrongFlagCount < 0)
  {
    qDebug()<<"ERREUR - TreasureHuntDigRequestAnswerFailedMessage -"<<"Forbidden value (" << this->wrongFlagCount << ") on element wrongFlagCount.";
  }
  output->writeByte(this->wrongFlagCount);
}

void TreasureHuntDigRequestAnswerFailedMessage::deserialize(Reader *input)
{
  this->deserializeAs_TreasureHuntDigRequestAnswerFailedMessage(input);
}

void TreasureHuntDigRequestAnswerFailedMessage::deserializeAs_TreasureHuntDigRequestAnswerFailedMessage(Reader *input)
{
  TreasureHuntDigRequestAnswerMessage::deserialize(input);
  this->_wrongFlagCountFunc(input);
}

void TreasureHuntDigRequestAnswerFailedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TreasureHuntDigRequestAnswerFailedMessage(tree);
}

void TreasureHuntDigRequestAnswerFailedMessage::deserializeAsyncAs_TreasureHuntDigRequestAnswerFailedMessage(FuncTree tree)
{
  TreasureHuntDigRequestAnswerMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&TreasureHuntDigRequestAnswerFailedMessage::_wrongFlagCountFunc, this, std::placeholders::_1));
}

void TreasureHuntDigRequestAnswerFailedMessage::_wrongFlagCountFunc(Reader *input)
{
  this->wrongFlagCount = input->readByte();
  if(this->wrongFlagCount < 0)
  {
    qDebug()<<"ERREUR - TreasureHuntDigRequestAnswerFailedMessage -"<<"Forbidden value (" << this->wrongFlagCount << ") on element of TreasureHuntDigRequestAnswerFailedMessage.wrongFlagCount.";
  }
}

TreasureHuntDigRequestAnswerFailedMessage::TreasureHuntDigRequestAnswerFailedMessage()
{
  m_type = MessageEnum::TREASUREHUNTDIGREQUESTANSWERFAILEDMESSAGE;
}

