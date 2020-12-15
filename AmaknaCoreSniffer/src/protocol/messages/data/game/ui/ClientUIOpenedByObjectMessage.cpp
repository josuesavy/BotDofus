#include "ClientUIOpenedByObjectMessage.h"

void ClientUIOpenedByObjectMessage::serialize(Writer *output)
{
  this->serializeAs_ClientUIOpenedByObjectMessage(output);
}

void ClientUIOpenedByObjectMessage::serializeAs_ClientUIOpenedByObjectMessage(Writer *output)
{
  ClientUIOpenedMessage::serializeAs_ClientUIOpenedMessage(output);
  if(this->uid < 0)
  {
    qDebug()<<"ERREUR - ClientUIOpenedByObjectMessage -"<<"Forbidden value (" << this->uid << ") on element uid.";
  }
  output->writeVarInt((int)this->uid);
}

void ClientUIOpenedByObjectMessage::deserialize(Reader *input)
{
  this->deserializeAs_ClientUIOpenedByObjectMessage(input);
}

void ClientUIOpenedByObjectMessage::deserializeAs_ClientUIOpenedByObjectMessage(Reader *input)
{
  ClientUIOpenedMessage::deserialize(input);
  this->_uidFunc(input);
}

void ClientUIOpenedByObjectMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ClientUIOpenedByObjectMessage(tree);
}

void ClientUIOpenedByObjectMessage::deserializeAsyncAs_ClientUIOpenedByObjectMessage(FuncTree tree)
{
  ClientUIOpenedMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&ClientUIOpenedByObjectMessage::_uidFunc, this, std::placeholders::_1));
}

void ClientUIOpenedByObjectMessage::_uidFunc(Reader *input)
{
  this->uid = input->readVarUhInt();
  if(this->uid < 0)
  {
    qDebug()<<"ERREUR - ClientUIOpenedByObjectMessage -"<<"Forbidden value (" << this->uid << ") on element of ClientUIOpenedByObjectMessage.uid.";
  }
}

ClientUIOpenedByObjectMessage::ClientUIOpenedByObjectMessage()
{
  m_type = MessageEnum::CLIENTUIOPENEDBYOBJECTMESSAGE;
}

