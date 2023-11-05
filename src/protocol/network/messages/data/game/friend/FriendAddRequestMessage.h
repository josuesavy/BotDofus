#ifndef FRIENDADDREQUESTMESSAGE_H
#define FRIENDADDREQUESTMESSAGE_H

#include "src/protocol/types/ClassManager.h"
#include "src/protocol/types/data/common/AbstractPlayerSearchInformation.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

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

  QSharedPointer<AbstractPlayerSearchInformation> target;

private:
  void _targettreeFunc(Reader *input);

  FuncTree _targettree;
};

#endif // FRIENDADDREQUESTMESSAGE_H