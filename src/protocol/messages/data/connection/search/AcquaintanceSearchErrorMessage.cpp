#include "AcquaintanceSearchErrorMessage.h"

void AcquaintanceSearchErrorMessage::serialize(Writer *output)
{
  this->serializeAs_AcquaintanceSearchErrorMessage(output);
}

void AcquaintanceSearchErrorMessage::serializeAs_AcquaintanceSearchErrorMessage(Writer *output)
{
  output->writeByte(this->reason);
}

void AcquaintanceSearchErrorMessage::deserialize(Reader *input)
{
  this->deserializeAs_AcquaintanceSearchErrorMessage(input);
}

void AcquaintanceSearchErrorMessage::deserializeAs_AcquaintanceSearchErrorMessage(Reader *input)
{
  this->_reasonFunc(input);
}

void AcquaintanceSearchErrorMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AcquaintanceSearchErrorMessage(tree);
}

void AcquaintanceSearchErrorMessage::deserializeAsyncAs_AcquaintanceSearchErrorMessage(FuncTree tree)
{
  tree.addChild(std::bind(&AcquaintanceSearchErrorMessage::_reasonFunc, this, std::placeholders::_1));
}

void AcquaintanceSearchErrorMessage::_reasonFunc(Reader *input)
{
  this->reason = input->readByte();
  if(this->reason < 0)
  {
    qDebug()<<"ERREUR - AcquaintanceSearchErrorMessage -"<<"Forbidden value (" << this->reason << ") on element of AcquaintanceSearchErrorMessage.reason.";
  }
}

AcquaintanceSearchErrorMessage::AcquaintanceSearchErrorMessage()
{
  m_type = MessageEnum::ACQUAINTANCESEARCHERRORMESSAGE;
}

