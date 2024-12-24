#ifndef SOCIALFIGHTJOINREQUESTMESSAGE_H
#define SOCIALFIGHTJOINREQUESTMESSAGE_H

#include "src/protocol/network/types/data/game/social/fight/SocialFightInfo.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class SocialFightJoinRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SocialFightJoinRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SocialFightJoinRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SocialFightJoinRequestMessage(FuncTree tree);
  SocialFightJoinRequestMessage();

  SocialFightInfo socialFightInfo;

private:
  void _socialFightInfotreeFunc(Reader *input);

  FuncTree _socialFightInfotree;
};

#endif // SOCIALFIGHTJOINREQUESTMESSAGE_H