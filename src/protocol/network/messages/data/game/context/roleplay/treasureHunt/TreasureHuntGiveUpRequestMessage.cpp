#include "TreasureHuntGiveUpRequestMessage.h"

void TreasureHuntGiveUpRequestMessage::serialize(Writer *output)
{
  this->serializeAs_TreasureHuntGiveUpRequestMessage(output);
}

void TreasureHuntGiveUpRequestMessage::serializeAs_TreasureHuntGiveUpRequestMessage(Writer *output)
{
  output->writeByte(this->questType);
}

void TreasureHuntGiveUpRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_TreasureHuntGiveUpRequestMessage(input);
}

void TreasureHuntGiveUpRequestMessage::deserializeAs_TreasureHuntGiveUpRequestMessage(Reader *input)
{
  this->_questTypeFunc(input);
}

void TreasureHuntGiveUpRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TreasureHuntGiveUpRequestMessage(tree);
}

void TreasureHuntGiveUpRequestMessage::deserializeAsyncAs_TreasureHuntGiveUpRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&TreasureHuntGiveUpRequestMessage::_questTypeFunc, this, std::placeholders::_1));
}

void TreasureHuntGiveUpRequestMessage::_questTypeFunc(Reader *input)
{
  this->questType = input->readByte();
  if(this->questType < 0)
  {
    qDebug()<<"ERREUR - TreasureHuntGiveUpRequestMessage -"<<"Forbidden value (" << this->questType << ") on element of TreasureHuntGiveUpRequestMessage.questType.";
  }
}

TreasureHuntGiveUpRequestMessage::TreasureHuntGiveUpRequestMessage()
{
  m_type = MessageEnum::TREASUREHUNTGIVEUPREQUESTMESSAGE;
}

