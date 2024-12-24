#ifndef SURRENDERVOTERESPONSE_H
#define SURRENDERVOTERESPONSE_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/utils/io/type/FuncTree.h"

class SurrenderVoteResponse : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SurrenderVoteResponse(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SurrenderVoteResponse(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SurrenderVoteResponse(FuncTree tree);
  SurrenderVoteResponse();
  bool operator==(const SurrenderVoteResponse &compared);
};

#endif // SURRENDERVOTERESPONSE_H