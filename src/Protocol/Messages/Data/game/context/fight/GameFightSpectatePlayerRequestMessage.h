#ifndef GAMEFIGHTSPECTATEPLAYERREQUESTMESSAGE_H
#define GAMEFIGHTSPECTATEPLAYERREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class GameFightSpectatePlayerRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameFightSpectatePlayerRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameFightSpectatePlayerRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameFightSpectatePlayerRequestMessage(FuncTree tree);
  GameFightSpectatePlayerRequestMessage();

  double playerId;

private:
  void _playerIdFunc(Reader *input);
};

#endif // GAMEFIGHTSPECTATEPLAYERREQUESTMESSAGE_H