#ifndef IGNOREDADDFAILUREMESSAGE_H
#define IGNOREDADDFAILUREMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

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