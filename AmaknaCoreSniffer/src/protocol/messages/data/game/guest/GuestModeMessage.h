#ifndef GUESTMODEMESSAGE_H
#define GUESTMODEMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class GuestModeMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuestModeMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuestModeMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuestModeMessage(FuncTree tree);
  GuestModeMessage();

  bool active;

private:
  void _activeFunc(Reader *input);
};

#endif // GUESTMODEMESSAGE_H