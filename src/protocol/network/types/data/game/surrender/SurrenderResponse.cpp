#include "SurrenderResponse.h"

void SurrenderResponse::serialize(Writer *output)
{
}

void SurrenderResponse::serializeAs_SurrenderResponse(Writer *output)
{
}

void SurrenderResponse::deserialize(Reader *input)
{
}

void SurrenderResponse::deserializeAs_SurrenderResponse(Reader *input)
{
}

void SurrenderResponse::deserializeAsync(FuncTree tree)
{
}

void SurrenderResponse::deserializeAsyncAs_SurrenderResponse(FuncTree tree)
{
}

SurrenderResponse::SurrenderResponse()
{
  m_types<<ClassEnum::SURRENDERRESPONSE;
}

bool SurrenderResponse::operator==(const SurrenderResponse &compared)
{
  return true;
}

