#ifndef OBJECTJOBADDEDMESSAGE_H
#define OBJECTJOBADDEDMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class ObjectJobAddedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ObjectJobAddedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ObjectJobAddedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ObjectJobAddedMessage(FuncTree tree);
  ObjectJobAddedMessage();

  uint jobId;

private:
  void _jobIdFunc(Reader *input);
};

#endif // OBJECTJOBADDEDMESSAGE_H