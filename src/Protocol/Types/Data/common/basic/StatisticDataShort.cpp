#include "StatisticDataShort.h"

void StatisticDataShort::serialize(Writer *output)
{
  this->serializeAs_StatisticDataShort(output);
}

void StatisticDataShort::serializeAs_StatisticDataShort(Writer *output)
{
  StatisticData::serializeAs_StatisticData(output);
  output->writeShort((short)this->value);
}

void StatisticDataShort::deserialize(Reader *input)
{
  this->deserializeAs_StatisticDataShort(input);
}

void StatisticDataShort::deserializeAs_StatisticDataShort(Reader *input)
{
  StatisticData::deserialize(input);
  this->_valueFunc(input);
}

void StatisticDataShort::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_StatisticDataShort(tree);
}

void StatisticDataShort::deserializeAsyncAs_StatisticDataShort(FuncTree tree)
{
  StatisticData::deserializeAsync(tree);
  tree.addChild(std::bind(&StatisticDataShort::_valueFunc, this, std::placeholders::_1));
}

void StatisticDataShort::_valueFunc(Reader *input)
{
  this->value = input->readShort();
}

StatisticDataShort::StatisticDataShort()
{
  m_types<<ClassEnum::STATISTICDATASHORT;
}

bool StatisticDataShort::operator==(const StatisticDataShort &compared)
{
  if(value == compared.value)
  return true;
  
  return false;
}

