#include "StatisticData.h"

void StatisticData::serialize(Writer *output)
{
}

void StatisticData::serializeAs_StatisticData(Writer *output)
{
}

void StatisticData::deserialize(Reader *input)
{
}

void StatisticData::deserializeAs_StatisticData(Reader *input)
{
}

void StatisticData::deserializeAsync(FuncTree tree)
{
}

void StatisticData::deserializeAsyncAs_StatisticData(FuncTree tree)
{
}

StatisticData::StatisticData()
{
  m_types<<ClassEnum::STATISTICDATA;
}

bool StatisticData::operator==(const StatisticData &compared)
{
  return true;
}

