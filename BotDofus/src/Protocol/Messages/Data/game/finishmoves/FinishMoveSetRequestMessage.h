#ifndef FINISHMOVESETREQUESTMESSAGE_H
#define FINISHMOVESETREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class FinishMoveSetRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_FinishMoveSetRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_FinishMoveSetRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_FinishMoveSetRequestMessage(FuncTree tree);
  FinishMoveSetRequestMessage();

  uint finishMoveId;
  bool finishMoveState;

private:
  void _finishMoveIdFunc(Reader *input);
  void _finishMoveStateFunc(Reader *input);
};

#endif // FINISHMOVESETREQUESTMESSAGE_H