#include "PrismFightersInformation.h"

void PrismFightersInformation::serialize(Writer *output)
{
  this->serializeAs_PrismFightersInformation(output);
}

void PrismFightersInformation::serializeAs_PrismFightersInformation(Writer *output)
{
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - PrismFightersInformation -"<<"Forbidden value (" << this->subAreaId << ") on element subAreaId.";
  }
  output->writeVarShort((int)this->subAreaId);
  this->waitingForHelpInfo.serializeAs_ProtectedEntityWaitingForHelpInfo(output);
  output->writeShort((short)this->allyCharactersInformations.size());
  for(uint _i3 = 0; _i3 < this->allyCharactersInformations.size(); _i3++)
  {
    output->writeShort((short)qSharedPointerCast<CharacterMinimalPlusLookInformations>(this->allyCharactersInformations[_i3])->getTypes().last());
    qSharedPointerCast<CharacterMinimalPlusLookInformations>(this->allyCharactersInformations[_i3])->serialize(output);
  }
  output->writeShort((short)this->enemyCharactersInformations.size());
  for(uint _i4 = 0; _i4 < this->enemyCharactersInformations.size(); _i4++)
  {
    output->writeShort((short)qSharedPointerCast<CharacterMinimalPlusLookInformations>(this->enemyCharactersInformations[_i4])->getTypes().last());
    qSharedPointerCast<CharacterMinimalPlusLookInformations>(this->enemyCharactersInformations[_i4])->serialize(output);
  }
}

void PrismFightersInformation::deserialize(Reader *input)
{
  this->deserializeAs_PrismFightersInformation(input);
}

void PrismFightersInformation::deserializeAs_PrismFightersInformation(Reader *input)
{
  uint _id3 = 0;
  QSharedPointer<CharacterMinimalPlusLookInformations> _item3 ;
  uint _id4 = 0;
  QSharedPointer<CharacterMinimalPlusLookInformations> _item4 ;
  this->_subAreaIdFunc(input);
  this->waitingForHelpInfo = ProtectedEntityWaitingForHelpInfo();
  this->waitingForHelpInfo.deserialize(input);
  uint _allyCharactersInformationsLen = input->readUShort();
  for(uint _i3 = 0; _i3 < _allyCharactersInformationsLen; _i3++)
  {
    _id3 = input->readUShort();
    _item3 = qSharedPointerCast<CharacterMinimalPlusLookInformations>(ClassManagerSingleton::get()->getClass(_id3));
    _item3->deserialize(input);
    this->allyCharactersInformations.append(_item3);
  }
  uint _enemyCharactersInformationsLen = input->readUShort();
  for(uint _i4 = 0; _i4 < _enemyCharactersInformationsLen; _i4++)
  {
    _id4 = input->readUShort();
    _item4 = qSharedPointerCast<CharacterMinimalPlusLookInformations>(ClassManagerSingleton::get()->getClass(_id4));
    _item4->deserialize(input);
    this->enemyCharactersInformations.append(_item4);
  }
}

void PrismFightersInformation::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PrismFightersInformation(tree);
}

void PrismFightersInformation::deserializeAsyncAs_PrismFightersInformation(FuncTree tree)
{
  tree.addChild(std::bind(&PrismFightersInformation::_subAreaIdFunc, this, std::placeholders::_1));
  this->_waitingForHelpInfotree = tree.addChild(std::bind(&PrismFightersInformation::_waitingForHelpInfotreeFunc, this, std::placeholders::_1));
  this->_allyCharactersInformationstree = tree.addChild(std::bind(&PrismFightersInformation::_allyCharactersInformationstreeFunc, this, std::placeholders::_1));
  this->_enemyCharactersInformationstree = tree.addChild(std::bind(&PrismFightersInformation::_enemyCharactersInformationstreeFunc, this, std::placeholders::_1));
}

void PrismFightersInformation::_subAreaIdFunc(Reader *input)
{
  this->subAreaId = input->readVarUhShort();
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - PrismFightersInformation -"<<"Forbidden value (" << this->subAreaId << ") on element of PrismFightersInformation.subAreaId.";
  }
}

void PrismFightersInformation::_waitingForHelpInfotreeFunc(Reader *input)
{
  this->waitingForHelpInfo = ProtectedEntityWaitingForHelpInfo();
  this->waitingForHelpInfo.deserializeAsync(this->_waitingForHelpInfotree);
}

void PrismFightersInformation::_allyCharactersInformationstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_allyCharactersInformationstree.addChild(std::bind(&PrismFightersInformation::_allyCharactersInformationsFunc, this, std::placeholders::_1));
  }
}

void PrismFightersInformation::_allyCharactersInformationsFunc(Reader *input)
{
  uint _id = input->readUShort();
  QSharedPointer<CharacterMinimalPlusLookInformations> _item = qSharedPointerCast<CharacterMinimalPlusLookInformations>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->allyCharactersInformations.append(_item);
}

void PrismFightersInformation::_enemyCharactersInformationstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_enemyCharactersInformationstree.addChild(std::bind(&PrismFightersInformation::_enemyCharactersInformationsFunc, this, std::placeholders::_1));
  }
}

void PrismFightersInformation::_enemyCharactersInformationsFunc(Reader *input)
{
  uint _id = input->readUShort();
  QSharedPointer<CharacterMinimalPlusLookInformations> _item = qSharedPointerCast<CharacterMinimalPlusLookInformations>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->enemyCharactersInformations.append(_item);
}

PrismFightersInformation::PrismFightersInformation()
{
  m_types<<ClassEnum::PRISMFIGHTERSINFORMATION;
}

bool PrismFightersInformation::operator==(const PrismFightersInformation &compared)
{
  if(subAreaId == compared.subAreaId)
  if(waitingForHelpInfo == compared.waitingForHelpInfo)
  if(allyCharactersInformations == compared.allyCharactersInformations)
  if(enemyCharactersInformations == compared.enemyCharactersInformations)
  if(_waitingForHelpInfotree == compared._waitingForHelpInfotree)
  if(_allyCharactersInformationstree == compared._allyCharactersInformationstree)
  if(_enemyCharactersInformationstree == compared._enemyCharactersInformationstree)
  return true;
  
  return false;
}

