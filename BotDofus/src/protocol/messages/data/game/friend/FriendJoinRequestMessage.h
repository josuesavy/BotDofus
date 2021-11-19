#ifndef FRIENDJOINREQUESTMESSAGE_H
#define FRIENDJOINREQUESTMESSAGE_H

#include "src/protocol/types/data/common/AbstractPlayerSearchInformation.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/types/ClassManager.h"
#include "src/protocol/messages/AbstractMessage.h"

class FriendJoinRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_FriendJoinRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_FriendJoinRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_FriendJoinRequestMessage(FuncTree tree);
  FriendJoinRequestMessage();

  QSharedPointer<AbstractPlayerSearchInformation> target;

private:
  void _targettreeFunc(Reader *input);

  FuncTree _targettree;
};

#endif // FRIENDJOINREQUESTMESSAGE_H