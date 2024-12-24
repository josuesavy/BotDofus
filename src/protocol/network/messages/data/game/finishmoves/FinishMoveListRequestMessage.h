#ifndef FINISHMOVELISTREQUESTMESSAGE_H
#define FINISHMOVELISTREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class FinishMoveListRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_FinishMoveListRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_FinishMoveListRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_FinishMoveListRequestMessage(FuncTree tree);
  FinishMoveListRequestMessage();
};

#endif // FINISHMOVELISTREQUESTMESSAGE_H