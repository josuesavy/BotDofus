#ifndef GAMEFIGHTJOINMESSAGE_H
#define GAMEFIGHTJOINMESSAGE_H

#include "src/utils/io/type/BooleanByteWrapper.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GameFightJoinMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameFightJoinMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameFightJoinMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameFightJoinMessage(FuncTree tree);
  GameFightJoinMessage();

  bool isTeamPhase;
  bool canBeCancelled;
  bool canSayReady;
  bool isFightStarted;
  uint timeMaxBeforeFightStart;
  uint fightType;

private:
  void deserializeByteBoxes(Reader *input);
  void _timeMaxBeforeFightStartFunc(Reader *input);
  void _fightTypeFunc(Reader *input);
};

#endif // GAMEFIGHTJOINMESSAGE_H