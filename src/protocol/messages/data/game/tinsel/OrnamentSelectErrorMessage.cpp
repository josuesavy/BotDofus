#include "OrnamentSelectErrorMessage.h"

void OrnamentSelectErrorMessage::serialize(Writer *output)
{
  this->serializeAs_OrnamentSelectErrorMessage(output);
}

void OrnamentSelectErrorMessage::serializeAs_OrnamentSelectErrorMessage(Writer *output)
{
  output->writeByte(this->reason);
}

void OrnamentSelectErrorMessage::deserialize(Reader *input)
{
  this->deserializeAs_OrnamentSelectErrorMessage(input);
}

void OrnamentSelectErrorMessage::deserializeAs_OrnamentSelectErrorMessage(Reader *input)
{
  this->_reasonFunc(input);
}

void OrnamentSelectErrorMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_OrnamentSelectErrorMessage(tree);
}

void OrnamentSelectErrorMessage::deserializeAsyncAs_OrnamentSelectErrorMessage(FuncTree tree)
{
  tree.addChild(std::bind(&OrnamentSelectErrorMessage::_reasonFunc, this, std::placeholders::_1));
}

void OrnamentSelectErrorMessage::_reasonFunc(Reader *input)
{
  this->reason = input->readByte();
  if(this->reason < 0)
  {
    qDebug()<<"ERREUR - OrnamentSelectErrorMessage -"<<"Forbidden value (" << this->reason << ") on element of OrnamentSelectErrorMessage.reason.";
  }
}

OrnamentSelectErrorMessage::OrnamentSelectErrorMessage()
{
  m_type = MessageEnum::ORNAMENTSELECTERRORMESSAGE;
}

