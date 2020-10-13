#ifndef FRIENDSETWARNONCONNECTIONMESSAGE_H
#define FRIENDSETWARNONCONNECTIONMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class FriendSetWarnOnConnectionMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_FriendSetWarnOnConnectionMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_FriendSetWarnOnConnectionMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_FriendSetWarnOnConnectionMessage(FuncTree tree);
  FriendSetWarnOnConnectionMessage();

  bool enable;

private:
  void _enableFunc(Reader *input);
};

#endif // FRIENDSETWARNONCONNECTIONMESSAGE_H