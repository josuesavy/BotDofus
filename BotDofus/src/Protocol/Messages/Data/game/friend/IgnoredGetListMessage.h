#ifndef IGNOREDGETLISTMESSAGE_H
#define IGNOREDGETLISTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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