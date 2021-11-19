#include "PartyMemberArenaInformations.h"

void PartyMemberArenaInformations::serialize(Writer *output)
{
  this->serializeAs_PartyMemberArenaInformations(output);
}

void PartyMemberArenaInformations::serializeAs_PartyMemberArenaInformations(Writer *output)
{
  PartyMemberInformations::serializeAs_PartyMemberInformations(output);
  if(this->rank < 0 || this->rank > 20000)
  {
    qDebug()<<"ERREUR - PartyMemberArenaInformations -"<<"Forbidden value (" << this->rank << ") on element rank.";
  }
  output->writeVarShort((int)this->rank);
}

void PartyMemberArenaInformations::deserialize(Reader *input)
{
  this->deserializeAs_PartyMemberArenaInformations(input);
}

void PartyMemberArenaInformations::deserializeAs_PartyMemberArenaInformations(Reader *input)
{
  PartyMemberInformations::deserialize(input);
  this->_rankFunc(input);
}

void PartyMemberArenaInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PartyMemberArenaInformations(tree);
}

void PartyMemberArenaInformations::deserializeAsyncAs_PartyMemberArenaInformations(FuncTree tree)
{
  PartyMemberInformations::deserializeAsync(tree);
  tree.addChild(std::bind(&PartyMemberArenaInformations::_rankFunc, this, std::placeholders::_1));
}

void PartyMemberArenaInformations::_rankFunc(Reader *input)
{
  this->rank = input->readVarUhShort();
  if(this->rank < 0 || this->rank > 20000)
  {
    qDebug()<<"ERREUR - PartyMemberArenaInformations -"<<"Forbidden value (" << this->rank << ") on element of PartyMemberArenaInformations.rank.";
  }
}

PartyMemberArenaInformations::PartyMemberArenaInformations()
{
  m_types<<ClassEnum::PARTYMEMBERARENAINFORMATIONS;
}

bool PartyMemberArenaInformations::operator==(const PartyMemberArenaInformations &compared)
{
  if(rank == compared.rank)
  return true;
  
  return false;
}

