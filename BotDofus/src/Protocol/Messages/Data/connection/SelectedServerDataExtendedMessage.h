#ifndef SELECTEDSERVERDATAEXTENDEDMESSAGE_H
#define SELECTEDSERVERDATAEXTENDEDMESSAGE_H

#include "src/Protocol/Types/Data/connection/GameServerInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/connection/SelectedServerDataMessage.h"

class SelectedServerDataExtendedMessage : public SelectedServerDataMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SelectedServerDataExtendedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SelectedServerDataExtendedMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SelectedServerDataExtendedMessage(FuncTree tree);
  SelectedServerDataExtendedMessage();

  QList<GameServerInformations> servers;

private:
  void _serverstreeFunc(Reader *input);
  void _serversFunc(Reader *input);

  FuncTree _serverstree;
};

#endif // SELECTEDSERVERDATAEXTENDEDMESSAGE_H