#ifndef SELECTEDSERVERDATAEXTENDEDMESSAGE_H
#define SELECTEDSERVERDATAEXTENDEDMESSAGE_H

#include "src/protocol/network/types/data/connection/GameServerInformations.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/connection/SelectedServerDataMessage.h"

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