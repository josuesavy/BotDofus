#include "StatisticDataString.h"

void StatisticDataString::serialize(Writer *output)
{
  this->serializeAs_StatisticDataString(output);
}

void StatisticDataString::serializeAs_StatisticDataString(Writer *output)
{
  StatisticData::serializeAs_StatisticData(output);
  output->writeUTF(this->value);
}

void StatisticDataString::deserialize(Reader *input)
{
  this->deserializeAs_StatisticDataString(input);
}

void StatisticDataString::deserializeAs_StatisticDataString(Reader *input)
{
  StatisticData::deserialize(input);
  this->_valueFunc(input);
}

void StatisticDataString::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_StatisticDataString(tree);
}

void StatisticDataString::deserializeAsyncAs_StatisticDataString(FuncTree tree)
{
  StatisticData::deserializeAsync(tree);
  tree.addChild(std::bind(&StatisticDataString::_valueFunc, this, std::placeholders::_1));
}

void StatisticDataString::_valueFunc(Reader *input)
{
  this->value = input->readUTF();
}

StatisticDataString::StatisticDataString()
{
  m_types<<ClassEnum::STATISTICDATASTRING;
}

bool StatisticDataString::operator==(const StatisticDataString &compared)
{
  if(value == compared.value)
  return true;
  
  return false;
}

