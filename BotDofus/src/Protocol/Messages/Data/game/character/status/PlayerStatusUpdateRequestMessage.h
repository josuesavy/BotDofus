#ifndef PLAYERSTATUSUPDATEREQUESTMESSAGE_H
#define PLAYERSTATUSUPDATEREQUESTMESSAGE_H

#include "src/Protocol/Types/Data/game/character/status/PlayerStatus.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Types/ClassManager.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class PlayerStatusUpdateRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PlayerStatusUpdateRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PlayerStatusUpdateRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PlayerStatusUpdateRequestMessage(FuncTree tree);
  PlayerStatusUpdateRequestMessage();

  QSharedPointer<PlayerStatus> status;

private:
  void _statustreeFunc(Reader *input);

  FuncTree _statustree;
};

#endif // PLAYERSTATUSUPDATEREQUESTMESSAGE_H