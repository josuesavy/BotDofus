#include "CinematicMessage.h"

void CinematicMessage::serialize(Writer *output)
{
  this->serializeAs_CinematicMessage(output);
}

void CinematicMessage::serializeAs_CinematicMessage(Writer *output)
{
  if(this->cinematicId < 0)
  {
    qDebug()<<"ERREUR - CinematicMessage -"<<"Forbidden value (" << this->cinematicId << ") on element cinematicId.";
  }
  output->writeVarShort((int)this->cinematicId);
}

void CinematicMessage::deserialize(Reader *input)
{
  this->deserializeAs_CinematicMessage(input);
}

void CinematicMessage::deserializeAs_CinematicMessage(Reader *input)
{
  this->_cinematicIdFunc(input);
}

void CinematicMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_CinematicMessage(tree);
}

void CinematicMessage::deserializeAsyncAs_CinematicMessage(FuncTree tree)
{
  tree.addChild(std::bind(&CinematicMessage::_cinematicIdFunc, this, std::placeholders::_1));
}

void CinematicMessage::_cinematicIdFunc(Reader *input)
{
  this->cinematicId = input->readVarUhShort();
  if(this->cinematicId < 0)
  {
    qDebug()<<"ERREUR - CinematicMessage -"<<"Forbidden value (" << this->cinematicId << ") on element of CinematicMessage.cinematicId.";
  }
}

CinematicMessage::CinematicMessage()
{
  m_type = MessageEnum::CINEMATICMESSAGE;
}

