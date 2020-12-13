#ifndef IGNOREDDELETERESULTMESSAGE_H
#define IGNOREDDELETERESULTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/engines/io/network/utils/BooleanByteWrapper.h"
#include "src/protocol/messages/AbstractMessage.h"

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
  QString name;
  bool session;

private:
  void deserializeByteBoxes(Reader *input);
  void _nameFunc(Reader *input);
};

#endif // IGNOREDDELETERESULTMESSAGE_H