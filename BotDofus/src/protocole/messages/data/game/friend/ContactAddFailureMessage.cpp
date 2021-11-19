#include "ContactAddFailureMessage.h"

void ContactAddFailureMessage::serialize(Writer *output)
{
  this->serializeAs_ContactAddFailureMessage(output);
}

void ContactAddFailureMessage::serializeAs_ContactAddFailureMessage(Writer *output)
{
  output->writeByte(this->reason);
}

void ContactAddFailureMessage::deserialize(Reader *input)
{
  this->deserializeAs_ContactAddFailureMessage(input);
}

void ContactAddFailureMessage::deserializeAs_ContactAddFailureMessage(Reader *input)
{
  this->_reasonFunc(input);
}

void ContactAddFailureMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ContactAddFailureMessage(tree);
}

void ContactAddFailureMessage::deserializeAsyncAs_ContactAddFailureMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ContactAddFailureMessage::_reasonFunc, this, std::placeholders::_1));
}

void ContactAddFailureMessage::_reasonFunc(Reader *input)
{
  this->reason = input->readByte();
  if(this->reason < 0)
  {
    qDebug()<<"ERREUR - ContactAddFailureMessage -"<<"Forbidden value (" << this->reason << ") on element of ContactAddFailureMessage.reason.";
  }
}

ContactAddFailureMessage::ContactAddFailureMessage()
{
  m_type = MessageEnum::CONTACTADDFAILUREMESSAGE;
}

