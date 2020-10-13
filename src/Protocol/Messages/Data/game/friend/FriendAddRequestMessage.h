#ifndef FRIENDADDREQUESTMESSAGE_H
#define FRIENDADDREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class FriendAddRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_FriendAddRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_FriendAddRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_FriendAddRequestMessage(FuncTree tree);
  FriendAddRequestMessage();

  QString name;

private:
  void _nameFunc(Reader *input);
};

#endif // FRIENDADDREQUESTMESSAGE_H