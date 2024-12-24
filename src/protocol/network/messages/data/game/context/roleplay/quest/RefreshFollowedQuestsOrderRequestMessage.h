#ifndef REFRESHFOLLOWEDQUESTSORDERREQUESTMESSAGE_H
#define REFRESHFOLLOWEDQUESTSORDERREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class RefreshFollowedQuestsOrderRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_RefreshFollowedQuestsOrderRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_RefreshFollowedQuestsOrderRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_RefreshFollowedQuestsOrderRequestMessage(FuncTree tree);
  RefreshFollowedQuestsOrderRequestMessage();

  QList<uint> quests;

private:
  void _queststreeFunc(Reader *input);
  void _questsFunc(Reader *input);

  FuncTree _queststree;
};

#endif // REFRESHFOLLOWEDQUESTSORDERREQUESTMESSAGE_H