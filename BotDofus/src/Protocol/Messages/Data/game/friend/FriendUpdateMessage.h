#ifndef FRIENDUPDATEMESSAGE_H
#define FRIENDUPDATEMESSAGE_H

#include "src/Protocol/Types/Data/game/friend/FriendInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Types/ClassManager.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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