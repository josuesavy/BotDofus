#ifndef CHALLENGEFIGHTJOINREFUSEDMESSAGE_H
#define CHALLENGEFIGHTJOINREFUSEDMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ChallengeFightJoinRefusedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ChallengeFightJoinRefusedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ChallengeFightJoinRefusedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ChallengeFightJoinRefusedMessage(FuncTree tree);
  ChallengeFightJoinRefusedMessage();

  double playerId;
  int reason;

private:
  void _playerIdFunc(Reader *input);
  void _reasonFunc(Reader *input);
};

#endif // CHALLENGEFIGHTJOINREFUSEDMESSAGE_H