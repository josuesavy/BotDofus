#include "OrnamentSelectedMessage.h"

void OrnamentSelectedMessage::serialize(Writer *output)
{
  this->serializeAs_OrnamentSelectedMessage(output);
}

void OrnamentSelectedMessage::serializeAs_OrnamentSelectedMessage(Writer *output)
{
  if(this->ornamentId < 0)
  {
    qDebug()<<"ERREUR - OrnamentSelectedMessage -"<<"Forbidden value (" << this->ornamentId << ") on element ornamentId.";
  }
  output->writeVarShort((int)this->ornamentId);
}

void OrnamentSelectedMessage::deserialize(Reader *input)
{
  this->deserializeAs_OrnamentSelectedMessage(input);
}

void OrnamentSelectedMessage::deserializeAs_OrnamentSelectedMessage(Reader *input)
{
  this->_ornamentIdFunc(input);
}

void OrnamentSelectedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_OrnamentSelectedMessage(tree);
}

void OrnamentSelectedMessage::deserializeAsyncAs_OrnamentSelectedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&OrnamentSelectedMessage::_ornamentIdFunc, this, std::placeholders::_1));
}

void OrnamentSelectedMessage::_ornamentIdFunc(Reader *input)
{
  this->ornamentId = input->readVarUhShort();
  if(this->ornamentId < 0)
  {
    qDebug()<<"ERREUR - OrnamentSelectedMessage -"<<"Forbidden value (" << this->ornamentId << ") on element of OrnamentSelectedMessage.ornamentId.";
  }
}

OrnamentSelectedMessage::OrnamentSelectedMessage()
{
  m_type = MessageEnum::ORNAMENTSELECTEDMESSAGE;
}

