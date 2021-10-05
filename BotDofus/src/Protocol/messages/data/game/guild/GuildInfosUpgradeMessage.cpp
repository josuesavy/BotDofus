#include "GuildInfosUpgradeMessage.h"

void GuildInfosUpgradeMessage::serialize(Writer *output)
{
  this->serializeAs_GuildInfosUpgradeMessage(output);
}

void GuildInfosUpgradeMessage::serializeAs_GuildInfosUpgradeMessage(Writer *output)
{
  if(this->maxTaxCollectorsCount < 0)
  {
    qDebug()<<"ERREUR - GuildInfosUpgradeMessage -"<<"Forbidden value (" << this->maxTaxCollectorsCount << ") on element maxTaxCollectorsCount.";
  }
  output->writeByte(this->maxTaxCollectorsCount);
  if(this->taxCollectorsCount < 0)
  {
    qDebug()<<"ERREUR - GuildInfosUpgradeMessage -"<<"Forbidden value (" << this->taxCollectorsCount << ") on element taxCollectorsCount.";
  }
  output->writeByte(this->taxCollectorsCount);
  if(this->taxCollectorLifePoints < 0)
  {
    qDebug()<<"ERREUR - GuildInfosUpgradeMessage -"<<"Forbidden value (" << this->taxCollectorLifePoints << ") on element taxCollectorLifePoints.";
  }
  output->writeVarShort((int)this->taxCollectorLifePoints);
  if(this->taxCollectorDamagesBonuses < 0)
  {
    qDebug()<<"ERREUR - GuildInfosUpgradeMessage -"<<"Forbidden value (" << this->taxCollectorDamagesBonuses << ") on element taxCollectorDamagesBonuses.";
  }
  output->writeVarShort((int)this->taxCollectorDamagesBonuses);
  if(this->taxCollectorPods < 0)
  {
    qDebug()<<"ERREUR - GuildInfosUpgradeMessage -"<<"Forbidden value (" << this->taxCollectorPods << ") on element taxCollectorPods.";
  }
  output->writeVarShort((int)this->taxCollectorPods);
  if(this->taxCollectorProspecting < 0)
  {
    qDebug()<<"ERREUR - GuildInfosUpgradeMessage -"<<"Forbidden value (" << this->taxCollectorProspecting << ") on element taxCollectorProspecting.";
  }
  output->writeVarShort((int)this->taxCollectorProspecting);
  if(this->taxCollectorWisdom < 0)
  {
    qDebug()<<"ERREUR - GuildInfosUpgradeMessage -"<<"Forbidden value (" << this->taxCollectorWisdom << ") on element taxCollectorWisdom.";
  }
  output->writeVarShort((int)this->taxCollectorWisdom);
  if(this->boostPoints < 0)
  {
    qDebug()<<"ERREUR - GuildInfosUpgradeMessage -"<<"Forbidden value (" << this->boostPoints << ") on element boostPoints.";
  }
  output->writeVarShort((int)this->boostPoints);
  output->writeShort((short)this->spellId.size());
  for(uint _i9 = 0; _i9 < this->spellId.size(); _i9++)
  {
    if(this->spellId[_i9] < 0)
    {
      qDebug()<<"ERREUR - GuildInfosUpgradeMessage -"<<"Forbidden value (" << this->spellId[_i9] << ") on element 9 (starting at 1) of spellId.";
    }
    output->writeVarShort((int)this->spellId[_i9]);
  }
  output->writeShort((short)this->spellLevel.size());
  for(uint _i10 = 0; _i10 < this->spellLevel.size(); _i10++)
  {
    output->writeShort((short)this->spellLevel[_i10]);
  }
}

void GuildInfosUpgradeMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildInfosUpgradeMessage(input);
}

void GuildInfosUpgradeMessage::deserializeAs_GuildInfosUpgradeMessage(Reader *input)
{
  uint _val9 = 0;
  auto _val10 = 0;
  this->_maxTaxCollectorsCountFunc(input);
  this->_taxCollectorsCountFunc(input);
  this->_taxCollectorLifePointsFunc(input);
  this->_taxCollectorDamagesBonusesFunc(input);
  this->_taxCollectorPodsFunc(input);
  this->_taxCollectorProspectingFunc(input);
  this->_taxCollectorWisdomFunc(input);
  this->_boostPointsFunc(input);
  uint _spellIdLen = input->readUShort();
  for(uint _i9 = 0; _i9 < _spellIdLen; _i9++)
  {
    _val9 = input->readVarUhShort();
    if(_val9 < 0)
    {
      qDebug()<<"ERREUR - GuildInfosUpgradeMessage -"<<"Forbidden value (" << _val9 << ") on elements of spellId.";
    }
    this->spellId.append(_val9);
  }
  uint _spellLevelLen = input->readUShort();
  for(uint _i10 = 0; _i10 < _spellLevelLen; _i10++)
  {
    _val10 = input->readShort();
    this->spellLevel.append(_val10);
  }
}

void GuildInfosUpgradeMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildInfosUpgradeMessage(tree);
}

void GuildInfosUpgradeMessage::deserializeAsyncAs_GuildInfosUpgradeMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GuildInfosUpgradeMessage::_maxTaxCollectorsCountFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildInfosUpgradeMessage::_taxCollectorsCountFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildInfosUpgradeMessage::_taxCollectorLifePointsFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildInfosUpgradeMessage::_taxCollectorDamagesBonusesFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildInfosUpgradeMessage::_taxCollectorPodsFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildInfosUpgradeMessage::_taxCollectorProspectingFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildInfosUpgradeMessage::_taxCollectorWisdomFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildInfosUpgradeMessage::_boostPointsFunc, this, std::placeholders::_1));
  this->_spellIdtree = tree.addChild(std::bind(&GuildInfosUpgradeMessage::_spellIdtreeFunc, this, std::placeholders::_1));
  this->_spellLeveltree = tree.addChild(std::bind(&GuildInfosUpgradeMessage::_spellLeveltreeFunc, this, std::placeholders::_1));
}

void GuildInfosUpgradeMessage::_maxTaxCollectorsCountFunc(Reader *input)
{
  this->maxTaxCollectorsCount = input->readByte();
  if(this->maxTaxCollectorsCount < 0)
  {
    qDebug()<<"ERREUR - GuildInfosUpgradeMessage -"<<"Forbidden value (" << this->maxTaxCollectorsCount << ") on element of GuildInfosUpgradeMessage.maxTaxCollectorsCount.";
  }
}

void GuildInfosUpgradeMessage::_taxCollectorsCountFunc(Reader *input)
{
  this->taxCollectorsCount = input->readByte();
  if(this->taxCollectorsCount < 0)
  {
    qDebug()<<"ERREUR - GuildInfosUpgradeMessage -"<<"Forbidden value (" << this->taxCollectorsCount << ") on element of GuildInfosUpgradeMessage.taxCollectorsCount.";
  }
}

void GuildInfosUpgradeMessage::_taxCollectorLifePointsFunc(Reader *input)
{
  this->taxCollectorLifePoints = input->readVarUhShort();
  if(this->taxCollectorLifePoints < 0)
  {
    qDebug()<<"ERREUR - GuildInfosUpgradeMessage -"<<"Forbidden value (" << this->taxCollectorLifePoints << ") on element of GuildInfosUpgradeMessage.taxCollectorLifePoints.";
  }
}

void GuildInfosUpgradeMessage::_taxCollectorDamagesBonusesFunc(Reader *input)
{
  this->taxCollectorDamagesBonuses = input->readVarUhShort();
  if(this->taxCollectorDamagesBonuses < 0)
  {
    qDebug()<<"ERREUR - GuildInfosUpgradeMessage -"<<"Forbidden value (" << this->taxCollectorDamagesBonuses << ") on element of GuildInfosUpgradeMessage.taxCollectorDamagesBonuses.";
  }
}

void GuildInfosUpgradeMessage::_taxCollectorPodsFunc(Reader *input)
{
  this->taxCollectorPods = input->readVarUhShort();
  if(this->taxCollectorPods < 0)
  {
    qDebug()<<"ERREUR - GuildInfosUpgradeMessage -"<<"Forbidden value (" << this->taxCollectorPods << ") on element of GuildInfosUpgradeMessage.taxCollectorPods.";
  }
}

void GuildInfosUpgradeMessage::_taxCollectorProspectingFunc(Reader *input)
{
  this->taxCollectorProspecting = input->readVarUhShort();
  if(this->taxCollectorProspecting < 0)
  {
    qDebug()<<"ERREUR - GuildInfosUpgradeMessage -"<<"Forbidden value (" << this->taxCollectorProspecting << ") on element of GuildInfosUpgradeMessage.taxCollectorProspecting.";
  }
}

void GuildInfosUpgradeMessage::_taxCollectorWisdomFunc(Reader *input)
{
  this->taxCollectorWisdom = input->readVarUhShort();
  if(this->taxCollectorWisdom < 0)
  {
    qDebug()<<"ERREUR - GuildInfosUpgradeMessage -"<<"Forbidden value (" << this->taxCollectorWisdom << ") on element of GuildInfosUpgradeMessage.taxCollectorWisdom.";
  }
}

void GuildInfosUpgradeMessage::_boostPointsFunc(Reader *input)
{
  this->boostPoints = input->readVarUhShort();
  if(this->boostPoints < 0)
  {
    qDebug()<<"ERREUR - GuildInfosUpgradeMessage -"<<"Forbidden value (" << this->boostPoints << ") on element of GuildInfosUpgradeMessage.boostPoints.";
  }
}

void GuildInfosUpgradeMessage::_spellIdtreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_spellIdtree.addChild(std::bind(&GuildInfosUpgradeMessage::_spellIdFunc, this, std::placeholders::_1));
  }
}

void GuildInfosUpgradeMessage::_spellIdFunc(Reader *input)
{
  uint _val = input->readVarUhShort();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - GuildInfosUpgradeMessage -"<<"Forbidden value (" << _val << ") on elements of spellId.";
  }
  this->spellId.append(_val);
}

void GuildInfosUpgradeMessage::_spellLeveltreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_spellLeveltree.addChild(std::bind(&GuildInfosUpgradeMessage::_spellLevelFunc, this, std::placeholders::_1));
  }
}

void GuildInfosUpgradeMessage::_spellLevelFunc(Reader *input)
{
  int _val = input->readShort();
  this->spellLevel.append(_val);
}

GuildInfosUpgradeMessage::GuildInfosUpgradeMessage()
{
  m_type = MessageEnum::GUILDINFOSUPGRADEMESSAGE;
}

