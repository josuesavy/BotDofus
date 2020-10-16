#include "StatisticDataBoolean.h"

void StatisticDataBoolean::serialize(Writer *output)
{
  this->serializeAs_StatisticDataBoolean(output);
}

void StatisticDataBoolean::serializeAs_StatisticDataBoolean(Writer *output)
{
  StatisticData::serializeAs_StatisticData(output);
  output->writeBool(this->value);
}

void StatisticDataBoolean::deserialize(Reader *input)
{
  this->deserializeAs_StatisticDataBoolean(input);
}

void StatisticDataBoolean::deserializeAs_StatisticDataBoolean(Reader *input)
{
  StatisticData::deserialize(input);
  this->_valueFunc(input);
}

void StatisticDataBoolean::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_StatisticDataBoolean(tree);
}

void StatisticDataBoolean::deserializeAsyncAs_StatisticDataBoolean(FuncTree tree)
{
  StatisticData::deserializeAsync(tree);
  tree.addChild(std::bind(&StatisticDataBoolean::_valueFunc, this, std::placeholders::_1));
}

void StatisticDataBoolean::_valueFunc(Reader *input)
{
  this->value = input->readBool();
}

StatisticDataBoolean::StatisticDataBoolean()
{
  m_types<<ClassEnum::STATISTICDATABOOLEAN;
}

bool StatisticDataBoolean::operator==(const StatisticDataBoolean &compared)
{
  if(value == compared.value)
  return true;
  
  return false;
}

