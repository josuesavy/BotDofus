#ifndef IGNOREDGETLISTMESSAGE_H
#define IGNOREDGETLISTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class IgnoredGetListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_IgnoredGetListMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_IgnoredGetListMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_IgnoredGetListMessage(FuncTree tree);
  IgnoredGetListMessage();
};

#endif // IGNOREDGETLISTMESSAGE_H