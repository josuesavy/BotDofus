#ifndef CHATERRORMESSAGE_H
#define CHATERRORMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class ChatErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ChatErrorMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ChatErrorMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ChatErrorMessage(FuncTree tree);
  ChatErrorMessage();

  uint reason;

private:
  void _reasonFunc(Reader *input);
};

#endif // CHATERRORMESSAGE_H