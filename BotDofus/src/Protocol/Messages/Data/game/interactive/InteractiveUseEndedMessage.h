#ifndef INTERACTIVEUSEENDEDMESSAGE_H
#define INTERACTIVEUSEENDEDMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class InteractiveUseEndedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_InteractiveUseEndedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_InteractiveUseEndedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_InteractiveUseEndedMessage(FuncTree tree);
  InteractiveUseEndedMessage();

  uint elemId;
  uint skillId;

private:
  void _elemIdFunc(Reader *input);
  void _skillIdFunc(Reader *input);
};

#endif // INTERACTIVEUSEENDEDMESSAGE_H