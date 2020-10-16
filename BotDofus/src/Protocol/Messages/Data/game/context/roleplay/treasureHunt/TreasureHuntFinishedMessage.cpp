#include "TreasureHuntFinishedMessage.h"

void TreasureHuntFinishedMessage::serialize(Writer *output)
{
  this->serializeAs_TreasureHuntFinishedMessage(output);
}

void TreasureHuntFinishedMessage::serializeAs_TreasureHuntFinishedMessage(Writer *output)
{
  output->writeByte(this->questType);
}

void TreasureHuntFinishedMessage::deserialize(Reader *input)
{
  this->deserializeAs_TreasureHuntFinishedMessage(input);
}

void TreasureHuntFinishedMessage::deserializeAs_TreasureHuntFinishedMessage(Reader *input)
{
  this->_questTypeFunc(input);
}

void TreasureHuntFinishedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TreasureHuntFinishedMessage(tree);
}

void TreasureHuntFinishedMessage::deserializeAsyncAs_TreasureHuntFinishedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&TreasureHuntFinishedMessage::_questTypeFunc, this, std::placeholders::_1));
}

void TreasureHuntFinishedMessage::_questTypeFunc(Reader *input)
{
  this->questType = input->readByte();
  if(this->questType < 0)
  {
    qDebug()<<"ERREUR - TreasureHuntFinishedMessage -"<<"Forbidden value (" << this->questType << ") on element of TreasureHuntFinishedMessage.questType.";
  }
}

TreasureHuntFinishedMessage::TreasureHuntFinishedMessage()
{
  m_type = MessageEnum::TREASUREHUNTFINISHEDMESSAGE;
}

