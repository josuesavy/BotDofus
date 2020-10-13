#ifndef SYSTEMMESSAGEDISPLAYMESSAGE_H
#define SYSTEMMESSAGEDISPLAYMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class SystemMessageDisplayMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SystemMessageDisplayMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SystemMessageDisplayMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SystemMessageDisplayMessage(FuncTree tree);
  SystemMessageDisplayMessage();

  bool hangUp;
  uint msgId;
  QList<QString> parameters;

private:
  void _hangUpFunc(Reader *input);
  void _msgIdFunc(Reader *input);
  void _parameterstreeFunc(Reader *input);
  void _parametersFunc(Reader *input);

  FuncTree _parameterstree;
};

#endif // SYSTEMMESSAGEDISPLAYMESSAGE_H