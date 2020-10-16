#ifndef FRIENDSGETLISTMESSAGE_H
#define FRIENDSGETLISTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class FriendsGetListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_FriendsGetListMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_FriendsGetListMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_FriendsGetListMessage(FuncTree tree);
  FriendsGetListMessage();
};

#endif // FRIENDSGETLISTMESSAGE_H