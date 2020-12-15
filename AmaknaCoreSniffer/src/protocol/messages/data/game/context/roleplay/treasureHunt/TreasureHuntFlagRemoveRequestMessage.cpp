#include "TreasureHuntFlagRemoveRequestMessage.h"

void TreasureHuntFlagRemoveRequestMessage::serialize(Writer *output)
{
  this->serializeAs_TreasureHuntFlagRemoveRequestMessage(output);
}

void TreasureHuntFlagRemoveRequestMessage::serializeAs_TreasureHuntFlagRemoveRequestMessage(Writer *output)
{
  output->writeByte(this->questType);
  if(this->index < 0)
  {
    qDebug()<<"ERREUR - TreasureHuntFlagRemoveRequestMessage -"<<"Forbidden value (" << this->index << ") on element index.";
  }
  output->writeByte(this->index);
}

void TreasureHuntFlagRemoveRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_TreasureHuntFlagRemoveRequestMessage(input);
}

void TreasureHuntFlagRemoveRequestMessage::deserializeAs_TreasureHuntFlagRemoveRequestMessage(Reader *input)
{
  this->_questTypeFunc(input);
  this->_indexFunc(input);
}

void TreasureHuntFlagRemoveRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TreasureHuntFlagRemoveRequestMessage(tree);
}

void TreasureHuntFlagRemoveRequestMessage::deserializeAsyncAs_TreasureHuntFlagRemoveRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&TreasureHuntFlagRemoveRequestMessage::_questTypeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TreasureHuntFlagRemoveRequestMessage::_indexFunc, this, std::placeholders::_1));
}

void TreasureHuntFlagRemoveRequestMessage::_questTypeFunc(Reader *input)
{
  this->questType = input->readByte();
  if(this->questType < 0)
  {
    qDebug()<<"ERREUR - TreasureHuntFlagRemoveRequestMessage -"<<"Forbidden value (" << this->questType << ") on element of TreasureHuntFlagRemoveRequestMessage.questType.";
  }
}

void TreasureHuntFlagRemoveRequestMessage::_indexFunc(Reader *input)
{
  this->index = input->readByte();
  if(this->index < 0)
  {
    qDebug()<<"ERREUR - TreasureHuntFlagRemoveRequestMessage -"<<"Forbidden value (" << this->index << ") on element of TreasureHuntFlagRemoveRequestMessage.index.";
  }
}

TreasureHuntFlagRemoveRequestMessage::TreasureHuntFlagRemoveRequestMessage()
{
  m_type = MessageEnum::TREASUREHUNTFLAGREMOVEREQUESTMESSAGE;
}

