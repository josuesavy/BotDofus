#ifndef SELECTEDSERVERDATAMESSAGE_H
#define SELECTEDSERVERDATAMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class SelectedServerDataMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SelectedServerDataMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SelectedServerDataMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SelectedServerDataMessage(FuncTree tree);
  SelectedServerDataMessage();

  uint serverId;
  QString address;
  QList<uint> ports;
  bool canCreateNewCharacter;
  QList<int> ticket;

private:
  void _serverIdFunc(Reader *input);
  void _addressFunc(Reader *input);
  void _portstreeFunc(Reader *input);
  void _portsFunc(Reader *input);
  void _canCreateNewCharacterFunc(Reader *input);
  void _tickettreeFunc(Reader *input);
  void _ticketFunc(Reader *input);

  FuncTree _portstree;
  FuncTree _tickettree;
};

#endif // SELECTEDSERVERDATAMESSAGE_H