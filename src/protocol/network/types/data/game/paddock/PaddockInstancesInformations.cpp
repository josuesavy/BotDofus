#include "PaddockInstancesInformations.h"

void PaddockInstancesInformations::serialize(Writer *output)
{
  this->serializeAs_PaddockInstancesInformations(output);
}

void PaddockInstancesInformations::serializeAs_PaddockInstancesInformations(Writer *output)
{
  PaddockInformations::serializeAs_PaddockInformations(output);
  output->writeShort((short)this->paddocks.size());
  for(uint _i1 = 0; _i1 < this->paddocks.size(); _i1++)
  {
    output->writeShort((short)(this->paddocks[_i1]ascom.ankamagames.dofus.network.types.game.paddock.PaddockBuyableInformations).getTypeId());
    (this->paddocks[_i1] as com.ankamagames.dofus.network.types.game.paddock.PaddockBuyableInformations).serialize(output);
  }
}

void PaddockInstancesInformations::deserialize(Reader *input)
{
  this->deserializeAs_PaddockInstancesInformations(input);
}

void PaddockInstancesInformations::deserializeAs_PaddockInstancesInformations(Reader *input)
{
  uint _id1 = 0;
  com.ankamagames.dofus.network.types.game.paddock.PaddockBuyableInformations _item1 ;
  PaddockInformations::deserialize(input);
  uint _paddocksLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _paddocksLen; _i1++)
  {
    _id1 = uint(input->readUShort());
    _item1 = qSharedPointerCast<>(ClassManagerSingleton::get()->getClass(_id1));
    _item1.deserialize(input);
    this->paddocks.append(_item1);
  }
}

void PaddockInstancesInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PaddockInstancesInformations(tree);
}

void PaddockInstancesInformations::deserializeAsyncAs_PaddockInstancesInformations(FuncTree tree)
{
  PaddockInformations::deserializeAsync(tree);
  this->_paddockstree = tree.addChild(std::bind(&PaddockInstancesInformations::_paddockstreeFunc, this, std::placeholders::_1));
}

void PaddockInstancesInformations::_paddockstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_paddockstree.addChild(std::bind(&PaddockInstancesInformations::_paddocksFunc, this, std::placeholders::_1));
  }
}

void PaddockInstancesInformations::_paddocksFunc(Reader *input)
{
  uint _id = uint(input->readUShort());
   _item = qSharedPointerCast<>(ClassManagerSingleton::get()->getClass(_id));
  _item.deserialize(input);
  this->paddocks.append(_item);
}

PaddockInstancesInformations::PaddockInstancesInformations()
{
  m_types<<ClassEnum::PADDOCKINSTANCESINFORMATIONS;
}

bool PaddockInstancesInformations::operator==(const PaddockInstancesInformations &compared)
{
  if(paddocks == compared.paddocks)
  if(_paddockstree == compared._paddockstree)
  return true;
  
  return false;
}

