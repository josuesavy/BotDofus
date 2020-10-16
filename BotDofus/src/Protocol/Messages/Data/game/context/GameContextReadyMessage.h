#ifndef GAMECONTEXTREADYMESSAGE_H
#define GAMECONTEXTREADYMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class GameContextReadyMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameContextReadyMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameContextReadyMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameContextReadyMessage(FuncTree tree);
  GameContextReadyMessage();

  double mapId;

private:
  void _mapIdFunc(Reader *input);
};

#endif // GAMECONTEXTREADYMESSAGE_H