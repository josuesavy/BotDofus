#ifndef QUEUESTATUSMESSAGE_H
#define QUEUESTATUSMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class QueueStatusMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_QueueStatusMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_QueueStatusMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_QueueStatusMessage(FuncTree tree);
  QueueStatusMessage();

  uint position;
  uint total;

private:
  void _positionFunc(Reader *input);
  void _totalFunc(Reader *input);
};

#endif // QUEUESTATUSMESSAGE_H