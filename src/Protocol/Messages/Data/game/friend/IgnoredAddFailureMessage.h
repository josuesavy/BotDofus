#ifndef IGNOREDADDFAILUREMESSAGE_H
#define IGNOREDADDFAILUREMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class IgnoredAddFailureMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_IgnoredAddFailureMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_IgnoredAddFailureMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_IgnoredAddFailureMessage(FuncTree tree);
  IgnoredAddFailureMessage();

  uint reason;

private:
  void _reasonFunc(Reader *input);
};

#endif // IGNOREDADDFAILUREMESSAGE_H