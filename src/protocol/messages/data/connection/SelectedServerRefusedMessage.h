#ifndef SELECTEDSERVERREFUSEDMESSAGE_H
#define SELECTEDSERVERREFUSEDMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class SelectedServerRefusedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SelectedServerRefusedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SelectedServerRefusedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SelectedServerRefusedMessage(FuncTree tree);
  SelectedServerRefusedMessage();

  uint serverId;
  uint error;
  uint serverStatus;

private:
  void _serverIdFunc(Reader *input);
  void _errorFunc(Reader *input);
  void _serverStatusFunc(Reader *input);
};

#endif // SELECTEDSERVERREFUSEDMESSAGE_H