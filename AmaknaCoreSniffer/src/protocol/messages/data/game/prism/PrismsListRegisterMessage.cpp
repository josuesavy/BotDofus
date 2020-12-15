#include "PrismsListRegisterMessage.h"

void PrismsListRegisterMessage::serialize(Writer *output)
{
  this->serializeAs_PrismsListRegisterMessage(output);
}

void PrismsListRegisterMessage::serializeAs_PrismsListRegisterMessage(Writer *output)
{
  output->writeByte(this->listen);
}

void PrismsListRegisterMessage::deserialize(Reader *input)
{
  this->deserializeAs_PrismsListRegisterMessage(input);
}

void PrismsListRegisterMessage::deserializeAs_PrismsListRegisterMessage(Reader *input)
{
  this->_listenFunc(input);
}

void PrismsListRegisterMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PrismsListRegisterMessage(tree);
}

void PrismsListRegisterMessage::deserializeAsyncAs_PrismsListRegisterMessage(FuncTree tree)
{
  tree.addChild(std::bind(&PrismsListRegisterMessage::_listenFunc, this, std::placeholders::_1));
}

void PrismsListRegisterMessage::_listenFunc(Reader *input)
{
  this->listen = input->readByte();
  if(this->listen < 0)
  {
    qDebug()<<"ERREUR - PrismsListRegisterMessage -"<<"Forbidden value (" << this->listen << ") on element of PrismsListRegisterMessage.listen.";
  }
}

PrismsListRegisterMessage::PrismsListRegisterMessage()
{
  m_type = MessageEnum::PRISMSLISTREGISTERMESSAGE;
}

