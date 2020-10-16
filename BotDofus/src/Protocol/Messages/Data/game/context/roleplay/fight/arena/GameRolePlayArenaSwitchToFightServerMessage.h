#ifndef GAMEROLEPLAYARENASWITCHTOFIGHTSERVERMESSAGE_H
#define GAMEROLEPLAYARENASWITCHTOFIGHTSERVERMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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
  QList<int> ticket;

private:
  void _addressFunc(Reader *input);
  void _portstreeFunc(Reader *input);
  void _portsFunc(Reader *input);
  void _tickettreeFunc(Reader *input);
  void _ticketFunc(Reader *input);

  FuncTree _portstree;
  FuncTree _tickettree;
};

#endif // GAMEROLEPLAYARENASWITCHTOFIGHTSERVERMESSAGE_H