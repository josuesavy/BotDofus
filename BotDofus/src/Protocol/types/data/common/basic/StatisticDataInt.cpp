#include "StatisticDataInt.h"

void StatisticDataInt::serialize(Writer *output)
{
  this->serializeAs_StatisticDataInt(output);
}

void StatisticDataInt::serializeAs_StatisticDataInt(Writer *output)
{
  StatisticData::serializeAs_StatisticData(output);
  output->writeInt((int)this->value);
}

void StatisticDataInt::deserialize(Reader *input)
{
  this->deserializeAs_StatisticDataInt(input);
}

void StatisticDataInt::deserializeAs_StatisticDataInt(Reader *input)
{
  StatisticData::deserialize(input);
  this->_valueFunc(input);
}

void StatisticDataInt::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_StatisticDataInt(tree);
}

void StatisticDataInt::deserializeAsyncAs_StatisticDataInt(FuncTree tree)
{
  StatisticData::deserializeAsync(tree);
  tree.addChild(std::bind(&StatisticDataInt::_valueFunc, this, std::placeholders::_1));
}

void StatisticDataInt::_valueFunc(Reader *input)
{
  this->value = input->readInt();
}

StatisticDataInt::StatisticDataInt()
{
  m_types<<ClassEnum::STATISTICDATAINT;
}

bool StatisticDataInt::operator==(const StatisticDataInt &compared)
{
  if(value == compared.value)
  return true;
  
  return false;
}

