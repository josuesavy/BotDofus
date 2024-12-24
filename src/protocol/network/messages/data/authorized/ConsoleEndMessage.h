#ifndef CONSOLEENDMESSAGE_H
#define CONSOLEENDMESSAGE_H

#include "src/protocol/network/types/data/game/Uuid.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ConsoleEndMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ConsoleEndMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ConsoleEndMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ConsoleEndMessage(FuncTree tree);
  ConsoleEndMessage();

  Uuid consoleUuid;
  bool isSuccess;

private:
  void _consoleUuidtreeFunc(Reader *input);
  void _isSuccessFunc(Reader *input);

  FuncTree _consoleUuidtree;
};

#endif // CONSOLEENDMESSAGE_H