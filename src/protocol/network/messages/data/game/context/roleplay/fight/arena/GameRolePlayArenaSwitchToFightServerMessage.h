#ifndef GAMEROLEPLAYARENASWITCHTOFIGHTSERVERMESSAGE_H
#define GAMEROLEPLAYARENASWITCHTOFIGHTSERVERMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class GameRolePlayArenaSwitchToFightServerMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameRolePlayArenaSwitchToFightServerMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameRolePlayArenaSwitchToFightServerMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameRolePlayArenaSwitchToFightServerMessage(FuncTree tree);
  GameRolePlayArenaSwitchToFightServerMessage();

  QString address;
  QList<uint> ports;
  QString token;

private:
  void _addressFunc(Reader *input);
  void _portstreeFunc(Reader *input);
  void _portsFunc(Reader *input);
  void _tokenFunc(Reader *input);

  FuncTree _portstree;
};

#endif // GAMEROLEPLAYARENASWITCHTOFIGHTSERVERMESSAGE_H