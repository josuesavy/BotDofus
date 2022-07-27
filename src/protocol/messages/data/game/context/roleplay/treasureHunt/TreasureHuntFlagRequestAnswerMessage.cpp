#include "TreasureHuntFlagRequestAnswerMessage.h"

void TreasureHuntFlagRequestAnswerMessage::serialize(Writer *output)
{
  this->serializeAs_TreasureHuntFlagRequestAnswerMessage(output);
}

void TreasureHuntFlagRequestAnswerMessage::serializeAs_TreasureHuntFlagRequestAnswerMessage(Writer *output)
{
  output->writeByte(this->questType);
  output->writeByte(this->result);
  if(this->index < 0)
  {
    qDebug()<<"ERREUR - TreasureHuntFlagRequestAnswerMessage -"<<"Forbidden value (" << this->index << ") on element index.";
  }
  output->writeByte(this->index);
}

void TreasureHuntFlagRequestAnswerMessage::deserialize(Reader *input)
{
  this->deserializeAs_TreasureHuntFlagRequestAnswerMessage(input);
}

void TreasureHuntFlagRequestAnswerMessage::deserializeAs_TreasureHuntFlagRequestAnswerMessage(Reader *input)
{
  this->_questTypeFunc(input);
  this->_resultFunc(input);
  this->_indexFunc(input);
}

void TreasureHuntFlagRequestAnswerMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TreasureHuntFlagRequestAnswerMessage(tree);
}

void TreasureHuntFlagRequestAnswerMessage::deserializeAsyncAs_TreasureHuntFlagRequestAnswerMessage(FuncTree tree)
{
  tree.addChild(std::bind(&TreasureHuntFlagRequestAnswerMessage::_questTypeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TreasureHuntFlagRequestAnswerMessage::_resultFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TreasureHuntFlagRequestAnswerMessage::_indexFunc, this, std::placeholders::_1));
}

void TreasureHuntFlagRequestAnswerMessage::_questTypeFunc(Reader *input)
{
  this->questType = input->readByte();
  if(this->questType < 0)
  {
    qDebug()<<"ERREUR - TreasureHuntFlagRequestAnswerMessage -"<<"Forbidden value (" << this->questType << ") on element of TreasureHuntFlagRequestAnswerMessage.questType.";
  }
}

void TreasureHuntFlagRequestAnswerMessage::_resultFunc(Reader *input)
{
  this->result = input->readByte();
  if(this->result < 0)
  {
    qDebug()<<"ERREUR - TreasureHuntFlagRequestAnswerMessage -"<<"Forbidden value (" << this->result << ") on element of TreasureHuntFlagRequestAnswerMessage.result.";
  }
}

void TreasureHuntFlagRequestAnswerMessage::_indexFunc(Reader *input)
{
  this->index = input->readByte();
  if(this->index < 0)
  {
    qDebug()<<"ERREUR - TreasureHuntFlagRequestAnswerMessage -"<<"Forbidden value (" << this->index << ") on element of TreasureHuntFlagRequestAnswerMessage.index.";
  }
}

TreasureHuntFlagRequestAnswerMessage::TreasureHuntFlagRequestAnswerMessage()
{
  m_type = MessageEnum::TREASUREHUNTFLAGREQUESTANSWERMESSAGE;
}

