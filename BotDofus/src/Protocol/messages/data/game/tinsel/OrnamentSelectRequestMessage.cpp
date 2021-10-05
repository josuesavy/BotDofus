#include "OrnamentSelectRequestMessage.h"

void OrnamentSelectRequestMessage::serialize(Writer *output)
{
  this->serializeAs_OrnamentSelectRequestMessage(output);
}

void OrnamentSelectRequestMessage::serializeAs_OrnamentSelectRequestMessage(Writer *output)
{
  if(this->ornamentId < 0)
  {
    qDebug()<<"ERREUR - OrnamentSelectRequestMessage -"<<"Forbidden value (" << this->ornamentId << ") on element ornamentId.";
  }
  output->writeVarShort((int)this->ornamentId);
}

void OrnamentSelectRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_OrnamentSelectRequestMessage(input);
}

void OrnamentSelectRequestMessage::deserializeAs_OrnamentSelectRequestMessage(Reader *input)
{
  this->_ornamentIdFunc(input);
}

void OrnamentSelectRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_OrnamentSelectRequestMessage(tree);
}

void OrnamentSelectRequestMessage::deserializeAsyncAs_OrnamentSelectRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&OrnamentSelectRequestMessage::_ornamentIdFunc, this, std::placeholders::_1));
}

void OrnamentSelectRequestMessage::_ornamentIdFunc(Reader *input)
{
  this->ornamentId = input->readVarUhShort();
  if(this->ornamentId < 0)
  {
    qDebug()<<"ERREUR - OrnamentSelectRequestMessage -"<<"Forbidden value (" << this->ornamentId << ") on element of OrnamentSelectRequestMessage.ornamentId.";
  }
}

OrnamentSelectRequestMessage::OrnamentSelectRequestMessage()
{
  m_type = MessageEnum::ORNAMENTSELECTREQUESTMESSAGE;
}

