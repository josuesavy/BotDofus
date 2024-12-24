#ifndef SURRENDERSTATEMESSAGE_H
#define SURRENDERSTATEMESSAGE_H

#include "src/utils/io/type/BooleanByteWrapper.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class SurrenderStateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SurrenderStateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SurrenderStateMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SurrenderStateMessage(FuncTree tree);
  SurrenderStateMessage();

  bool canSurrender;
  bool permitVote;

private:
  void deserializeByteBoxes(Reader *input);
};

#endif // SURRENDERSTATEMESSAGE_H