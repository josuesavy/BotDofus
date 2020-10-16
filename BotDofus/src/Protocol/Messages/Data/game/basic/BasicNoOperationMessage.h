#ifndef BASICNOOPERATIONMESSAGE_H
#define BASICNOOPERATIONMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class BasicNoOperationMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_BasicNoOperationMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_BasicNoOperationMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_BasicNoOperationMessage(FuncTree tree);
  BasicNoOperationMessage();
};

#endif // BASICNOOPERATIONMESSAGE_H