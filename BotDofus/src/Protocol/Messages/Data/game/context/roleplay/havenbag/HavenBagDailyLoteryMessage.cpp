#include "HavenBagDailyLoteryMessage.h"

void HavenBagDailyLoteryMessage::serialize(Writer *output)
{
  this->serializeAs_HavenBagDailyLoteryMessage(output);
}

void HavenBagDailyLoteryMessage::serializeAs_HavenBagDailyLoteryMessage(Writer *output)
{
  output->writeByte(this->returnType);
  output->writeUTF(this->gameActionId);
}

void HavenBagDailyLoteryMessage::deserialize(Reader *input)
{
  this->deserializeAs_HavenBagDailyLoteryMessage(input);
}

void HavenBagDailyLoteryMessage::deserializeAs_HavenBagDailyLoteryMessage(Reader *input)
{
  this->_returnTypeFunc(input);
  this->_gameActionIdFunc(input);
}

void HavenBagDailyLoteryMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_HavenBagDailyLoteryMessage(tree);
}

void HavenBagDailyLoteryMessage::deserializeAsyncAs_HavenBagDailyLoteryMessage(FuncTree tree)
{
  tree.addChild(std::bind(&HavenBagDailyLoteryMessage::_returnTypeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HavenBagDailyLoteryMessage::_gameActionIdFunc, this, std::placeholders::_1));
}

void HavenBagDailyLoteryMessage::_returnTypeFunc(Reader *input)
{
  this->returnType = input->readByte();
  if(this->returnType < 0)
  {
    qDebug()<<"ERREUR - HavenBagDailyLoteryMessage -"<<"Forbidden value (" << this->returnType << ") on element of HavenBagDailyLoteryMessage.returnType.";
  }
}

void HavenBagDailyLoteryMessage::_gameActionIdFunc(Reader *input)
{
  this->gameActionId = input->readUTF();
}

HavenBagDailyLoteryMessage::HavenBagDailyLoteryMessage()
{
  m_type = MessageEnum::HAVENBAGDAILYLOTERYMESSAGE;
}

