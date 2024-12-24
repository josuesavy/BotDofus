#ifndef SURRENDERVOTEUPDATEMESSAGE_H
#define SURRENDERVOTEUPDATEMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class SurrenderVoteUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SurrenderVoteUpdateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SurrenderVoteUpdateMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SurrenderVoteUpdateMessage(FuncTree tree);
  SurrenderVoteUpdateMessage();
};

#endif // SURRENDERVOTEUPDATEMESSAGE_H