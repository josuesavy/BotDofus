#include "AbstractPlayerSearchInformation.h"

void AbstractPlayerSearchInformation::serialize(Writer *output)
{
}

void AbstractPlayerSearchInformation::serializeAs_AbstractPlayerSearchInformation(Writer *output)
{
}

void AbstractPlayerSearchInformation::deserialize(Reader *input)
{
}

void AbstractPlayerSearchInformation::deserializeAs_AbstractPlayerSearchInformation(Reader *input)
{
}

void AbstractPlayerSearchInformation::deserializeAsync(FuncTree tree)
{
}

void AbstractPlayerSearchInformation::deserializeAsyncAs_AbstractPlayerSearchInformation(FuncTree tree)
{
}

AbstractPlayerSearchInformation::AbstractPlayerSearchInformation()
{
  m_types<<ClassEnum::ABSTRACTPLAYERSEARCHINFORMATION;
}

bool AbstractPlayerSearchInformation::operator==(const AbstractPlayerSearchInformation &compared)
{
  return true;
}

