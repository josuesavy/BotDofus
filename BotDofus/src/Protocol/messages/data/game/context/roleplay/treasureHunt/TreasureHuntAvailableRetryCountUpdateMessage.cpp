#include "TreasureHuntAvailableRetryCountUpdateMessage.h"

void TreasureHuntAvailableRetryCountUpdateMessage::serialize(Writer *output)
{
  this->serializeAs_TreasureHuntAvailableRetryCountUpdateMessage(output);
}

void TreasureHuntAvailableRetryCountUpdateMessage::serializeAs_TreasureHuntAvailableRetryCountUpdateMessage(Writer *output)
{
  output->writeByte(this->questType);
  output->writeInt((int)this->availableRetryCount);
}

void TreasureHuntAvailableRetryCountUpdateMessage::deserialize(Reader *input)
{
  this->deserializeAs_TreasureHuntAvailableRetryCountUpdateMessage(input);
}

void TreasureHuntAvailableRetryCountUpdateMessage::deserializeAs_TreasureHuntAvailableRetryCountUpdateMessage(Reader *input)
{
  this->_questTypeFunc(input);
  this->_availableRetryCountFunc(input);
}

void TreasureHuntAvailableRetryCountUpdateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TreasureHuntAvailableRetryCountUpdateMessage(tree);
}

void TreasureHuntAvailableRetryCountUpdateMessage::deserializeAsyncAs_TreasureHuntAvailableRetryCountUpdateMessage(FuncTree tree)
{
  tree.addChild(std::bind(&TreasureHuntAvailableRetryCountUpdateMessage::_questTypeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TreasureHuntAvailableRetryCountUpdateMessage::_availableRetryCountFunc, this, std::placeholders::_1));
}

void TreasureHuntAvailableRetryCountUpdateMessage::_questTypeFunc(Reader *input)
{
  this->questType = input->readByte();
  if(this->questType < 0)
  {
    qDebug()<<"ERREUR - TreasureHuntAvailableRetryCountUpdateMessage -"<<"Forbidden value (" << this->questType << ") on element of TreasureHuntAvailableRetryCountUpdateMessage.questType.";
  }
}

void TreasureHuntAvailableRetryCountUpdateMessage::_availableRetryCountFunc(Reader *input)
{
  this->availableRetryCount = input->readInt();
}

TreasureHuntAvailableRetryCountUpdateMessage::TreasureHuntAvailableRetryCountUpdateMessage()
{
  m_type = MessageEnum::TREASUREHUNTAVAILABLERETRYCOUNTUPDATEMESSAGE;
}

