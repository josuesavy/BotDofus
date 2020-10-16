#ifndef GAMEFIGHTJOINMESSAGE_H
#define GAMEFIGHTJOINMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Engines/IO/Network/Utils/BooleanByteWrapper.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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