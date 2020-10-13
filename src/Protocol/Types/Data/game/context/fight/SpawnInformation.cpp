#include "SpawnInformation.h"

void SpawnInformation::serialize(Writer *output)
{
}

void SpawnInformation::serializeAs_SpawnInformation(Writer *output)
{
}

void SpawnInformation::deserialize(Reader *input)
{
}

void SpawnInformation::deserializeAs_SpawnInformation(Reader *input)
{
}

void SpawnInformation::deserializeAsync(FuncTree tree)
{
}

void SpawnInformation::deserializeAsyncAs_SpawnInformation(FuncTree tree)
{
}

SpawnInformation::SpawnInformation()
{
  m_types<<ClassEnum::SPAWNINFORMATION;
}

bool SpawnInformation::operator==(const SpawnInformation &compared)
{
  return true;
}

