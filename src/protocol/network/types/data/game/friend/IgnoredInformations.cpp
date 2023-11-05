#include "IgnoredInformations.h"

void IgnoredInformations::serialize(Writer *output)
{
  this->serializeAs_IgnoredInformations(output);
}

void IgnoredInformations::serializeAs_IgnoredInformations(Writer *output)
{
  AbstractContactInformations::serializeAs_AbstractContactInformations(output);
}

void IgnoredInformations::deserialize(Reader *input)
{
  this->deserializeAs_IgnoredInformations(input);
}

void IgnoredInformations::deserializeAs_IgnoredInformations(Reader *input)
{
  AbstractContactInformations::deserialize(input);
}

void IgnoredInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_IgnoredInformations(tree);
}

void IgnoredInformations::deserializeAsyncAs_IgnoredInformations(FuncTree tree)
{
  AbstractContactInformations::deserializeAsync(tree);
}

IgnoredInformations::IgnoredInformations()
{
  m_types<<ClassEnum::IGNOREDINFORMATIONS;
}

bool IgnoredInformations::operator==(const IgnoredInformations &compared)
{
  return true;
}

