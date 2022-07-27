#include "ClientUIOpenedMessage.h"

void ClientUIOpenedMessage::serialize(Writer *output)
{
  this->serializeAs_ClientUIOpenedMessage(output);
}

void ClientUIOpenedMessage::serializeAs_ClientUIOpenedMessage(Writer *output)
{
  output->writeByte(this->type);
}

void ClientUIOpenedMessage::deserialize(Reader *input)
{
  this->deserializeAs_ClientUIOpenedMessage(input);
}

void ClientUIOpenedMessage::deserializeAs_ClientUIOpenedMessage(Reader *input)
{
  this->_typeFunc(input);
}

void ClientUIOpenedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ClientUIOpenedMessage(tree);
}

void ClientUIOpenedMessage::deserializeAsyncAs_ClientUIOpenedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ClientUIOpenedMessage::_typeFunc, this, std::placeholders::_1));
}

void ClientUIOpenedMessage::_typeFunc(Reader *input)
{
  this->type = input->readByte();
  if(this->type < 0)
  {
    qDebug()<<"ERREUR - ClientUIOpenedMessage -"<<"Forbidden value (" << this->type << ") on element of ClientUIOpenedMessage.type.";
  }
}

ClientUIOpenedMessage::ClientUIOpenedMessage()
{
  m_type = MessageEnum::CLIENTUIOPENEDMESSAGE;
}

