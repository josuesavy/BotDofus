#ifndef GUILDINVITATIONSEARCHMESSAGE_H
#define GUILDINVITATIONSEARCHMESSAGE_H

#include "src/protocol/types/data/common/AbstractPlayerSearchInformation.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/types/ClassManager.h"
#include "src/protocol/messages/AbstractMessage.h"

class GuildInvitationSearchMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildInvitationSearchMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildInvitationSearchMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildInvitationSearchMessage(FuncTree tree);
  GuildInvitationSearchMessage();

  QSharedPointer<AbstractPlayerSearchInformation> target;

private:
  void _targettreeFunc(Reader *input);

  FuncTree _targettree;
};

#endif // GUILDINVITATIONSEARCHMESSAGE_H