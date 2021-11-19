#ifndef FRIENDSLISTMESSAGE_H
#define FRIENDSLISTMESSAGE_H

#include "src/protocol/types/data/game/friend/FriendInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/types/ClassManager.h"
#include "src/protocol/messages/AbstractMessage.h"

class FriendsListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_FriendsListMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_FriendsListMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_FriendsListMessage(FuncTree tree);
  FriendsListMessage();

  QList<QSharedPointer<FriendInformations>> friendsList;

private:
  void _friendsListtreeFunc(Reader *input);
  void _friendsListFunc(Reader *input);

  FuncTree _friendsListtree;
};

#endif // FRIENDSLISTMESSAGE_H