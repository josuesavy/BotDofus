#include "TreasureHuntFlagRequestMessage.h"

void TreasureHuntFlagRequestMessage::serialize(Writer *output)
{
  this->serializeAs_TreasureHuntFlagRequestMessage(output);
}

void TreasureHuntFlagRequestMessage::serializeAs_TreasureHuntFlagRequestMessage(Writer *output)
{
  output->writeByte(this->questType);
  if(this->index < 0)
  {
    qDebug()<<"ERREUR - TreasureHuntFlagRequestMessage -"<<"Forbidden value (" << this->index << ") on element index.";
  }
  output->writeByte(this->index);
}

void TreasureHuntFlagRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_TreasureHuntFlagRequestMessage(input);
}

void TreasureHuntFlagRequestMessage::deserializeAs_TreasureHuntFlagRequestMessage(Reader *input)
{
  this->_questTypeFunc(input);
  this->_indexFunc(input);
}

void TreasureHuntFlagRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TreasureHuntFlagRequestMessage(tree);
}

void TreasureHuntFlagRequestMessage::deserializeAsyncAs_TreasureHuntFlagRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&TreasureHuntFlagRequestMessage::_questTypeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TreasureHuntFlagRequestMessage::_indexFunc, this, std::placeholders::_1));
}

void TreasureHuntFlagRequestMessage::_questTypeFunc(Reader *input)
{
  this->questType = input->readByte();
  if(this->questType < 0)
  {
    qDebug()<<"ERREUR - TreasureHuntFlagRequestMessage -"<<"Forbidden value (" << this->questType << ") on element of TreasureHuntFlagRequestMessage.questType.";
  }
}

void TreasureHuntFlagRequestMessage::_indexFunc(Reader *input)
{
  this->index = input->readByte();
  if(this->index < 0)
  {
    qDebug()<<"ERREUR - TreasureHuntFlagRequestMessage -"<<"Forbidden value (" << this->index << ") on element of TreasureHuntFlagRequestMessage.index.";
  }
}

TreasureHuntFlagRequestMessage::TreasureHuntFlagRequestMessage()
{
  m_type = MessageEnum::TREASUREHUNTFLAGREQUESTMESSAGE;
}

