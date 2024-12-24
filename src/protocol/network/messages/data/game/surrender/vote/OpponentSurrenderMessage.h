#ifndef OPPONENTSURRENDERMESSAGE_H
#define OPPONENTSURRENDERMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class OpponentSurrenderMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_OpponentSurrenderMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_OpponentSurrenderMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_OpponentSurrenderMessage(FuncTree tree);
  OpponentSurrenderMessage();
};

#endif // OPPONENTSURRENDERMESSAGE_H