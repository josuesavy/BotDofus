#include "HumanOption.h"

void HumanOption::serialize(Writer *output)
{
}

void HumanOption::serializeAs_HumanOption(Writer *output)
{
}

void HumanOption::deserialize(Reader *input)
{
}

void HumanOption::deserializeAs_HumanOption(Reader *input)
{
}

void HumanOption::deserializeAsync(FuncTree tree)
{
}

void HumanOption::deserializeAsyncAs_HumanOption(FuncTree tree)
{
}

HumanOption::HumanOption()
{
  m_types<<ClassEnum::HUMANOPTION;
}

bool HumanOption::operator==(const HumanOption &compared)
{
  return true;
}

