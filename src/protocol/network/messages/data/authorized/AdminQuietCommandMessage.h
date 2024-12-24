#ifndef ADMINQUIETCOMMANDMESSAGE_H
#define ADMINQUIETCOMMANDMESSAGE_H

#include "src/protocol/network/types/data/game/Uuid.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/authorized/AdminCommandMessage.h"

class AdminQuietCommandMessage : public AdminCommandMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AdminQuietCommandMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AdminQuietCommandMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AdminQuietCommandMessage(FuncTree tree);
  AdminQuietCommandMessage();
};

#endif // ADMINQUIETCOMMANDMESSAGE_H