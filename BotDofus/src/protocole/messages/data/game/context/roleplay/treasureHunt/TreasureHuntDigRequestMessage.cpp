#include "TreasureHuntDigRequestMessage.h"

void TreasureHuntDigRequestMessage::serialize(Writer *output)
{
  this->serializeAs_TreasureHuntDigRequestMessage(output);
}

void TreasureHuntDigRequestMessage::serializeAs_TreasureHuntDigRequestMessage(Writer *output)
{
  output->writeByte(this->questType);
}

void TreasureHuntDigRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_TreasureHuntDigRequestMessage(input);
}

void TreasureHuntDigRequestMessage::deserializeAs_TreasureHuntDigRequestMessage(Reader *input)
{
  this->_questTypeFunc(input);
}

void TreasureHuntDigRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TreasureHuntDigRequestMessage(tree);
}

void TreasureHuntDigRequestMessage::deserializeAsyncAs_TreasureHuntDigRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&TreasureHuntDigRequestMessage::_questTypeFunc, this, std::placeholders::_1));
}

void TreasureHuntDigRequestMessage::_questTypeFunc(Reader *input)
{
  this->questType = input->readByte();
  if(this->questType < 0)
  {
    qDebug()<<"ERREUR - TreasureHuntDigRequestMessage -"<<"Forbidden value (" << this->questType << ") on element of TreasureHuntDigRequestMessage.questType.";
  }
}

TreasureHuntDigRequestMessage::TreasureHuntDigRequestMessage()
{
  m_type = MessageEnum::TREASUREHUNTDIGREQUESTMESSAGE;
}

