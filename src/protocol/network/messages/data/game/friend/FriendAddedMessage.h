#ifndef FRIENDADDEDMESSAGE_H
#define FRIENDADDEDMESSAGE_H

#include "src/protocol/network/types/ClassManager.h"
#include "src/protocol/network/types/data/game/friend/FriendInformations.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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