#include "GameRolePlayMerchantInformations.h"

void GameRolePlayMerchantInformations::serialize(Writer *output)
{
  this->serializeAs_GameRolePlayMerchantInformations(output);
}

void GameRolePlayMerchantInformations::serializeAs_GameRolePlayMerchantInformations(Writer *output)
{
  GameRolePlayNamedActorInformations::serializeAs_GameRolePlayNamedActorInformations(output);
  if(this->sellType < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayMerchantInformations -"<<"Forbidden value (" << this->sellType << ") on element sellType.";
  }
  output->writeByte(this->sellType);
  output->writeShort((short)this->options.size());
  for(uint _i2 = 0; _i2 < this->options.size(); _i2++)
  {
    output->writeShort((short)qSharedPointerCast<HumanOption>(this->options[_i2])->getTypes().last());
    qSharedPointerCast<HumanOption>(this->options[_i2])->serialize(output);
  }
}

void GameRolePlayMerchantInformations::deserialize(Reader *input)
{
  this->deserializeAs_GameRolePlayMerchantInformations(input);
}

void GameRolePlayMerchantInformations::deserializeAs_GameRolePlayMerchantInformations(Reader *input)
{
  uint _id2 = 0;
  QSharedPointer<HumanOption> _item2 ;
  GameRolePlayNamedActorInformations::deserialize(input);
  this->_sellTypeFunc(input);
  uint _optionsLen = input->readUShort();
  for(uint _i2 = 0; _i2 < _optionsLen; _i2++)
  {
    _id2 = input->readUShort();
    _item2 = qSharedPointerCast<HumanOption>(ClassManagerSingleton::get()->getClass(_id2));
    _item2->deserialize(input);
    this->options.append(_item2);
  }
}

void GameRolePlayMerchantInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameRolePlayMerchantInformations(tree);
}

void GameRolePlayMerchantInformations::deserializeAsyncAs_GameRolePlayMerchantInformations(FuncTree tree)
{
  GameRolePlayNamedActorInformations::deserializeAsync(tree);
  tree.addChild(std::bind(&GameRolePlayMerchantInformations::_sellTypeFunc, this, std::placeholders::_1));
  this->_optionstree = tree.addChild(std::bind(&GameRolePlayMerchantInformations::_optionstreeFunc, this, std::placeholders::_1));
}

void GameRolePlayMerchantInformations::_sellTypeFunc(Reader *input)
{
  this->sellType = input->readByte();
  if(this->sellType < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayMerchantInformations -"<<"Forbidden value (" << this->sellType << ") on element of GameRolePlayMerchantInformations.sellType.";
  }
}

void GameRolePlayMerchantInformations::_optionstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_optionstree.addChild(std::bind(&GameRolePlayMerchantInformations::_optionsFunc, this, std::placeholders::_1));
  }
}

void GameRolePlayMerchantInformations::_optionsFunc(Reader *input)
{
  uint _id = input->readUShort();
  QSharedPointer<HumanOption> _item = qSharedPointerCast<HumanOption>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->options.append(_item);
}

GameRolePlayMerchantInformations::GameRolePlayMerchantInformations()
{
  m_types<<ClassEnum::GAMEROLEPLAYMERCHANTINFORMATIONS;
}

bool GameRolePlayMerchantInformations::operator==(const GameRolePlayMerchantInformations &compared)
{
  if(sellType == compared.sellType)
  if(options == compared.options)
  if(_optionstree == compared._optionstree)
  return true;
  
  return false;
}

