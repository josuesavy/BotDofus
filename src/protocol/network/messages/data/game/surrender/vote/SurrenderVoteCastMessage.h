#ifndef SURRENDERVOTECASTMESSAGE_H
#define SURRENDERVOTECASTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class SurrenderVoteCastMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SurrenderVoteCastMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SurrenderVoteCastMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SurrenderVoteCastMessage(FuncTree tree);
  SurrenderVoteCastMessage();

  bool vote;

private:
  void _voteFunc(Reader *input);
};

#endif // SURRENDERVOTECASTMESSAGE_H