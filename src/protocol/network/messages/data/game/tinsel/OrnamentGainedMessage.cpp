#include "OrnamentGainedMessage.h"

void OrnamentGainedMessage::serialize(Writer *output)
{
  this->serializeAs_OrnamentGainedMessage(output);
}

void OrnamentGainedMessage::serializeAs_OrnamentGainedMessage(Writer *output)
{
  if(this->ornamentId < 0)
  {
    qDebug()<<"ERREUR - OrnamentGainedMessage -"<<"Forbidden value (" << this->ornamentId << ") on element ornamentId.";
  }
  output->writeShort((short)this->ornamentId);
}

void OrnamentGainedMessage::deserialize(Reader *input)
{
  this->deserializeAs_OrnamentGainedMessage(input);
}

void OrnamentGainedMessage::deserializeAs_OrnamentGainedMessage(Reader *input)
{
  this->_ornamentIdFunc(input);
}

void OrnamentGainedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_OrnamentGainedMessage(tree);
}

void OrnamentGainedMessage::deserializeAsyncAs_OrnamentGainedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&OrnamentGainedMessage::_ornamentIdFunc, this, std::placeholders::_1));
}

void OrnamentGainedMessage::_ornamentIdFunc(Reader *input)
{
  this->ornamentId = input->readShort();
  if(this->ornamentId < 0)
  {
    qDebug()<<"ERREUR - OrnamentGainedMessage -"<<"Forbidden value (" << this->ornamentId << ") on element of OrnamentGainedMessage.ornamentId.";
  }
}

OrnamentGainedMessage::OrnamentGainedMessage()
{
  m_type = MessageEnum::ORNAMENTGAINEDMESSAGE;
}

