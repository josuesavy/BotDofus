#include "IgnoredAddFailureMessage.h"

void IgnoredAddFailureMessage::serialize(Writer *output)
{
  this->serializeAs_IgnoredAddFailureMessage(output);
}

void IgnoredAddFailureMessage::serializeAs_IgnoredAddFailureMessage(Writer *output)
{
  output->writeByte(this->reason);
}

void IgnoredAddFailureMessage::deserialize(Reader *input)
{
  this->deserializeAs_IgnoredAddFailureMessage(input);
}

void IgnoredAddFailureMessage::deserializeAs_IgnoredAddFailureMessage(Reader *input)
{
  this->_reasonFunc(input);
}

void IgnoredAddFailureMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_IgnoredAddFailureMessage(tree);
}

void IgnoredAddFailureMessage::deserializeAsyncAs_IgnoredAddFailureMessage(FuncTree tree)
{
  tree.addChild(std::bind(&IgnoredAddFailureMessage::_reasonFunc, this, std::placeholders::_1));
}

void IgnoredAddFailureMessage::_reasonFunc(Reader *input)
{
  this->reason = input->readByte();
  if(this->reason < 0)
  {
    qDebug()<<"ERREUR - IgnoredAddFailureMessage -"<<"Forbidden value (" << this->reason << ") on element of IgnoredAddFailureMessage.reason.";
  }
}

IgnoredAddFailureMessage::IgnoredAddFailureMessage()
{
  m_type = MessageEnum::IGNOREDADDFAILUREMESSAGE;
}

