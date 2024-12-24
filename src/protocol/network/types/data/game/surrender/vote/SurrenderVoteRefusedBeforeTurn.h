#ifndef SURRENDERVOTEREFUSEDBEFORETURN_H
#define SURRENDERVOTEREFUSEDBEFORETURN_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/surrender/vote/SurrenderVoteRefused.h"
#include "src/utils/io/type/FuncTree.h"

class SurrenderVoteRefusedBeforeTurn : public SurrenderVoteRefused
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SurrenderVoteRefusedBeforeTurn(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SurrenderVoteRefusedBeforeTurn(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SurrenderVoteRefusedBeforeTurn(FuncTree tree);
  SurrenderVoteRefusedBeforeTurn();
  bool operator==(const SurrenderVoteRefusedBeforeTurn &compared);

  int minTurnForSurrenderVote;

private:
  void _minTurnForSurrenderVoteFunc(Reader *input);
};

#endif // SURRENDERVOTEREFUSEDBEFORETURN_H