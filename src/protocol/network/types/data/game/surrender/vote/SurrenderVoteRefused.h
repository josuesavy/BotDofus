#ifndef SURRENDERVOTEREFUSED_H
#define SURRENDERVOTEREFUSED_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/surrender/vote/SurrenderVoteResponse.h"
#include "src/utils/io/type/FuncTree.h"

class SurrenderVoteRefused : public SurrenderVoteResponse
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SurrenderVoteRefused(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SurrenderVoteRefused(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SurrenderVoteRefused(FuncTree tree);
  SurrenderVoteRefused();
  bool operator==(const SurrenderVoteRefused &compared);
};

#endif // SURRENDERVOTEREFUSED_H