#ifndef SURRENDERVOTEREFUSEDALREADYASKED_H
#define SURRENDERVOTEREFUSEDALREADYASKED_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/surrender/vote/SurrenderVoteRefused.h"
#include "src/utils/io/type/FuncTree.h"

class SurrenderVoteRefusedAlreadyAsked : public SurrenderVoteRefused
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SurrenderVoteRefusedAlreadyAsked(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SurrenderVoteRefusedAlreadyAsked(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SurrenderVoteRefusedAlreadyAsked(FuncTree tree);
  SurrenderVoteRefusedAlreadyAsked();
  bool operator==(const SurrenderVoteRefusedAlreadyAsked &compared);
};

#endif // SURRENDERVOTEREFUSEDALREADYASKED_H