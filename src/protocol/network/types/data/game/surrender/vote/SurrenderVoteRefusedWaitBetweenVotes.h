#ifndef SURRENDERVOTEREFUSEDWAITBETWEENVOTES_H
#define SURRENDERVOTEREFUSEDWAITBETWEENVOTES_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/surrender/vote/SurrenderVoteRefused.h"
#include "src/utils/io/type/FuncTree.h"

class SurrenderVoteRefusedWaitBetweenVotes : public SurrenderVoteRefused
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SurrenderVoteRefusedWaitBetweenVotes(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SurrenderVoteRefusedWaitBetweenVotes(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SurrenderVoteRefusedWaitBetweenVotes(FuncTree tree);
  SurrenderVoteRefusedWaitBetweenVotes();
  bool operator==(const SurrenderVoteRefusedWaitBetweenVotes &compared);

  int nextVoteTimestamp;

private:
  void _nextVoteTimestampFunc(Reader *input);
};

#endif // SURRENDERVOTEREFUSEDWAITBETWEENVOTES_H