#include "TreasureHuntRequestAnswerMessage.h"

void TreasureHuntRequestAnswerMessage::serialize(Writer *output)
{
  this->serializeAs_TreasureHuntRequestAnswerMessage(output);
}

void TreasureHuntRequestAnswerMessage::serializeAs_TreasureHuntRequestAnswerMessage(Writer *output)
{
  output->writeByte(this->questType);
  output->writeByte(this->result);
}

void TreasureHuntRequestAnswerMessage::deserialize(Reader *input)
{
  this->deserializeAs_TreasureHuntRequestAnswerMessage(input);
}

void TreasureHuntRequestAnswerMessage::deserializeAs_TreasureHuntRequestAnswerMessage(Reader *input)
{
  this->_questTypeFunc(input);
  this->_resultFunc(input);
}

void TreasureHuntRequestAnswerMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TreasureHuntRequestAnswerMessage(tree);
}

void TreasureHuntRequestAnswerMessage::deserializeAsyncAs_TreasureHuntRequestAnswerMessage(FuncTree tree)
{
  tree.addChild(std::bind(&TreasureHuntRequestAnswerMessage::_questTypeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TreasureHuntRequestAnswerMessage::_resultFunc, this, std::placeholders::_1));
}

void TreasureHuntRequestAnswerMessage::_questTypeFunc(Reader *input)
{
  this->questType = input->readByte();
  if(this->questType < 0)
  {
    qDebug()<<"ERREUR - TreasureHuntRequestAnswerMessage -"<<"Forbidden value (" << this->questType << ") on element of TreasureHuntRequestAnswerMessage.questType.";
  }
}

void TreasureHuntRequestAnswerMessage::_resultFunc(Reader *input)
{
  this->result = input->readByte();
  if(this->result < 0)
  {
    qDebug()<<"ERREUR - TreasureHuntRequestAnswerMessage -"<<"Forbidden value (" << this->result << ") on element of TreasureHuntRequestAnswerMessage.result.";
  }
}

TreasureHuntRequestAnswerMessage::TreasureHuntRequestAnswerMessage()
{
  m_type = MessageEnum::TREASUREHUNTREQUESTANSWERMESSAGE;
}

