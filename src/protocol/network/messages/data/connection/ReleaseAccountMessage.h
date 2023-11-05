#ifndef RELEASEACCOUNTMESSAGE_H
#define RELEASEACCOUNTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class ReleaseAccountMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ReleaseAccountMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ReleaseAccountMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ReleaseAccountMessage(FuncTree tree);
  ReleaseAccountMessage();
};

#endif // RELEASEACCOUNTMESSAGE_H