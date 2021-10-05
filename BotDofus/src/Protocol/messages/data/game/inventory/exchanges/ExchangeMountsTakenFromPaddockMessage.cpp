#include "ExchangeMountsTakenFromPaddockMessage.h"

void ExchangeMountsTakenFromPaddockMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeMountsTakenFromPaddockMessage(output);
}

void ExchangeMountsTakenFromPaddockMessage::serializeAs_ExchangeMountsTakenFromPaddockMessage(Writer *output)
{
  output->writeUTF(this->name);
  if(this->worldX < -255 || this->worldX > 255)
  {
    qDebug()<<"ERREUR - ExchangeMountsTakenFromPaddockMessage -"<<"Forbidden value (" << this->worldX << ") on element worldX.";
  }
  output->writeShort((short)this->worldX);
  if(this->worldY < -255 || this->worldY > 255)
  {
    qDebug()<<"ERREUR - ExchangeMountsTakenFromPaddockMessage -"<<"Forbidden value (" << this->worldY << ") on element worldY.";
  }
  output->writeShort((short)this->worldY);
  output->writeUTF(this->ownername);
}

void ExchangeMountsTakenFromPaddockMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeMountsTakenFromPaddockMessage(input);
}

void ExchangeMountsTakenFromPaddockMessage::deserializeAs_ExchangeMountsTakenFromPaddockMessage(Reader *input)
{
  this->_nameFunc(input);
  this->_worldXFunc(input);
  this->_worldYFunc(input);
  this->_ownernameFunc(input);
}

void ExchangeMountsTakenFromPaddockMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeMountsTakenFromPaddockMessage(tree);
}

void ExchangeMountsTakenFromPaddockMessage::deserializeAsyncAs_ExchangeMountsTakenFromPaddockMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ExchangeMountsTakenFromPaddockMessage::_nameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangeMountsTakenFromPaddockMessage::_worldXFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangeMountsTakenFromPaddockMessage::_worldYFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangeMountsTakenFromPaddockMessage::_ownernameFunc, this, std::placeholders::_1));
}

void ExchangeMountsTakenFromPaddockMessage::_nameFunc(Reader *input)
{
  this->name = input->readUTF();
}

void ExchangeMountsTakenFromPaddockMessage::_worldXFunc(Reader *input)
{
  this->worldX = input->readShort();
  if(this->worldX < -255 || this->worldX > 255)
  {
    qDebug()<<"ERREUR - ExchangeMountsTakenFromPaddockMessage -"<<"Forbidden value (" << this->worldX << ") on element of ExchangeMountsTakenFromPaddockMessage.worldX.";
  }
}

void ExchangeMountsTakenFromPaddockMessage::_worldYFunc(Reader *input)
{
  this->worldY = input->readShort();
  if(this->worldY < -255 || this->worldY > 255)
  {
    qDebug()<<"ERREUR - ExchangeMountsTakenFromPaddockMessage -"<<"Forbidden value (" << this->worldY << ") on element of ExchangeMountsTakenFromPaddockMessage.worldY.";
  }
}

void ExchangeMountsTakenFromPaddockMessage::_ownernameFunc(Reader *input)
{
  this->ownername = input->readUTF();
}

ExchangeMountsTakenFromPaddockMessage::ExchangeMountsTakenFromPaddockMessage()
{
  m_type = MessageEnum::EXCHANGEMOUNTSTAKENFROMPADDOCKMESSAGE;
}

