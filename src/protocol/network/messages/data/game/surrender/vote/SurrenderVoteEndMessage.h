#ifndef SURRENDERVOTEENDMESSAGE_H
#define SURRENDERVOTEENDMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class SurrenderVoteEndMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SurrenderVoteEndMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SurrenderVoteEndMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SurrenderVoteEndMessage(FuncTree tree);
  SurrenderVoteEndMessage();

  bool voteResult;

private:
  void _voteResultFunc(Reader *input);
};

#endif // SURRENDERVOTEENDMESSAGE_H