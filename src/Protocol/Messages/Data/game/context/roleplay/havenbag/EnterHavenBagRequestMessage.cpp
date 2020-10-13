#include "EnterHavenBagRequestMessage.h"

void EnterHavenBagRequestMessage::serialize(Writer *output)
{
  this->serializeAs_EnterHavenBagRequestMessage(output);
}

void EnterHavenBagRequestMessage::serializeAs_EnterHavenBagRequestMessage(Writer *output)
{
  if(this->havenBagOwner < 0 || this->havenBagOwner > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - EnterHavenBagRequestMessage -"<<"Forbidden value (" << this->havenBagOwner << ") on element havenBagOwner.";
  }
  output->writeVarLong((double)this->havenBagOwner);
}

void EnterHavenBagRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_EnterHavenBagRequestMessage(input);
}

void EnterHavenBagRequestMessage::deserializeAs_EnterHavenBagRequestMessage(Reader *input)
{
  this->_havenBagOwnerFunc(input);
}

void EnterHavenBagRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_EnterHavenBagRequestMessage(tree);
}

void EnterHavenBagRequestMessage::deserializeAsyncAs_EnterHavenBagRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&EnterHavenBagRequestMessage::_havenBagOwnerFunc, this, std::placeholders::_1));
}

void EnterHavenBagRequestMessage::_havenBagOwnerFunc(Reader *input)
{
  this->havenBagOwner = input->readVarUhLong();
  if(this->havenBagOwner < 0 || this->havenBagOwner > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - EnterHavenBagRequestMessage -"<<"Forbidden value (" << this->havenBagOwner << ") on element of EnterHavenBagRequestMessage.havenBagOwner.";
  }
}

EnterHavenBagRequestMessage::EnterHavenBagRequestMessage()
{
  m_type = MessageEnum::ENTERHAVENBAGREQUESTMESSAGE;
}

