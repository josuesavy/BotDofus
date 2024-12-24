#ifndef FORCEACCOUNTMESSAGE_H
#define FORCEACCOUNTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ForceAccountMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ForceAccountMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ForceAccountMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ForceAccountMessage(FuncTree tree);
  ForceAccountMessage();

  uint accountId;

private:
  void _accountIdFunc(Reader *input);
};

#endif // FORCEACCOUNTMESSAGE_H