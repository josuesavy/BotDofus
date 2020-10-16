#include "PartyIdol.h"

void PartyIdol::serialize(Writer *output)
{
  this->serializeAs_PartyIdol(output);
}

void PartyIdol::serializeAs_PartyIdol(Writer *output)
{
  Idol::serializeAs_Idol(output);
  output->writeShort((short)this->ownersIds.size());
  for(uint _i1 = 0; _i1 < this->ownersIds.size(); _i1++)
  {
    if(this->ownersIds[_i1] < 0 || this->ownersIds[_i1] > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - PartyIdol -"<<"Forbidden value (" << this->ownersIds[_i1] << ") on element 1 (starting at 1) of ownersIds.";
    }
    output->writeVarLong((double)this->ownersIds[_i1]);
  }
}

void PartyIdol::deserialize(Reader *input)
{
  this->deserializeAs_PartyIdol(input);
}

void PartyIdol::deserializeAs_PartyIdol(Reader *input)
{
  auto _val1 = NULL;
  Idol::deserialize(input);
  uint _ownersIdsLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _ownersIdsLen; _i1++)
  {
    _val1 = input->readVarUhLong();
    if(_val1 < 0 || _val1 > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - PartyIdol -"<<"Forbidden value (" << _val1 << ") on elements of ownersIds.";
    }
    this->ownersIds.append(_val1);
  }
}

void PartyIdol::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PartyIdol(tree);
}

void PartyIdol::deserializeAsyncAs_PartyIdol(FuncTree tree)
{
  Idol::deserializeAsync(tree);
  this->_ownersIdstree = tree.addChild(std::bind(&PartyIdol::_ownersIdstreeFunc, this, std::placeholders::_1));
}

void PartyIdol::_ownersIdstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_ownersIdstree.addChild(std::bind(&PartyIdol::_ownersIdsFunc, this, std::placeholders::_1));
  }
}

void PartyIdol::_ownersIdsFunc(Reader *input)
{
  double _val = input->readVarUhLong();
  if(_val < 0 || _val > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PartyIdol -"<<"Forbidden value (" << _val << ") on elements of ownersIds.";
  }
  this->ownersIds.append(_val);
}

PartyIdol::PartyIdol()
{
  m_types<<ClassEnum::PARTYIDOL;
}

bool PartyIdol::operator==(const PartyIdol &compared)
{
  if(ownersIds == compared.ownersIds)
  if(_ownersIdstree == compared._ownersIdstree)
  return true;
  
  return false;
}

