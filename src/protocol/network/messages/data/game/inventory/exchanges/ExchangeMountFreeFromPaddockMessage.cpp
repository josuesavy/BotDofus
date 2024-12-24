#include "ExchangeMountFreeFromPaddockMessage.h"

void ExchangeMountFreeFromPaddockMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeMountFreeFromPaddockMessage(output);
}

void ExchangeMountFreeFromPaddockMessage::serializeAs_ExchangeMountFreeFromPaddockMessage(Writer *output)
{
  output->writeUTF(this->name);
  if(this->worldX < -255 || this->worldX > 255)
  {
    qDebug()<<"ERREUR - ExchangeMountFreeFromPaddockMessage -"<<"Forbidden value (" << this->worldX << ") on element worldX.";
  }
  output->writeShort((short)this->worldX);
  if(this->worldY < -255 || this->worldY > 255)
  {
    qDebug()<<"ERREUR - ExchangeMountFreeFromPaddockMessage -"<<"Forbidden value (" << this->worldY << ") on element worldY.";
  }
  output->writeShort((short)this->worldY);
  output->writeUTF(this->liberator);
}

void ExchangeMountFreeFromPaddockMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeMountFreeFromPaddockMessage(input);
}

void ExchangeMountFreeFromPaddockMessage::deserializeAs_ExchangeMountFreeFromPaddockMessage(Reader *input)
{
  this->_nameFunc(input);
  this->_worldXFunc(input);
  this->_worldYFunc(input);
  this->_liberatorFunc(input);
}

void ExchangeMountFreeFromPaddockMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeMountFreeFromPaddockMessage(tree);
}

void ExchangeMountFreeFromPaddockMessage::deserializeAsyncAs_ExchangeMountFreeFromPaddockMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ExchangeMountFreeFromPaddockMessage::_nameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangeMountFreeFromPaddockMessage::_worldXFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangeMountFreeFromPaddockMessage::_worldYFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangeMountFreeFromPaddockMessage::_liberatorFunc, this, std::placeholders::_1));
}

void ExchangeMountFreeFromPaddockMessage::_nameFunc(Reader *input)
{
  this->name = input->readUTF();
}

void ExchangeMountFreeFromPaddockMessage::_worldXFunc(Reader *input)
{
  this->worldX = input->readShort();
  if(this->worldX < -255 || this->worldX > 255)
  {
    qDebug()<<"ERREUR - ExchangeMountFreeFromPaddockMessage -"<<"Forbidden value (" << this->worldX << ") on element of ExchangeMountFreeFromPaddockMessage.worldX.";
  }
}

void ExchangeMountFreeFromPaddockMessage::_worldYFunc(Reader *input)
{
  this->worldY = input->readShort();
  if(this->worldY < -255 || this->worldY > 255)
  {
    qDebug()<<"ERREUR - ExchangeMountFreeFromPaddockMessage -"<<"Forbidden value (" << this->worldY << ") on element of ExchangeMountFreeFromPaddockMessage.worldY.";
  }
}

void ExchangeMountFreeFromPaddockMessage::_liberatorFunc(Reader *input)
{
  this->liberator = input->readUTF();
}

ExchangeMountFreeFromPaddockMessage::ExchangeMountFreeFromPaddockMessage()
{
  m_type = MessageEnum::EXCHANGEMOUNTFREEFROMPADDOCKMESSAGE;
}

