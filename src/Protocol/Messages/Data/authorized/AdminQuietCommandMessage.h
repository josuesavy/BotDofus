#ifndef ADMINQUIETCOMMANDMESSAGE_H
#define ADMINQUIETCOMMANDMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/authorized/AdminCommandMessage.h"

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