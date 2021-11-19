#include "ExchangeMountSterilizeFromPaddockMessage.h"

void ExchangeMountSterilizeFromPaddockMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeMountSterilizeFromPaddockMessage(output);
}

void ExchangeMountSterilizeFromPaddockMessage::serializeAs_ExchangeMountSterilizeFromPaddockMessage(Writer *output)
{
  output->writeUTF(this->name);
  if(this->worldX < -255 || this->worldX > 255)
  {
    qDebug()<<"ERREUR - ExchangeMountSterilizeFromPaddockMessage -"<<"Forbidden value (" << this->worldX << ") on element worldX.";
  }
  output->writeShort((short)this->worldX);
  if(this->worldY < -255 || this->worldY > 255)
  {
    qDebug()<<"ERREUR - ExchangeMountSterilizeFromPaddockMessage -"<<"Forbidden value (" << this->worldY << ") on element worldY.";
  }
  output->writeShort((short)this->worldY);
  output->writeUTF(this->sterilizator);
}

void ExchangeMountSterilizeFromPaddockMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeMountSterilizeFromPaddockMessage(input);
}

void ExchangeMountSterilizeFromPaddockMessage::deserializeAs_ExchangeMountSterilizeFromPaddockMessage(Reader *input)
{
  this->_nameFunc(input);
  this->_worldXFunc(input);
  this->_worldYFunc(input);
  this->_sterilizatorFunc(input);
}

void ExchangeMountSterilizeFromPaddockMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeMountSterilizeFromPaddockMessage(tree);
}

void ExchangeMountSterilizeFromPaddockMessage::deserializeAsyncAs_ExchangeMountSterilizeFromPaddockMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ExchangeMountSterilizeFromPaddockMessage::_nameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangeMountSterilizeFromPaddockMessage::_worldXFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangeMountSterilizeFromPaddockMessage::_worldYFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangeMountSterilizeFromPaddockMessage::_sterilizatorFunc, this, std::placeholders::_1));
}

void ExchangeMountSterilizeFromPaddockMessage::_nameFunc(Reader *input)
{
  this->name = input->readUTF();
}

void ExchangeMountSterilizeFromPaddockMessage::_worldXFunc(Reader *input)
{
  this->worldX = input->readShort();
  if(this->worldX < -255 || this->worldX > 255)
  {
    qDebug()<<"ERREUR - ExchangeMountSterilizeFromPaddockMessage -"<<"Forbidden value (" << this->worldX << ") on element of ExchangeMountSterilizeFromPaddockMessage.worldX.";
  }
}

void ExchangeMountSterilizeFromPaddockMessage::_worldYFunc(Reader *input)
{
  this->worldY = input->readShort();
  if(this->worldY < -255 || this->worldY > 255)
  {
    qDebug()<<"ERREUR - ExchangeMountSterilizeFromPaddockMessage -"<<"Forbidden value (" << this->worldY << ") on element of ExchangeMountSterilizeFromPaddockMessage.worldY.";
  }
}

void ExchangeMountSterilizeFromPaddockMessage::_sterilizatorFunc(Reader *input)
{
  this->sterilizator = input->readUTF();
}

ExchangeMountSterilizeFromPaddockMessage::ExchangeMountSterilizeFromPaddockMessage()
{
  m_type = MessageEnum::EXCHANGEMOUNTSTERILIZEFROMPADDOCKMESSAGE;
}

