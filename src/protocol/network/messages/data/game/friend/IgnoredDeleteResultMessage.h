#ifndef IGNOREDDELETERESULTMESSAGE_H
#define IGNOREDDELETERESULTMESSAGE_H

#include "src/protocol/network/types/data/common/AccountTagInformation.h"
#include "src/utils/io/type/BooleanByteWrapper.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class IgnoredDeleteResultMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_IgnoredDeleteResultMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_IgnoredDeleteResultMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_IgnoredDeleteResultMessage(FuncTree tree);
  IgnoredDeleteResultMessage();

  bool success;
  AccountTagInformation tag;
  bool session;

private:
  void deserializeByteBoxes(Reader *input);
  void _tagtreeFunc(Reader *input);

  FuncTree _tagtree;
};

#endif // IGNOREDDELETERESULTMESSAGE_H