#ifndef GUESTLIMITATIONMESSAGE_H
#define GUESTLIMITATIONMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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