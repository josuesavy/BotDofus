#include "TreasureHuntDigRequestAnswerMessage.h"

void TreasureHuntDigRequestAnswerMessage::serialize(Writer *output)
{
  this->serializeAs_TreasureHuntDigRequestAnswerMessage(output);
}

void TreasureHuntDigRequestAnswerMessage::serializeAs_TreasureHuntDigRequestAnswerMessage(Writer *output)
{
  output->writeByte(this->questType);
  output->writeByte(this->result);
}

void TreasureHuntDigRequestAnswerMessage::deserialize(Reader *input)
{
  this->deserializeAs_TreasureHuntDigRequestAnswerMessage(input);
}

void TreasureHuntDigRequestAnswerMessage::deserializeAs_TreasureHuntDigRequestAnswerMessage(Reader *input)
{
  this->_questTypeFunc(input);
  this->_resultFunc(input);
}

void TreasureHuntDigRequestAnswerMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TreasureHuntDigRequestAnswerMessage(tree);
}

void TreasureHuntDigRequestAnswerMessage::deserializeAsyncAs_TreasureHuntDigRequestAnswerMessage(FuncTree tree)
{
  tree.addChild(std::bind(&TreasureHuntDigRequestAnswerMessage::_questTypeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TreasureHuntDigRequestAnswerMessage::_resultFunc, this, std::placeholders::_1));
}

void TreasureHuntDigRequestAnswerMessage::_questTypeFunc(Reader *input)
{
  this->questType = input->readByte();
  if(this->questType < 0)
  {
    qDebug()<<"ERREUR - TreasureHuntDigRequestAnswerMessage -"<<"Forbidden value (" << this->questType << ") on element of TreasureHuntDigRequestAnswerMessage.questType.";
  }
}

void TreasureHuntDigRequestAnswerMessage::_resultFunc(Reader *input)
{
  this->result = input->readByte();
  if(this->result < 0)
  {
    qDebug()<<"ERREUR - TreasureHuntDigRequestAnswerMessage -"<<"Forbidden value (" << this->result << ") on element of TreasureHuntDigRequestAnswerMessage.result.";
  }
}

TreasureHuntDigRequestAnswerMessage::TreasureHuntDigRequestAnswerMessage()
{
  m_type = MessageEnum::TREASUREHUNTDIGREQUESTANSWERMESSAGE;
}

