#ifndef GAMEFIGHTNEWROUNDMESSAGE_H
#define GAMEFIGHTNEWROUNDMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class GameFightNewRoundMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameFightNewRoundMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameFightNewRoundMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameFightNewRoundMessage(FuncTree tree);
  GameFightNewRoundMessage();

  uint roundNumber;

private:
  void _roundNumberFunc(Reader *input);
};

#endif // GAMEFIGHTNEWROUNDMESSAGE_H