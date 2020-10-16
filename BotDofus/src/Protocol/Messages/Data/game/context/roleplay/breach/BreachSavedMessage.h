#ifndef BREACHSAVEDMESSAGE_H
#define BREACHSAVEDMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class BreachSavedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_BreachSavedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_BreachSavedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_BreachSavedMessage(FuncTree tree);
  BreachSavedMessage();

  bool saved;

private:
  void _savedFunc(Reader *input);
};

#endif // BREACHSAVEDMESSAGE_H