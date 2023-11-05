#ifndef ALLIANCEAPPLICATIONRECEIVEDMESSAGE_H
#define ALLIANCEAPPLICATIONRECEIVEDMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class AllianceApplicationReceivedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceApplicationReceivedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceApplicationReceivedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceApplicationReceivedMessage(FuncTree tree);
  AllianceApplicationReceivedMessage();

  QString playerName;
  double playerId;

private:
  void _playerNameFunc(Reader *input);
  void _playerIdFunc(Reader *input);
};

#endif // ALLIANCEAPPLICATIONRECEIVEDMESSAGE_H