#include "SurrenderRefusedBeforeTurn.h"

void SurrenderRefusedBeforeTurn::serialize(Writer *output)
{
  this->serializeAs_SurrenderRefusedBeforeTurn(output);
}

void SurrenderRefusedBeforeTurn::serializeAs_SurrenderRefusedBeforeTurn(Writer *output)
{
  SurrenderRefused::serializeAs_SurrenderRefused(output);
  output->writeInt((int)this->minTurnForSurrender);
}

void SurrenderRefusedBeforeTurn::deserialize(Reader *input)
{
  this->deserializeAs_SurrenderRefusedBeforeTurn(input);
}

void SurrenderRefusedBeforeTurn::deserializeAs_SurrenderRefusedBeforeTurn(Reader *input)
{
  SurrenderRefused::deserialize(input);
  this->_minTurnForSurrenderFunc(input);
}

void SurrenderRefusedBeforeTurn::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_SurrenderRefusedBeforeTurn(tree);
}

void SurrenderRefusedBeforeTurn::deserializeAsyncAs_SurrenderRefusedBeforeTurn(FuncTree tree)
{
  SurrenderRefused::deserializeAsync(tree);
  tree.addChild(std::bind(&SurrenderRefusedBeforeTurn::_minTurnForSurrenderFunc, this, std::placeholders::_1));
}

void SurrenderRefusedBeforeTurn::_minTurnForSurrenderFunc(Reader *input)
{
  this->minTurnForSurrender = input->readInt();
}

SurrenderRefusedBeforeTurn::SurrenderRefusedBeforeTurn()
{
  m_types<<ClassEnum::SURRENDERREFUSEDBEFORETURN;
}

bool SurrenderRefusedBeforeTurn::operator==(const SurrenderRefusedBeforeTurn &compared)
{
  if(minTurnForSurrender == compared.minTurnForSurrender)
  return true;
  
  return false;
}

