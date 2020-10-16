#ifndef FRIENDADDEDMESSAGE_H
#define FRIENDADDEDMESSAGE_H

#include "src/Protocol/Types/Data/game/friend/FriendInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Types/ClassManager.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class FriendAddedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_FriendAddedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_FriendAddedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_FriendAddedMessage(FuncTree tree);
  FriendAddedMessage();

  QSharedPointer<FriendInformations> friendAdded;

private:
  void _friendAddedtreeFunc(Reader *input);

  FuncTree _friendAddedtree;
};

#endif // FRIENDADDEDMESSAGE_H