#ifndef SOCIALFIGHTLEAVEREQUESTMESSAGE_H
#define SOCIALFIGHTLEAVEREQUESTMESSAGE_H

#include "src/protocol/network/types/data/game/social/fight/SocialFightInfo.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class SocialFightLeaveRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SocialFightLeaveRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SocialFightLeaveRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SocialFightLeaveRequestMessage(FuncTree tree);
  SocialFightLeaveRequestMessage();

  SocialFightInfo socialFightInfo;

private:
  void _socialFightInfotreeFunc(Reader *input);

  FuncTree _socialFightInfotree;
};

#endif // SOCIALFIGHTLEAVEREQUESTMESSAGE_H