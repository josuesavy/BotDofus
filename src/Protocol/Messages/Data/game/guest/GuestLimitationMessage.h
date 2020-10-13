#ifndef GUESTLIMITATIONMESSAGE_H
#define GUESTLIMITATIONMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class GuestLimitationMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuestLimitationMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuestLimitationMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuestLimitationMessage(FuncTree tree);
  GuestLimitationMessage();

  uint reason;

private:
  void _reasonFunc(Reader *input);
};

#endif // GUESTLIMITATIONMESSAGE_H