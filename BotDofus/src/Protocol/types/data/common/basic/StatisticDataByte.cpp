#include "StatisticDataByte.h"

void StatisticDataByte::serialize(Writer *output)
{
  this->serializeAs_StatisticDataByte(output);
}

void StatisticDataByte::serializeAs_StatisticDataByte(Writer *output)
{
  StatisticData::serializeAs_StatisticData(output);
  output->writeByte(this->value);
}

void StatisticDataByte::deserialize(Reader *input)
{
  this->deserializeAs_StatisticDataByte(input);
}

void StatisticDataByte::deserializeAs_StatisticDataByte(Reader *input)
{
  StatisticData::deserialize(input);
  this->_valueFunc(input);
}

void StatisticDataByte::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_StatisticDataByte(tree);
}

void StatisticDataByte::deserializeAsyncAs_StatisticDataByte(FuncTree tree)
{
  StatisticData::deserializeAsync(tree);
  tree.addChild(std::bind(&StatisticDataByte::_valueFunc, this, std::placeholders::_1));
}

void StatisticDataByte::_valueFunc(Reader *input)
{
  this->value = input->readByte();
}

StatisticDataByte::StatisticDataByte()
{
  m_types<<ClassEnum::STATISTICDATABYTE;
}

bool StatisticDataByte::operator==(const StatisticDataByte &compared)
{
  if(value == compared.value)
  return true;
  
  return false;
}

