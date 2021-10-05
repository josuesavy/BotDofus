#include "IdolPartyLostMessage.h"

void IdolPartyLostMessage::serialize(Writer *output)
{
  this->serializeAs_IdolPartyLostMessage(output);
}

void IdolPartyLostMessage::serializeAs_IdolPartyLostMessage(Writer *output)
{
  if(this->idolId < 0)
  {
    qDebug()<<"ERREUR - IdolPartyLostMessage -"<<"Forbidden value (" << this->idolId << ") on element idolId.";
  }
  output->writeVarShort((int)this->idolId);
}

void IdolPartyLostMessage::deserialize(Reader *input)
{
  this->deserializeAs_IdolPartyLostMessage(input);
}

void IdolPartyLostMessage::deserializeAs_IdolPartyLostMessage(Reader *input)
{
  this->_idolIdFunc(input);
}

void IdolPartyLostMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_IdolPartyLostMessage(tree);
}

void IdolPartyLostMessage::deserializeAsyncAs_IdolPartyLostMessage(FuncTree tree)
{
  tree.addChild(std::bind(&IdolPartyLostMessage::_idolIdFunc, this, std::placeholders::_1));
}

void IdolPartyLostMessage::_idolIdFunc(Reader *input)
{
  this->idolId = input->readVarUhShort();
  if(this->idolId < 0)
  {
    qDebug()<<"ERREUR - IdolPartyLostMessage -"<<"Forbidden value (" << this->idolId << ") on element of IdolPartyLostMessage.idolId.";
  }
}

IdolPartyLostMessage::IdolPartyLostMessage()
{
  m_type = MessageEnum::IDOLPARTYLOSTMESSAGE;
}

