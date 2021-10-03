#ifndef FRIENDUPDATEMESSAGE_H
#define FRIENDUPDATEMESSAGE_H

#include "src/protocol/types/data/game/friend/FriendInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/types/ClassManager.h"
#include "src/protocol/messages/AbstractMessage.h"

class FriendUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_FriendUpdateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_FriendUpdateMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_FriendUpdateMessage(FuncTree tree);
  FriendUpdateMessage();

  QSharedPointer<FriendInformations> friendUpdated;

private:
  void _friendUpdatedtreeFunc(Reader *input);

  FuncTree _friendUpdatedtree;
};

#endif // FRIENDUPDATEMESSAGE_H