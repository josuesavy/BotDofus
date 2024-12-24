#ifndef SURRENDERVOTEACCEPTED_H
#define SURRENDERVOTEACCEPTED_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/surrender/vote/SurrenderVoteResponse.h"
#include "src/utils/io/type/FuncTree.h"

class SurrenderVoteAccepted : public SurrenderVoteResponse
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SurrenderVoteAccepted(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SurrenderVoteAccepted(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SurrenderVoteAccepted(FuncTree tree);
  SurrenderVoteAccepted();
  bool operator==(const SurrenderVoteAccepted &compared);
};

#endif // SURRENDERVOTEACCEPTED_H