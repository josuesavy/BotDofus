#ifndef INTERACTIVEUSEREQUESTMESSAGE_H
#define INTERACTIVEUSEREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class InteractiveUseRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_InteractiveUseRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_InteractiveUseRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_InteractiveUseRequestMessage(FuncTree tree);
  InteractiveUseRequestMessage();

  uint elemId;
  uint skillInstanceUid;

private:
  void _elemIdFunc(Reader *input);
  void _skillInstanceUidFunc(Reader *input);
};

#endif // INTERACTIVEUSEREQUESTMESSAGE_H