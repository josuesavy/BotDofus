#include "OrnamentLostMessage.h"

void OrnamentLostMessage::serialize(Writer *output)
{
  this->serializeAs_OrnamentLostMessage(output);
}

void OrnamentLostMessage::serializeAs_OrnamentLostMessage(Writer *output)
{
  if(this->ornamentId < 0)
  {
    qDebug()<<"ERREUR - OrnamentLostMessage -"<<"Forbidden value (" << this->ornamentId << ") on element ornamentId.";
  }
  output->writeShort((short)this->ornamentId);
}

void OrnamentLostMessage::deserialize(Reader *input)
{
  this->deserializeAs_OrnamentLostMessage(input);
}

void OrnamentLostMessage::deserializeAs_OrnamentLostMessage(Reader *input)
{
  this->_ornamentIdFunc(input);
}

void OrnamentLostMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_OrnamentLostMessage(tree);
}

void OrnamentLostMessage::deserializeAsyncAs_OrnamentLostMessage(FuncTree tree)
{
  tree.addChild(std::bind(&OrnamentLostMessage::_ornamentIdFunc, this, std::placeholders::_1));
}

void OrnamentLostMessage::_ornamentIdFunc(Reader *input)
{
  this->ornamentId = input->readShort();
  if(this->ornamentId < 0)
  {
    qDebug()<<"ERREUR - OrnamentLostMessage -"<<"Forbidden value (" << this->ornamentId << ") on element of OrnamentLostMessage.ornamentId.";
  }
}

OrnamentLostMessage::OrnamentLostMessage()
{
  m_type = MessageEnum::ORNAMENTLOSTMESSAGE;
}

