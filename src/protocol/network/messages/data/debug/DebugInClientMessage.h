#ifndef DEBUGINCLIENTMESSAGE_H
#define DEBUGINCLIENTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class DebugInClientMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_DebugInClientMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_DebugInClientMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_DebugInClientMessage(FuncTree tree);
  DebugInClientMessage();

  uint level;
  QString message;

private:
  void _levelFunc(Reader *input);
  void _messageFunc(Reader *input);
};

#endif // DEBUGINCLIENTMESSAGE_H